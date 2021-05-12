//
// Created by PinkySmile on 22/04/2021.
//

#include <cassert>
#include "Map.hpp"
#include "SokuFct.hpp"

namespace SokuLib
{
	auto FUN_0044e050 = SokuLib::union_cast<MapNode<unsigned short, unsigned char> *(Map<unsigned short, unsigned char>::*)(MapNode<unsigned short, unsigned char> *, const unsigned short &)>(0x44e050);
	auto FUN_0044f3e0 = SokuLib::union_cast<MapNode<unsigned short, unsigned char> *(Map<unsigned short, unsigned char>::*)(MapNode<unsigned short, unsigned char> *, const unsigned short &)>(0x44f3e0);

	template<>
	unsigned char &Map<unsigned short, unsigned char>::operator[](const unsigned short &key)
	{
		MapNode<unsigned short, unsigned char> buffer;

		(this->*FUN_0044e050)(&buffer, key);
		if (buffer.next == this->data)
			(this->*FUN_0044f3e0)(&buffer, key)->next->data.second = 0;
		assert(buffer.next != this->data);
		return buffer.next->data.second;
	}
}