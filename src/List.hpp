//
// Created by PinkySmile on 17/02/2021.
//

#ifndef SOKULIB_LIST_HPP
#define SOKULIB_LIST_HPP

#include "Memory.hpp"

namespace SokuLib
{
	template<typename T> class List {
	public:
		using value_type = T;

		struct node_type {
			node_type* next;
			node_type* prev;
			value_type val;

			node_type& operator=(const node_type&) = delete;
		};

		class iterator {
		public:
			using value_type = T;
			node_type* _ptr;

			inline iterator(const iterator& o) : _ptr(o._ptr) {}
			inline iterator(node_type* ptr, const List* container) : _ptr(ptr) {}
			inline value_type& operator*() { return _ptr->val; }
			inline value_type* operator->() { return &**this; }

			inline iterator& operator++() { _ptr = _ptr->next; return *this; }
			inline iterator operator++(int) { iterator tmp = *this; ++*this; return tmp; }
			inline iterator& operator--() { _ptr = _ptr->prev; return *this; }
			inline iterator operator--(int) { iterator tmp = *this; --*this; return tmp; }

			inline bool operator==(const iterator& o) const { return _ptr == o._ptr; }
			inline bool operator!=(const iterator& o) const { return _ptr != o._ptr; }
		};

		// Data
	private:
		uint32_t debug_proxy = 0;
	public:
		node_type* m_head = 0;
		size_t m_size = 0;

		inline List() : m_head(_allocNode()) {}
		inline List(const List& other) : List() { insert(this->begin(), other.begin(), other.end()); }
		inline ~List() { clear(); _freeNode(m_head); }

		List& operator=(const List& other) {
			this->clear();
			insert(begin(), other.begin(), other.end());
			return *this;
		}

		List(List&&) = delete; // TODO
		List& operator=(List&&) = delete; // TODO

		inline iterator begin() const { return iterator(this->m_head->next, this); }
		inline iterator end() const { return iterator(this->m_head, this); }
		inline size_t size() const { return this->m_size; }
		inline size_t max_size() const { return UINT_MAX / sizeof(node_type); }
		inline bool empty() const { return this->m_size == 0; }
		inline value_type& front() { return *begin(); }
		inline const value_type& front() const { return *begin(); }
		inline value_type& back() { return *(--end()); }
		inline const value_type& back() const { return *(--end()); }

		iterator erase(iterator where) {
			node_type* node = (where++)._ptr;
			if (node != this->m_head) {
				node->prev->next = node->next;
				node->next->prev = node->prev;
				_freeNode(node);
				--this->m_size;
			} return where;
		}

		iterator erase(iterator where, iterator finish) {
			while (where != finish)
				where = this->erase(where);
			return where;
		}

		iterator insert(iterator where, value_type&& val) {
			node_type* inode = where._ptr;
			node_type* newnode = _allocNode(inode, inode->prev);
			new (&newnode->val) T(std::forward<T>(val));
			newnode->prev->next = inode->prev = newnode;
			++this->m_size;
			return --where;
		}

		iterator insert(iterator where, const value_type& val) {
			node_type* inode = where._ptr;
			node_type* newnode = _allocNode(inode, inode->prev);
			new (&newnode->val) T(val);
			newnode->prev->next = inode->prev = newnode;
			++this->m_size;
			return --where;
		}

		template <class InputIt>
		inline iterator insert(iterator where, InputIt begin, InputIt end) {
			iterator prev = where; --prev;
			for (;begin != end; ++begin) this->insert(where, *begin);
			return ++prev;
		}

		inline void push_front(value_type&& val) { insert(begin(), std::forward<T>(val)); }
		inline void push_back(value_type&& val) { insert(end(), std::forward<T>(val)); }
		inline void push_front(const value_type& val) { insert(begin(), val); }
		inline void push_back(const value_type& val) { insert(end(), val); }
		inline void pop_front() { erase(begin()); }
		inline void pop_back() { erase(--end()); }

		void clear() {
			node_type* node = this->m_head->next;
			this->m_head->next = this->m_head;
			this->m_head->prev = this->m_head;
			this->m_size = 0;

			for (node_type* pnext; node != this->m_head; node = pnext) {
				pnext = node->next; _freeNode(node);
			}
		}

	private:
		node_type* _allocNode(node_type* next = 0, node_type* prev = 0) {
			node_type* ptr = Allocator<node_type>().allocate(1);
			if (!next) prev = next = ptr;
			ptr->next = next;
			ptr->prev = prev;
			return ptr;
		}

		void _freeNode(node_type* ptr) {
			Allocator<node_type>().deallocate(ptr, 1);
		}
	};
}


#endif //SOKULIB_LIST_HPP
