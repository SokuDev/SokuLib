//
// Created by PinkySmile on 22/04/2021.
//

#ifndef SOKULIB_PROFILEDECKEDIT_HPP
#define SOKULIB_PROFILEDECKEDIT_HPP


#include "../Map.hpp"
#include "../Cards.hpp"
#include "../Character.hpp"

namespace SokuLib
{
	struct Guide {
		bool active;
		char offset_0x1[0x3];
		void *imagePtr;
		Sprite sprite;
		char offset_0x9C[0x4];
		float size;
		unsigned char fadeTimer;
		char offset_0xA5[0x3];
	};

	struct ProfileDeckEdit {
		void *vtable;
		// 0x4
		char offset_0x04[0x4];
		// 0x8
		Character editedCharacter;
		// 0xC
		char offset_0x0C[0x45C];
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
		// 0x4D8
		char offset_0x4D8[0x10];
		// 0x4E8
		unsigned int selectedDeck;
		// 0x4EC
		char offset_0x4EC[0x6];
		// 0x4F2
		bool saveDialogDisplayed;
		// 0x4F3
		char offset_0x4F3;
		// 0x4F4
		bool cursorOnDeckChangeBox;
		// 0x4F5
		char offset_0x4F5[0x3];
		// 0x4F8
		Guide guideVector[5];

		unsigned short getSelectedCardId() const;
		unsigned short getSelectedCardIdFromIndex(unsigned int index) const;
	};
}

#endif //SOKULIB_PROFILEDECKEDIT_HPP
