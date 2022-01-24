//
// Created by PinkySmile on 17/02/2021.
//

#ifndef SOKULIB_LINKEDLIST_HPP
#define SOKULIB_LINKEDLIST_HPP


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
			return static_cast<std::vector<T *>>(*this);
		}

		operator std::vector<T *>() const
		{
			if (!this->size || !this->head)
				return {};

			std::vector<T *> result;
			Node<T> *node = this->head->next;

			for (unsigned int k = 0; node && k < this->size; k++) {
				result.push_back(node->val);
				node = node->next;
			}
			return result;
		}

		operator std::vector<T>() const
		{
			if (!this->size || !this->head)
				return {};

			std::vector<T> result;
			Node<T> *node = this->head->next;

			for (unsigned int k = 0; node && k < this->size; k++) {
				result.push_back(*node->val);
				node = node->next;
			}
			return result;
		}
	};
}


#endif //SOKULIB_LINKEDLIST_HPP
