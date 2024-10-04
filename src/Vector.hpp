//
// Created by DPhoenix on 29/05/2024.
//

#ifndef SOKULIB_VECTOR_HPP
#define SOKULIB_VECTOR_HPP

#include <windows.h>
#include "Memory.hpp"
#include <stdexcept>
#include <memory>

namespace SokuLib
{
	template<typename T> class Vector {
	public:
		using value_type = T;

		class iterator {
		public:
			using value_type = T;

			//void* __proxy;
			value_type* _ptr;

			inline iterator(const iterator& o) : _ptr(o._ptr) {}
			inline iterator(value_type* ptr, const Vector* container) : _ptr(ptr) {}
			inline value_type& operator*() { return *_ptr; }
			inline value_type* operator->() { return &**this; }

			inline iterator& operator++() { ++_ptr; return *this; }
			inline iterator operator++(int) { iterator tmp = *this; ++*this; return tmp; }
			inline iterator& operator--() { --_ptr; return *this; }
			inline iterator operator--(int) { iterator tmp = *this; --*this; return tmp; }

			inline iterator& operator+=(const int value) { _ptr += value; return *this; }
			inline iterator operator+(const int value) const { iterator tmp = *this; return (tmp += value); }
			inline iterator& operator-=(const int value) { _ptr -= value; return *this; }
			inline iterator operator-(const int value) const { iterator tmp = *this; return (tmp -= value); }
			inline std::ptrdiff_t operator-(const iterator& o) const { return this->_ptr - o._ptr; }
			inline bool operator==(const iterator& o) const { return _ptr == o._ptr; }
			inline bool operator!=(const iterator& o) const { return _ptr != o._ptr; }
			inline bool operator<(const iterator& o) const { return _ptr < o._ptr; }
			inline bool operator>(const iterator& o) const { return o < *this; }
			inline bool operator<=(const iterator& o) const { return !(o < *this); }
			inline bool operator>=(const iterator& o) const { return !(*this < o); }
		};

		// Data
	private:
		uint32_t debug_proxy = 0;
	public:
		value_type* m_first = 0;
		value_type* m_last = 0;
		value_type* m_end = 0;

		Vector() = default;
		Vector(const Vector& other) {
			if (!other.size()) return;
			this->_grow(other.size());
			for(const value_type& val : other) {
				this->push_back(val);
			}
		}

		inline ~Vector() {
			// TODO if (this->debug_proxy) throw std::runtime_error("trying to destroy Soku managed vector. Can cause memory leak");
			if (this->m_first) Allocator<value_type>().deallocate(this->m_first, this->capacity());
		}

		Vector& operator=(const Vector& other) {
			this->clear();
			if (!other.size()) return *this;
			this->_grow(other.size());
			for(const value_type& val : other) {
				this->push_back(val);
			}
			return *this;
		}

		void push_back(value_type&& val) {
			if (this->m_last == this->m_end) _grow(1);
			std::construct_at(this->m_last, std::forward<value_type>(val));
			++this->m_last;
		}

		void push_back(const value_type& val) {
			if (this->m_last == this->m_end) _grow(1);
			std::construct_at(this->m_last, val);
			++this->m_last;
		}

		template<typename ...Args>
		value_type &emplace_back(Args... args) {
			if (this->m_last == this->m_end) _grow(1);
			std::construct_at(this->m_last, args...);
			return *(this->m_last++);
		}

		void pop_back() {
			if (this->m_last > this->m_first) {
				std::destroy_at(--this->m_last);
			}
		}

		Vector(Vector&&) = delete; // TODO
		Vector& operator=(Vector&&) = delete; // TODO

		inline iterator begin() const { return iterator(this->m_first, this); }
		inline iterator end() const { return iterator(this->m_last, this); }
		inline value_type& front() const { return *begin(); }
		inline value_type& back() const { return *--end(); }
		inline size_t size() const { return this->m_last - this->m_first; }
		inline size_t capacity() const { return this->m_end - this->m_first; }
		inline size_t max_size() const { return UINT_MAX / sizeof(value_type); }
		inline bool empty() const { return this->m_first == this->m_last; }
		inline value_type& operator[](size_t index) const { return *(begin() + index); }

		inline value_type& at(size_t index) const {
			if (index >= this->size()) throw std::out_of_range("invalid vector<T> subscript");
			return *(begin() + index);
		}

		void clear() {
			if (!this->m_first) return;
			std::destroy_n(begin(), size());
			Allocator<value_type>().deallocate(this->m_first, this->capacity());
			this->m_first = this->m_last = this->m_end = 0;
		}

		void reserve(size_t N) {
			if (N <= this->m_end - this->m_first) return; // there's space, ignore
			if (N > max_size()) throw std::runtime_error("SokuLib: Vector<T> too long.");
			_reallocate(N);
		}

		void resize(size_t N) {
			if (N < size()) erase(begin() + N, end());
			else {
				reserve(N);
				for (; size() < N; ++this->m_last) {
					std::construct_at<T>(&this->m_first[size()]);
				}
			}
		}

		inline iterator erase(iterator where) {
			return this->erase(where, where + 1);
		}

		iterator erase(iterator where, iterator finish) {
			if (where == begin() && finish == end()) clear();
			else if(where != finish) {
				if (where._ptr > finish._ptr || where._ptr < this->m_first || finish._ptr >= this->m_last) {
					std::runtime_error("SokuLib: Vector<T> erase outside bounds.");
				}

				const iterator newlast = std::move(finish, end(), where);
				std::destroy_n(newlast, end() - newlast);
				this->m_last = newlast._ptr;
			}
			return where;
		}

	private:
		size_t _growRate(size_t N) const {
			size_t c = capacity() + capacity() / 2;
			if (c < N || c > max_size()) return N;
			return c;
		}

		void _grow(size_t N) {
			if (N <= this->m_end - this->m_last) return; // there's space, ignore
			if (N > max_size() - size()) throw std::runtime_error("SokuLib: Vector<T> too long.");
			_reallocate(_growRate(size() + N));
		}

		void _reallocate(size_t N) {
			Allocator<value_type> alloc;

			auto ptr = alloc.allocate(N);
			auto size = this->size();
			if (this->m_first) {
				memcpy(ptr, this->m_first, size*sizeof(value_type));
				alloc.deallocate(this->m_first, this->capacity());
			}

			// TODO invalidate debug proxy?
			this->m_end = ptr + N;
			this->m_last = ptr + size;
			this->m_first = ptr;
		}
	};
}

#endif
