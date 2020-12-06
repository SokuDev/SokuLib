//
// Created by PinkySmile on 06/12/2020.
//

#include "SokuAddresses.hpp"
#include "Cards.hpp"

namespace SokuLib
{
	short (__thiscall * const getCard)(mDeckInfo2 *) = reinterpret_cast<short (__thiscall *)(mDeckInfo2 *)>(ADDR_GET_CARD);
	short *(__thiscall * const peekCard)(mDeckSubStructure *) = reinterpret_cast<short *(__thiscall *)(mDeckSubStructure *)>(ADDR_PEEK_CARD);
}