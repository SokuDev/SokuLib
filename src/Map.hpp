//
// Created by PinkySmile on 22/04/2021.
//

#ifndef SOKULIB_MAP_HPP
#define SOKULIB_MAP_HPP


#include "Memory.hpp"
#include <utility>

namespace SokuLib
{

	template<typename T1, typename T2>
	class Map {
		enum Color:char {_Red, _Black};
	public:
		using value_type = std::pair<T1, T2>;

		struct Node {
			Node* left;
			Node* parent;
			Node* right;
			value_type val;
			Color color;
			bool isNil;
		};

		class Iterator {
		public:
			Node* ptr;

			Iterator(Node* ptr) : ptr(ptr) {}

			value_type& operator*() const { return this->ptr->val; }

			value_type* operator->() const {
				return &this->ptr->val;
			}

			bool operator==(const Iterator& other) const {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const Iterator& other) const {
				return !(this->ptr == other.ptr);
			}

			Iterator& operator++() {
				if (this->ptr->isNil) ;// do nothing
				else if (!this->ptr->right->isNil) {
					// leftmost of right tree
					this->ptr = this->ptr->right;
					while(!this->ptr->left->isNil)
						this->ptr = this->ptr->left;
				} else {
					// climb tree
					Node* next = this->ptr->parent;
					while (!next->isNil && this->ptr == next->right) {
						this->ptr = next;
						next = next->parent;
					} this->ptr = next;
				}
				return *this;
			}

			Iterator operator++(int) {
				Iterator tmp = *this;
				++*this;
				return tmp;
			}

			Iterator& operator--() {
				if (this->ptr->isNil) this->ptr = this->ptr->right;
				else if(!this->ptr->left->isNil) {
					// rightmost of left tree
					this->ptr = this->ptr->left;
					while(!this->ptr->right->isNil)
						this->ptr = this->ptr->right;
				} else {
					// climb tree
					Node* next = this->ptr->parent;
					while(!next->isNil && this->ptr == next->left) {
						this->ptr = next;
						next = next->parent;
					}
					if (!this->ptr->isNil) this->ptr = next;
				}
				return *this;
			}

			Iterator operator--(int) {
				Iterator tmp = *this;
				--*this;
				return tmp;
			}
		};

		// Data
		char offset00[4];
		Node* head;
		int size;

		Map() {
			this->size = 0;
			this->head = (Node*)SokuLib::NewFct(sizeof(Node));
			this->head->left = this->head;
			this->head->parent = this->head;
			this->head->right = this->head;
			this->head->color = Color::_Black;
			this->head->isNil = true;
		}

	private:
		Node* _newNode(const value_type& value) {
			Node* node = (Node*)SokuLib::NewFct(sizeof(Node));
			node->left = this->head;
			node->parent = this->head;
			node->right = this->head;
			node->color = Color::_Red;
			node->isNil = false;
			new (&node->val) value_type(value);
			return node;
		}

		void _erase(Node* root) {
			for (Node* node = root; !node->isNil; root = node) {
				_erase(node->right);
				node->val.~value_type();
				node = node->left;
				SokuLib::DeleteFct(root);
			}
		}

		void _Lrotate(Node* where) {
			Node* node = where->right;
			where->right = node->left;

			if (!node->left->isNil) node->left->parent = where;
			node->parent = where->parent;

			if (this->head->parent == where) this->head->parent = node;
			else if (where == where->parent->left)
				where->parent->left = node;
			else where->parent->right = node;

			node->left = where;
			where->parent = node;
		}

		void _Rrotate(Node* where) {
			Node* node = where->left;
			where->left = node->right;

			if (!node->right->isNil) node->right->parent = where;
			node->parent = where->parent;

			if (this->head->parent == where) this->head->parent = node;
			else if (where == where->parent->right)
				where->parent->right = node;
			else where->parent->left = node;

			node->right = where;
			where->parent = node;
		}

