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

	CSprite &HandContainer::pushCard(const Card &card)
	{
		return (this->*union_cast<CSprite &(__thiscall HandContainer::*)(const Card &)>(ADDR_PUSH_CARD))(card);
	}

	UnknownCardStruct *deckInfo::lookupCard(int id)
	{
		return (this->*union_cast<UnknownCardStruct *(__thiscall deckInfo::*)(int)>(ADDR_LOOKUP_CARD))(id);
	}

	short deckInfo::getNextCard()
	{
		return (this->*union_cast<short (__thiscall deckInfo::*)()>(ADDR_GET_CARD))();
	}

	void CSprite::init(int unknown1, int unknown2, int unknown3, void *dat1, void *dat2)
	{
		(this->*union_cast<void (__thiscall CSprite::*)(int, int, int, void *, void *)>(ADDR_CSPRITE_INIT))(unknown1, unknown2, unknown3, dat1, dat2);
	}
}