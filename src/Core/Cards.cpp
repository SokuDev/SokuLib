//
// Created by PinkySmile on 06/12/2020.
//

#include "SokuAddresses.hpp"
#include "Cards.hpp"

namespace SokuLib
{
	short (__thiscall * const getCard)(deckInfo *) = reinterpret_cast<short (__thiscall *)(deckInfo *)>(ADDR_GET_CARD);
	short *(__thiscall * const peekCard)(mVC9Dequeue<short> *) = reinterpret_cast<short *(__thiscall *)(mVC9Dequeue<short> *)>(ADDR_PEEK_CARD);
}