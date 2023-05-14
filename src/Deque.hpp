//
// Created by DPhoenix on 10/06/2022.
//

#ifndef SOKULIB_DEQUE_HPP
#define SOKULIB_DEQUE_HPP


#include "Memory.hpp"

#include <deque>
#include <stdexcept>

namespace SokuLib {
	template<typename T>
	class Deque {
		static constexpr size_t _Bytes = sizeof(T);
		static constexpr size_t _BlockMax = _Bytes <= 1 ? 16 : _Bytes <= 2 ? 8 : _Bytes <= 4 ? 4 : _Bytes <= 8 ? 2 : 1;
		static constexpr size_t _MinBlocks = 8;

		using _Base = typename std::deque<T, Allocator<T> >;
		_Base base;

		// hacks to access private data
		inline T**& _GetMap() const { return ((T***)this)[1]; }
		inline size_t& _GetBlockCount() const { return ((size_t*)this)[2]; }
		inline size_t& _GetOffset() const { return ((size_t*)this)[3]; }
		inline size_t& _GetSize() const { return ((size_t*)this)[4]; }
		inline size_t _GetBlock(size_t offset) const {
			// Main fix on this class
			return (offset / _BlockMax) % _GetBlockCount();
		}

		inline static T** _Copy_Indexes(T** dest, T** src, size_t amount) { memcpy(dest, src, amount*sizeof(T*)); return dest + amount; }

		// _Growmap depend on power of 2 and must be reimplemented
		void _Growmap(size_t amount) {
			if (_GetBlockCount() + amount > base.max_size() / _BlockMax) throw std::length_error("deque<T> too long");

			size_t inc = _GetBlockCount() / 2;
			if (inc < _MinBlocks) inc = _MinBlocks;
			if (amount < inc && _GetBlockCount() + inc < base.max_size() / _BlockMax) amount = inc;

			size_t blockOff = _GetOffset() / _BlockMax;
			T** newMap = SokuLib::Allocator<T*>().allocate(_GetBlockCount() + amount);
			T** ptr = newMap + blockOff;

			ptr = _Copy_Indexes(ptr, _GetMap() + blockOff, _GetBlockCount() - blockOff);
			if (blockOff <= amount) {
				ptr = _Copy_Indexes(ptr, _GetMap(), blockOff);
				memset(ptr, 0, (amount - blockOff)*sizeof(T*));
				memset(newMap, 0, blockOff*sizeof(T*));
			} else {
				_Copy_Indexes(ptr, _GetMap(), amount);
				ptr = _Copy_Indexes(newMap, _GetMap() + amount, (blockOff - amount)*sizeof(T*));
				memset(ptr, 0, amount);
			}

			if (_GetMap()) SokuLib::Allocator<T*>().deallocate(_GetMap(), _GetBlockCount());
			_GetMap() = newMap;
			_GetBlockCount() += amount;
		}

	public:
		class iterator {
		public:
			using _BaseIterator = typename _Base::_Unchecked_iterator;
			void* __proxy;
			_BaseIterator base;

			inline iterator(const iterator& o) : base(o.base) {}
			inline iterator(const _BaseIterator& o) : base(o) {}
			inline iterator(size_t offset, const Deque* container) : base(offset, (const std::_Container_base12*)container) {}

			T& operator*() {
				// depends on _GetBlock
				const size_t _Block = ((Deque*)base._Mycont)->_GetBlock(base._Myoff);
				const size_t _Off = base._Myoff % _BlockMax;
				return ((Deque*)base._Mycont)->_GetMap()[_Block][_Off];
			}

			inline T* operator->() { return &**this; }

			inline iterator& operator++() { ++base; return *this; }
			inline iterator operator++(int) { return base++; }
			inline iterator& operator--() { --base; return *this; }
			inline iterator operator--(int) { return base--; }

			inline iterator& operator+=(const int value) { base += value; return this; }
			inline iterator operator+(const int value) const { return base + value; }
			inline iterator& operator-=(const int value) { base -= value; return this; }
			inline iterator operator-(const int value) const { return base - value; }
			inline int operator-(const iterator& o) const { return base - o.base; }
			inline bool operator==(const iterator& o) const { return base == o.base; }
			inline bool operator!=(const iterator& o) const { return base != o.base; }
		};

		inline Deque() : base() {}
		explicit inline Deque(size_t s) : base(s) {}
		explicit inline Deque(size_t s, const T& v) : base(s, v) {}
		inline Deque(const Deque& o) : base(o) {} // TODO this should work, but need to be tested
		template<class _It> inline Deque(_It b, _It e) : base(b, e) {} // TODO this should work, but need to be tested
		inline ~Deque() {
			// depends on pop_front, as long the deque is empty it will work
			while(!empty()) this->pop_front();
		}

		inline iterator begin() const { return iterator(_GetOffset(), this); }
		inline iterator end() const { return iterator(_GetOffset() + _GetSize(), this); }
		inline bool empty() const { return base.empty(); }
		inline size_t size() const { return base.size(); }

		inline T& front() const { return *begin(); }
		inline T& back() const { return *--end(); }
		T& operator[](size_t index) { return *(begin()+index); }
		T& at(size_t index) {
			if (index >= base.size()) throw std::out_of_range("invalid deque<T> subscript");
			return *(begin()+index);
		}

		// TODO more size manipulation functions

		inline void clear() {
			// depends on pop_front, as long the deque is empty it will work
			while(!empty()) this->pop_front();
			base.clear();
		}

		inline void pop_front() {
			// depends on _GetBlock
			if (empty()) return;
			const size_t _Block = _GetBlock(_GetOffset());
			_GetMap()[_Block][_GetOffset()%_BlockMax].~T(); // TODO check destructor
			if (++_GetOffset() >= _GetBlockCount()*_BlockMax) _GetOffset() = 0;
			if (--_GetSize() == 0) _GetOffset() = 0;
		}

		inline void push_back(const T& value) {
			// depends on _Growmap, so must use the custom grow
			if ((_GetOffset() + _GetSize()) % _BlockMax == 0 && _GetBlockCount() <= (_GetSize() + _BlockMax) / _BlockMax) {
				_Growmap(1);
			}

			const size_t offset = _GetOffset() + _GetSize();
			size_t block = offset / _BlockMax;
			if (_GetBlockCount() <= block) block -= _GetBlockCount();
			if (_GetMap()[block] == 0)
				_GetMap()[block] = Allocator<T>().allocate(_BlockMax);
			new (_GetMap()[block] + offset%_BlockMax) T(value); // TODO check constructor
			++_GetSize();
		}

		template<class... _Valty>
		inline void emplace_back(_Valty&&... value) {
			// depends on _Growmap, so must use the custom grow
			if ((_GetOffset() + _GetSize()) % _BlockMax == 0 && _GetBlockCount() <= (_GetSize() + _BlockMax) / _BlockMax) {
				_Growmap(1);
			}

			const size_t offset = _GetOffset() + _GetSize();
			size_t block = offset / _BlockMax;
			if (_GetBlockCount() <= block) block -= _GetBlockCount();
			if (_GetMap()[block] == 0)
				_GetMap()[block] = Allocator<T>().allocate(_BlockMax);
			new (_GetMap()[block] + offset%_BlockMax) T(std::forward<_Valty>(value)...); // TODO check constructor
			++_GetSize();
		}
	};
}

#endif // SOKULIB_DEQUE_HPP
