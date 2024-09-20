//
// Created by DPhoenix on 10/06/2022.
//

#ifndef SOKULIB_DEQUE_HPP
#define SOKULIB_DEQUE_HPP


#include "Memory.hpp"

#include <stdexcept>

namespace SokuLib {
	template<typename T>
	class Deque {
	private:
		static constexpr size_t _Bytes = sizeof(T);
		static constexpr size_t _BlockMax = _Bytes <= 1 ? 16 : _Bytes <= 2 ? 8 : _Bytes <= 4 ? 4 : _Bytes <= 8 ? 2 : 1;
		static constexpr size_t _MinBlocks = 8;

		// Data
		uint32_t debug_proxy = 0;
	public:
		T** m_table = 0;
		size_t m_blockCount = 0;
		size_t m_offset = 0;
		size_t m_size = 0;

		inline size_t max_size() const { return UINT_MAX / sizeof(T); }

	private:
		inline size_t _GetBlock(size_t offset) const { return (offset / _BlockMax) % m_blockCount; }
		inline static T** _Copy_Indexes(T** dest, T** src, size_t amount) { memcpy(dest, src, amount*sizeof(T*)); return dest + amount; }

		// _Growmap depend on power of 2 and must be reimplemented
		void _Growmap(size_t amount) {
			if (m_blockCount + amount > this->max_size() / _BlockMax) throw std::length_error("deque<T> too long");

			size_t inc = m_blockCount / 2;
			if (inc < _MinBlocks) inc = _MinBlocks;
			if (amount < inc && m_blockCount + inc < this->max_size() / _BlockMax) amount = inc;

			size_t blockOff = m_offset / _BlockMax;
			T** newMap = SokuLib::Allocator<T*>().allocate(m_blockCount + amount);
			T** ptr = newMap + blockOff;

			ptr = _Copy_Indexes(ptr, m_table + blockOff, m_blockCount - blockOff);
			if (blockOff <= amount) {
				ptr = _Copy_Indexes(ptr, m_table, blockOff);
				memset(ptr, 0, (amount - blockOff)*sizeof(T*));
				memset(newMap, 0, blockOff*sizeof(T*));
			} else {
				_Copy_Indexes(ptr, m_table, amount);
				ptr = _Copy_Indexes(newMap, m_table + amount, (blockOff - amount)*sizeof(T*));
				memset(ptr, 0, amount);
			}

			if (m_table) SokuLib::Allocator<T*>().deallocate(m_table, m_blockCount);
			m_table = newMap;
			m_blockCount += amount;
		}

	public:
		class iterator {
		public:
			using value_type = T;
			const Deque* m_container;
			size_t m_offset;

			inline iterator(const iterator& o) : m_container(o.m_container), m_offset(o.m_offset) {}
			inline iterator(size_t offset, const Deque* container) : m_container(container), m_offset(offset) {}

			value_type& operator*() {
				// depends on _GetBlock
				const size_t _Block = m_container->_GetBlock(m_offset);
				const size_t _Off = m_offset % _BlockMax;
				return m_container->m_table[_Block][_Off];
			}

			inline T* operator->() { return &**this; }

			inline iterator& operator++() { ++m_offset; return *this; }
			inline iterator operator++(int) { iterator tmp = *this; ++*this; return tmp; }
			inline iterator& operator--() { --m_offset; return *this; }
			inline iterator operator--(int) { iterator tmp = *this; --*this; return tmp; }

			inline iterator& operator+=(const int value) { m_offset += value; return *this; }
			inline iterator operator+(const int value) const { iterator tmp = *this; return tmp += value; }
			inline iterator& operator-=(const int value) { m_offset -= value; return *this; }
			inline iterator operator-(const int value) const { iterator tmp = *this; return tmp -= value; }
			inline std::ptrdiff_t operator-(const iterator& o) const { return static_cast<std::ptrdiff_t>(m_offset - o.m_offset); }
			inline bool operator==(const iterator& o) const { return m_offset == o.m_offset; }
			inline bool operator!=(const iterator& o) const { return m_offset != o.m_offset; }
			inline bool operator<(const iterator& o) const { return m_offset < o.m_offset; }
			inline bool operator>(const iterator& o) const { return o < *this; }
			inline bool operator<=(const iterator& o) const { return !(o < *this); }
			inline bool operator>=(const iterator& o) const { return !(*this < o); }
		};

		inline Deque() = default;
		explicit inline Deque(size_t s) { resize(s); }
		explicit inline Deque(size_t s, const T& v) { resize(s, v); }
		inline Deque(const Deque& other) { for (const auto& val : other) push_back(val); }
		template<class _It> inline Deque(_It b, _It e) { for (;b != e; ++b) push_back(*b); }
		inline ~Deque() { clear(); }

		Deque &operator=(const Deque &other) {
			this->clear();
			for (const auto &val : other)
				this->push_back(val);
			return *this;
		}

		inline iterator begin() const { return iterator(m_offset, this); }
		inline iterator end() const { return iterator(m_offset + m_size, this); }
		inline bool empty() const { return this->m_size == 0; }
		inline size_t size() const { return this->m_size; }

		inline T& front() const { return *begin(); }
		inline T& back() const { return *--end(); }
		T& operator[](size_t index) { return *(begin()+index); }
		T& at(size_t index) {
			if (index >= this->m_size) throw std::out_of_range("invalid deque<T> subscript");
			return *(begin()+index);
		}

