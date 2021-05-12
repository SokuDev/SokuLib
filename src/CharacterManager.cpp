//
// Created by PinkySmile on 20/02/2021.
//

#include "SokuAddresses.hpp"
#include "CharacterManager.hpp"
#include "DatFiles.hpp"

namespace SokuLib
{
	Card *CharacterManager::addCard(unsigned short id)
	{
		SokuLib::Card card;

		if (!this->generateCard(id, card))
			return nullptr;

		int result = reinterpret_cast<int>(&this->hand.pushCard(card));

		this->cardCount = this->hand.size;
		return reinterpret_cast<Card *>(result - 4);
	}

	bool CharacterManager::generateCard(unsigned short id, Card &card)
	{
		auto iVar2 = this->deckInfo.lookupCard(id);

		card.id = id;
		memset(&card.sprite, 0, sizeof(card.sprite));
		card.sprite.VTable = reinterpret_cast<void *>(SokuLib::ADDR_VTBL_CSPRITE);
		if (iVar2) {
			card.cost = iVar2->cost;
			if (iVar2->overrideCost == 1)
				card.cost = 1;
			if (iVar2->unknown)
				card.sprite.init(iVar2->unknown, 0, 0, reinterpret_cast<int>(Dat0x897004), reinterpret_cast<int>(Dat0x897000));
		}
		return iVar2 != nullptr;
	}

	void CharacterManager::playSE(int id)
	{
		(this->*union_cast<void (CharacterManager::*)(int)>(ADDR_PLAY_SE_CHARACTER))(id);
	}
}