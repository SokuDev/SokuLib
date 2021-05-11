//
// Created by PinkySmile on 06/12/2020.
//

#ifndef SWRSTOYS_CARDS_HPP
#define SWRSTOYS_CARDS_HPP


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

	struct CSprite {
		void *VTable;
		int dxHandle;
		DxVertex vertices[4];
		char offset_0x78[0x8];
		Vector pos;
		char offset_0x88[0xC];

		void init(int unknown1, int unknown2, int unknown3, int dat1, int dat2);
	};

	struct Card {
		unsigned short id;
		unsigned short cost;
		CSprite sprite;
	};

	// Probably a generic container
	struct HandContainer {
		// 0x5E8
		int unknown;
		// 0x5EC
		Card **handCardBase;
		// 0x5F0
		int handCardMax;
		// 0x5F4
		int selectedCard; //The actual card is at handCardBase[selectedCard % handCardMax]
		// 0x5F8
		unsigned char size;

		Card &operator[](unsigned id) const;
		CSprite &pushCard(const Card &card);
	};

	struct UnknownCardStruct {
		//0x00
		char offset_0x00[0x1C];
		//0x1C
		char overrideCost;
		//0x1D
		char offset_0x1D;
		//0x1E
		unsigned short cost;
		//0x20
		char offset_0x20[0x38];
		//0x58
		int unknown;
	};

	struct deckInfo {
		// 0x57C (From character manager start)
		char UNKNOWN[0x34];
		// 0x5B0
		mVC9Dequeue<unsigned short> deck;
		// 0x5C4
		char unknown[0x20];
		// 0x5E4
		unsigned short cardGauge;
		// 0x5E6
		unsigned char cardCount;
		// 0x5E7
		char padding_0x5E7;
		// 0x5E8
		HandContainer hand;

		UnknownCardStruct *lookupCard(int id);
		short getNextCard();
	};
}


#endif //SWRSTOYS_CARDS_HPP