		// TODO more size manipulation functions

		inline void clear() {
			while(!empty()) this->pop_front();

			size_t block = m_blockCount;
			while(block > 0) if (m_table[--block]) {
				Allocator<T>().deallocate(m_table[block], _BlockMax);
			}

			if (m_table) Allocator<T*>().deallocate(m_table, m_blockCount);
			m_table = 0;
			m_blockCount = 0;
		}

		inline void pop_front() {
			// depends on _GetBlock
			if (empty()) return;
			const size_t _Block = _GetBlock(m_offset);
			std::destroy_at<T>(&m_table[_Block][m_offset%_BlockMax]);
			if (++m_offset >= m_blockCount*_BlockMax) m_offset = 0;
			if (--m_size == 0) m_offset = 0;
		}

		inline void pop_back() {
			// depends on _GetBlock
			if (empty()) return;
			const size_t offset = m_offset + m_size - 1;
			const size_t _Block = _GetBlock(offset);
			std::destroy_at<T>(&m_table[_Block][offset%_BlockMax]);
			if (--m_size == 0) m_offset = 0;
		}

		inline void push_front(const T& value) {
			// depends on _Growmap, so must use the custom grow
			if (m_offset % _BlockMax == 0 && m_blockCount <= (m_size + _BlockMax) / _BlockMax) {
				_Growmap(1);
			}

			size_t offset = m_offset != 0 ? m_offset : m_blockCount * _BlockMax;
			size_t block = _GetBlock(--offset);
			if (m_blockCount <= block) block -= m_blockCount;
			if (m_table[block] == 0)
				m_table[block] = Allocator<T>().allocate(_BlockMax);
			std::construct_at<T>(m_table[block] + offset%_BlockMax, value);
			m_offset = offset;
			++m_size;
		}

		inline void push_back(const T& value) {
			// depends on _Growmap, so must use the custom grow
			if ((m_offset + m_size) % _BlockMax == 0 && m_blockCount <= (m_size + _BlockMax) / _BlockMax) {
				_Growmap(1);
			}

			const size_t offset = m_offset + m_size;
			size_t block = offset / _BlockMax;
			if (m_blockCount <= block) block -= m_blockCount;
			if (m_table[block] == 0)
				m_table[block] = Allocator<T>().allocate(_BlockMax);
			std::construct_at<T>(m_table[block] + offset%_BlockMax, value);
			++m_size;
		}

		template<class... _Valty>
		inline T& emplace_front(_Valty&&... value) {
			// depends on _Growmap, so must use the custom grow
			if (m_offset % _BlockMax == 0 && m_blockCount <= (m_size + _BlockMax) / _BlockMax) {
				_Growmap(1);
			}

			const size_t offset = m_offset != 0 ? m_offset : m_blockCount * _BlockMax;
			size_t block = _GetBlock(--offset);
			if (m_blockCount <= block) block -= m_blockCount;
			if (m_table[block] == 0)
				m_table[block] = Allocator<T>().allocate(_BlockMax);
			T* const ptr = m_table[block] + offset%_BlockMax;
			std::construct_at<T>(ptr, std::forward<_Valty>(value)...);
			m_offset = offset;
			++m_size;
			return *ptr;
		}

		template<class... _Valty>
		inline T& emplace_back(_Valty&&... value) {
			// depends on _Growmap, so must use the custom grow
			if ((m_offset + m_size) % _BlockMax == 0 && m_blockCount <= (m_size + _BlockMax) / _BlockMax) {
				_Growmap(1);
			}

			const size_t offset = m_offset + m_size;
			size_t block = offset / _BlockMax;
			if (m_blockCount <= block) block -= m_blockCount;
			if (m_table[block] == 0)
				m_table[block] = Allocator<T>().allocate(_BlockMax);
			T* const ptr = m_table[block] + offset%_BlockMax;
			std::construct_at<T>(ptr, std::forward<_Valty>(value)...);
			++m_size;
			return *ptr;
		}

		iterator insert(iterator where, const T& value) {
			size_t offset = where - begin();
			if (m_size < offset) throw std::runtime_error("SokuLib: Deque<T> iterator outside range");

			if (offset <= m_size / 2) {
				push_front(value);
				for (iterator i = begin(); i < begin() + offset; ++i) std::swap(*i, *(i+1));
			} else {
				push_back(value);
				for (iterator i = end() - 1; i >= begin() + offset; --i) std::swap(*i, *(i-1));
			}
			return begin() + offset;
		}

		iterator erase(iterator where, iterator finish) {
			if (finish < where || where < begin() || end() < finish)
				throw std::runtime_error("SokuLib: Deque<T> erase outside range");

			const size_t offset = where - begin();
			size_t count = finish - where;
			const size_t rem = end() - finish;

			if (count > 0) if (offset < rem) {
				std::move_backward(begin(), where, finish);
				while (count-- > 0) pop_front();
			} else {
				std::move(finish, end(), where);
				while (count-- > 0) pop_back();
			}

			return begin() + offset;
		}

		inline void resize(size_t count) {
			if (count < size()) erase(begin() + count, end());
			else while(count > size()) emplace_back();
		}

		inline void resize(size_t count, const T& value) {
			if (count < size()) erase(begin() + count, end());
			else while(count > size()) push_back(value);
		}
	};
}

#endif // SOKULIB_DEQUE_HPP
