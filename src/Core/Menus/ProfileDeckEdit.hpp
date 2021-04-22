//
// Created by PinkySmile on 22/04/2021.
//

#ifndef SWRSTOYS_PROFILEDECKEDIT_HPP
#define SWRSTOYS_PROFILEDECKEDIT_HPP


#include "../Map.hpp"

namespace SokuLib
{
	struct T {
		char balec[0x468];
	};

	struct ProfileDeckEdit {
		char offset_0x00[0x468];
		// 0x468
		Map<unsigned short, unsigned char> *editedDeck;
		// 0x46C
		Map<unsigned short, unsigned char> deck1;
		// 0x478
		Map<unsigned short, unsigned char> deck2;
		// 0x484
		Map<unsigned short, unsigned char> deck3;
		// 0x490
		Map<unsigned short, unsigned char> deck4;
		// 0x49C
		Map<unsigned short, unsigned char> *unknownMap;
		// 0x4A0
		char offset_0x4A0[0x11];
		// 0x4B1
		unsigned char displayedNumberOfCards;
		// 0x4B2
		char offset_0x4B2[0xE];
		// 0x4C0
		unsigned int selectedCardIndex;
		// 0x4C4
		char offset_0x4C4[0x10];
		// 0x4D4
		unsigned int panel;

		unsigned short getSelectedCardId() const;
		unsigned short getSelectedCardIdFromIndex(unsigned int index) const;
	};
}

#endif //SWRSTOYS_PROFILEDECKEDIT_HPP
