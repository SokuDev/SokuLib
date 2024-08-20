//
// Created by PinkySmile on 06/12/2020.
//

#ifndef SOKULIB_CARDS_HPP
#define SOKULIB_CARDS_HPP


#include "Stack.hpp"
#include "UnionCast.hpp"
#include "Sprite.hpp"
#include "String.hpp"

namespace SokuLib
{
	struct Card {
		unsigned short id;
		unsigned short cost;
		Sprite sprite;
	};

	// Probably a generic container
	struct HandContainer {
		// 0x00
		int offset_0x00;
		// 0x04
		Card **handCardBase;
		// 0x08
		int handCardMax;
		// 0x0C
		int selectedCard; //The actual card is at handCardBase[selectedCard % handCardMax]
		// 0x10
		unsigned int size;
		// 0x14
		char offset_0x14[0x8];
		// 0x1C
		int handCardMax2;
		// 0x20
		int handCardCount;
		// 0x24
		int handCardUsed;

		Card &operator[](unsigned id) const;
		Sprite &pushCard(const Card &card);
	};

	struct [[deprecated("Use CardInfo instead")]] UnknownCardStruct {
		// 0x00
		char offset_0x00[0x1C];
		// 0x1C
		char overrideCost;
		// 0x1D
		char offset_0x1D;
		// 0x1E
		unsigned short cost;
		// 0x20
		char offset_0x20[0x38];
		// 0x58
		int unknown;
	};

	struct CardInfo {
		String name;

		// offset: 0x1C
		char type; // align 1
		unsigned short costOrSlot;
		String description;

		// offset: 0x2C
		short apparency;
		char rarity; // align 1
		short cellH, cellJ, cellL;
		char cellI, cellK, cellM;
		// align 3
		int cellN;

		// offset: 0x44
		short sort; // align 2
		int texIdA; // seem to be the same for all cards
		int texIdB; // this one differs
		int unknown5C; // multiple of 16 (some kind of coord?)
	};

	struct CardData {
		// 0x00
		Dequeue<Card> queue;
		// 0x14
		char offset_0x14[0xC];
	};

	struct DeckInfo {
		// 0x00
		CardData cardData;
		// 0x20
		Dequeue<unsigned short> deckCopy;
		// 0x34
		Dequeue<unsigned short> deck;

		UnknownCardStruct *lookupCard(int id);
		short getNextCard();
	};
}


#endif //SOKULIB_CARDS_HPP