		Iterator _insert(bool addLeft, Node* where, Node* newNode) {
			++this->size;
			newNode->parent = where;
			if (where == this->head) {
				this->head->parent = newNode;
				this->head->left = newNode;
				this->head->right = newNode;
			} else if (addLeft) {
				where->left = newNode;
				if (this->head->left == where)
					this->head->left = newNode;
			} else {
				where->right = newNode;
				if (this->head->right == where)
					this->head->right = newNode;
			}

			for (Node* node = newNode; node->parent->color == Color::_Red;) {
				if (node->parent == node->parent->parent->left) {
					where = node->parent->parent->right;
					if (where->color == Color::_Red) {
						node->parent->color = Color::_Black;
						where->color = Color::_Black;
						node->parent->parent->color = Color::_Red;
						node = node->parent->parent;
					} else {
						if (node == node->parent->right) {
							node = node->parent;
							this->_Lrotate(node);
						}

						node->parent->color = Color::_Black;
						node->parent->parent->color = Color::_Red;
						this->_Rrotate(node->parent->parent);
					}
				} else {
					where = node->parent->parent->left;
					if (where->color == Color::_Red) {
						node->parent->color = Color::_Black;
						where->color = Color::_Black;
						node->parent->parent->color = Color::_Red;
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							this->_Rrotate(node);
						}

						node->parent->color = Color::_Black;
						node->parent->parent->color = Color::_Red;
						this->_Lrotate(node->parent->parent);
					}
				}
			}

			this->head->parent->color = Color::_Black;
			return Iterator(newNode);
		}

		Iterator _insert(const Iterator& where, const value_type& value) {
			Node* node = this->_newNode(value);
			if (this->size == 0) return this->_insert(true, this->head, node);

			if (where == this->head->left) {
				if (value.first < where->first)
					return this->_insert(true, where.ptr, node);
			} else if (where == this->head) {
				if (this->head->right->val.first < value.first)
					return this->_insert(false, this->head->right, node);
			} else if (value.first < where->first) {
				Iterator _next = where; --_next;
				if (_next->first < value.first) {
					if (_next.ptr->right->isNil)
						return this->_insert(false, _next.ptr, node);
					else return this->_insert(true, where.ptr, node);
				}
			} else if (where->first < value.first) {
				Iterator _next = where; ++_next;
				if (_next.ptr == this->head || value.first < _next->first){
					if (where.ptr->right->isNil)
						return this->_insert(false, where.ptr, node);
					return this->_insert(true, _next.ptr, node);
				}
			}

			// hint fail, do normal insert;
			Node* tnode = this->head->parent;
			Node* wnode = this->head;
			bool addLeft = true;
			while(!tnode->isNil) {
				wnode = tnode;
				addLeft = value.first < tnode->val.first;
				tnode = addLeft ? tnode->left : tnode->right;
			}

			Iterator next(wnode);
			if (addLeft) {
				if (wnode == this->head->left) {
					return this->_insert(true, wnode, node);
				} else --next;
			}

			if (next->first < value.first) return this->_insert(addLeft, wnode, node);

			// duplicate
			node->val.~value_type();
			SokuLib::DeleteFct(node);
			return next;
		}

		Iterator _lower_bound(const T1& key) {
			Node* node = this->head->parent;
			Node* lower = this->head;

			while (!node->isNil) {
				if (node->val.first < key) {
					node = node->right;
				} else {
					lower = node;
					node = node->left;
				}
			}

			return Iterator(lower);
		}

		Node* _min(Node* node) {
			while(!node->left->isNil) node = node->left;
			return node;
		}

		Node* _max(Node* node) {
			while(!node->right->isNil) node = node->right;
			return node;
		}

		Node* _copy(Node* node, Node* where) {
			Node* ret = this->head;
			if (!node->isNil) {
				Node* tnode = this->_newNode(node->val);
				tnode->parent = where;
				tnode->color = node->color;
				if (ret->isNil) ret = tnode;
				tnode->left = _copy(node->left, tnode);
				tnode->right = _copy(node->right, tnode);
			}

			return ret;
		}

	public:
		Map(const Map& o) : Map() {
			this->head->parent = this->_copy(o.head->parent, this->head);
			this->size = o.size;
			if (this->head->parent->isNil) {
				this->head->left = this->head;
				this->head->right = this->head;
			} else {
				this->head->left = this->_min(this->head->parent);
				this->head->right = this->_max(this->head->parent);
			}
		}

		Iterator begin() {
			return Iterator(this->head->left);
		}

		Iterator end() {
			return Iterator(this->head);
		}

		void clear() {
			this->_erase(this->head->parent);
			this->size = 0;
			this->head->parent = this->head;
			this->head->left = this->head;
			this->head->right = this->head;
		}

		T2& operator[](const T1& key) {
			Iterator iter = this->_lower_bound(key);
			if (iter == this->end() || key < iter->first) {
				iter = this->_insert(iter, std::pair(key, T2()));
			}
			return iter->second;
		}

		Iterator find(const T1& key) {
			Iterator iter = this->_lower_bound(key);
			if (iter != this->end() && key < iter->first)
				iter = this->end();
			return iter;
		}

		~Map() {
			this->_erase(this->head->parent);
			SokuLib::DeleteFct(this->head);
			this->head = 0;
		}
	};
}

#endif //SOKULIB_MAP_HPP
