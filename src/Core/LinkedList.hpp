//
// Created by PinkySmile on 17/02/2021.
//

#ifndef SWRSTOYS_LINKEDLIST_HPP
#define SWRSTOYS_LINKEDLIST_HPP


#include <vector>

namespace SokuLib
{
	template<typename T>
	struct Node {
		Node<T> *next;
		Node<T> *prev;
		T *val;
	};

	template<typename T>
	struct LinkedList {
		void *alloc;
		Node<T> *head;
		unsigned int size;

		std::vector<T *> vector() const
		{
			puts("Call 2");
			return static_cast<std::vector<T *>>(*this);
		}

		operator std::vector<T *>() const
		{
			std::vector<T *> result;
			Node<T> *node = this->head;

			for (unsigned int k = 0; node && this->head != node->next && k < this->size; k++) {
				result.push_back(node->val);
				node = node->next;
			}
			return result;
		}

		operator std::vector<T>() const
		{
			std::vector<T> result;
			Node<T> *node = this->head;

			for (unsigned int k = 0; node && this->head != node->next && k < this->size; k++) {
				result.push_back(*node->val);
				node = node->next;
			}
			return result;
		}
	};
}


#endif //SWRSTOYS_LINKEDLIST_HPP
