//
// Created by PinkySmile on 06/12/2020.
//

#ifndef SWRSTOYS_CARDS_HPP
#define SWRSTOYS_CARDS_HPP


#include "Stack.hpp"

namespace SokuLib
{
	typedef unsigned int undefined4;

	struct Card {
		unsigned short id;
		unsigned short cost;
	};

	struct deckInfo {
		// 0x57C (From character manager start)
		char UNKNOWN[0x34];
		// 0x5B0
		mVC9Dequeue<short> deck;
		// 0x5C4
		char unknown[0x20];
		// 0x5E4
		unsigned short cardGauge;
		// 0x5E6
		unsigned char cardCount;
		// 0x5E7
		char unknown2[0x5];
		// 0x5EC
		Card **handCardBase;
		// 0x5F0
		int handCardMax;
		// 0x5F4
		int selectedCard; //The actual card is at handCardBase[selectedCard % handCardMax]
		// 0x5F8
		unsigned char cardCount2;
	};

	extern short (__thiscall * const getCard)(deckInfo *);
	extern short *(__thiscall * const peekCard)(mVC9Dequeue<short> *);

	struct mDeckData { /* Size unknown, function not completely known. */
		undefined4 unknown1;
		undefined4 *cardInHandSprites;
		unsigned int mmMax;
		int selectedCard;
		int cardInHandCount;
		undefined4 field_0x14;
		undefined4 *field_0x18;
		int mmMax2;
		int mmSomeSortOfCount;
		int totalCardsUsed;
	};
}


#endif //SWRSTOYS_CARDS_HPP
