//
// Created by PinkySmile on 06/12/2020.
//

#include "SokuAddresses.hpp"
#include "Cards.hpp"

namespace SokuLib
{
	Card &HandContainer::operator[](unsigned int id) const
	{
		return *this->handCardBase[(this->selectedCard + id) % this->handCardMax];
	}

	Sprite &HandContainer::pushCard(const Card &card)
	{
		return (this->*union_cast<Sprite &(__thiscall HandContainer::*)(const Card &)>(ADDR_PUSH_CARD))(card);
	}

	UnknownCardStruct *DeckInfo::lookupCard(int id)
	{
		return (this->*union_cast<UnknownCardStruct *(__thiscall DeckInfo::*)(int)>(ADDR_LOOKUP_CARD))(id);
	}

	short DeckInfo::getNextCard()
	{
		return (this->*union_cast<short (__thiscall DeckInfo::*)()>(ADDR_GET_CARD))();
	}
}