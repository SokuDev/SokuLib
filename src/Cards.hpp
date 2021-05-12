//
// Created by PinkySmile on 06/12/2020.
//

#ifndef SOKULIB_CARDS_HPP
#define SOKULIB_CARDS_HPP


#include "Stack.hpp"
#include "SokuFct.hpp"

namespace SokuLib
{
	struct Vector {
		float x;
		float y;
	};

	struct VectorI {
		int x;
		int y;
	};

	struct DxVertex {
		float x;
		float y;
		float z;
		float rhw;
		unsigned color;
		float u;
		float v;
	};

	struct Sprite {
		void *VTable;
		int dxHandle;
		DxVertex vertices[4];
		Vector size;
		Vector pos;
		Vector scale;
		float rotation;

		void init(int unknown1, int unknown2, int unknown3, int dat1, int dat2);
	};

	[[deprecated("Replaced by Sprite")]]
	typedef Sprite CSprite;

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

	struct UnknownCardStruct {
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

	struct CardData {
		// 0x00
		Dequeue<Card> queue;
		// 0x14
		char offset_0x14[0xC];
	};

	struct DeckInfo {
		// 0x57C (From character manager start)
		CardData cardData;
		// 0x5B0
		Dequeue<unsigned short> deckCopy;
		Dequeue<unsigned short> deck;

		UnknownCardStruct *lookupCard(int id);
		short getNextCard();
	};

	[[deprecated("Replaced with DeckInfo")]]
	typedef DeckInfo deckInfo;
}


#endif //SOKULIB_CARDS_HPP
