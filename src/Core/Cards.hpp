//
// Created by PinkySmile on 06/12/2020.
//

#ifndef SWRSTOYS_CARDS_HPP
#define SWRSTOYS_CARDS_HPP


namespace SokuLib
{
	typedef unsigned int undefined4;

	struct mDeckSubStructure { /* Possibly something from the visual studio runtime, vector? */
		undefined4 UnknownObject; /* Created by retype action */
		undefined4* UnknownPtr;
		undefined4 mmAlwaysEight;
		undefined4 UnknownCardCounter;
		int CardsLeft;
	};

	struct mDeckInfo2 {
		char UNKNOWN[0x34];
		struct mDeckSubStructure UnknownSubStructure;
	};

	extern short (__thiscall * const getCard)(mDeckInfo2 *);
	extern short *(__thiscall * const peekCard)(mDeckSubStructure *);

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
