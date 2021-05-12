//
// Created by PinkySmile on 12/05/2021.
//

#include "Sprite.hpp"
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	void Sprite::init(int unknown1, int unknown2, int unknown3, int dat1, int dat2)
	{
		(this->*union_cast<void (__thiscall Sprite::*)(int, int, int, int , int )>(ADDR_CSPRITE_INIT))(unknown1, unknown2, unknown3, dat1, dat2);
	}
}