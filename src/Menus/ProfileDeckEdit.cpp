//
// Created by PinkySmile on 22/04/2021.
//

#include "ProfileDeckEdit.hpp"
#include "../UnionCast.hpp"

namespace SokuLib
{
	//auto FUN_00433c90 = SokuLib::union_cast<MapNode<unsigned short, unsigned char> *(Map<unsigned short, unsigned char>::*)(unsigned int)>(0x433c90);

	unsigned short ProfileDeckEdit::getSelectedCardId() const
	{
		return this->getSelectedCardIdFromIndex(this->selectedCardIndex);
	}

	unsigned short ProfileDeckEdit::getSelectedCardIdFromIndex(unsigned int index) const
	{
		//return (this->unknownMap->*FUN_00433c90)(index)->next->data.first;
		return 0; // TODO check with Pinky;
	}
}