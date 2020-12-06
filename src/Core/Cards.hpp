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

	struct mDeckInfo2 {
		char UNKNOWN[0x34];
		mVC9Dequeue<short> deck;
		char unknown[0x20];
		unsigned short cardGauge;
		unsigned char cardCount;
		char unknown2[0x5];
		Card **handCardBase;
		int handCardMax;
		int selectedCard; //The actual card is at handCardBase[selectedCard % handCardMax]
		unsigned char cardCount2;
	};

	extern short (__thiscall * const getCard)(mDeckInfo2 *);
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
