//
// Created by PinkySmile on 06/12/2020.
//

#ifndef SWRSTOYS_STACK_HPP
#define SWRSTOYS_STACK_HPP

namespace SokuLib
{
	template<class T>
	struct mVC9Dequeue {
		int unknown1;
		T** data;
		int chunkSize;
		int counter;
		int size;

		//Assumes ChunkSize == 8
		//PeekCard
		T &at(int id) {
			int pos = this->counter + id;

			return data[(pos >> 3) % this->chunkSize][pos & 0b111];
		}

		T &operator[](int id) {
			return at(id);
		}

		//GetCard
		T pop_front() {
			//Err, not sure if this works, at/[] might have to be changed to pointers instead
			T &value = at(0);

			this->counter++;
			this->size--;
			return value;
		}
	};
}
#endif //SWRSTOYS_STACK_HPP
