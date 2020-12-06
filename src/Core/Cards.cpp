//
// Created by PinkySmile on 06/12/2020.
//

#include "SokuAddresses.hpp"
#include "Cards.hpp"

namespace SokuLib
{
	short (__thiscall * const getCard)(mDeckInfo2 *) = reinterpret_cast<short (__thiscall *)(mDeckInfo2 *)>(ADDR_GET_CARD);
	short *(__thiscall * const peekCard)(mVC9Dequeue<short> *) = reinterpret_cast<short *(__thiscall *)(mVC9Dequeue<short> *)>(ADDR_PEEK_CARD);
}