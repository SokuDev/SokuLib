//
// Created by PinkySmile on 06/12/2020.
//

#ifndef SOKULIB_STACK_HPP
#define SOKULIB_STACK_HPP


#include "UnionCast.hpp"
#include "Memory.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	template<typename T>
	struct Dequeue {
		int unknown1;
		T** data;
		int chunkSize;
		int counter;
		int size;

		Dequeue() :
			unknown1(0),
			data(nullptr),
			chunkSize(0),
			counter(0),
			size(0)
		{}

		//Assumes ChunkSize == 8
		//PeekCard
		T &at(int id) {
			int pos = this->counter + id;

			return data[(pos >> 3) % this->chunkSize][pos & 0b111];
		}

		T &operator[](int id) {
			return at(id);
		}

		void push_back(const T &val)
		{
			unsigned uVar1 = (this->size + 8U) >> 3;
			unsigned uVar3;

			if (
				((this->counter + this->size & 7U) == 0) &&
				(this->chunkSize <= uVar1)
			)
				((void (__thiscall *)(Dequeue<T> *, unsigned))0x42c920)(this, 1);
			uVar1 = this->counter + this->size;
			uVar3 = uVar1 >> 3;
			if (this->chunkSize <= uVar3)
				uVar3 = uVar3 - this->chunkSize;
			if (this->data[uVar3] == nullptr)
				this->data[uVar3] = SokuLib::New<T>(0x8);
			if (this->data[uVar3] + (uVar1 & 7) != nullptr)
				this->data[uVar3][uVar1 & 7] = val;
			this->size = this->size + 1;
		}
		
		void clear()
		{
			int ctr = this->chunkSize;

			if (this->size != 0)
				this->counter = 0;
			this->size = 0;

			while (ctr != 0) {
				ctr--;
				if (this->data[ctr] != nullptr)
					SokuLib::Delete(this->data[ctr]);
			}

			if (this->data == nullptr) {
				this->data = nullptr;
				this->chunkSize = 0;
				return;
			}
			SokuLib::Delete(this->data);
			this->data = nullptr;
			this->chunkSize = 0;
		}

		//GetCard
		T pop_front() {
			//Err, not sure if this works, at/[] might have to be changed to pointers instead
			T &value = at(0);

			this->counter++;
			this->size--;
			return value;
		}

		T &peekValue()
		{
			return (this->*union_cast<T *(__thiscall Dequeue<T>::*)()>(ADDR_STACK_PEEK_VALUE))();
		}
	};
}


#endif //SOKULIB_STACK_HPP
