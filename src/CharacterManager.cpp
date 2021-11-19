//
// Created by PinkySmile on 20/02/2021.
//

#include "SokuAddresses.hpp"
#include "CharacterManager.hpp"

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
		// memset(&card.sprite, 0, sizeof(card.sprite));
		// card.sprite.VTable = reinterpret_cast<void *>(SokuLib::ADDR_VTBL_CSPRITE);
		if (iVar2) {
			card.cost = iVar2->cost;
			if (iVar2->overrideCost == 1)
				card.cost = 1;
			if (iVar2->unknown)
				card.sprite.init(iVar2->unknown, 0, 0, *(int *)0x897004, *(int *)0x897000);
		}
		return iVar2 != nullptr;
	}

	void CharacterManager::playSE(int id)
	{
		(this->*union_cast<void (CharacterManager::*)(int)>(ADDR_PLAY_SE_CHARACTER))(id);
	}

	void ObjectManager::animate2()
	{
		(*(void (__thiscall **)(SokuLib::ObjectManager *))(*(int *)&this->vtable + 0x14))(this);
		return;

	/*	SokuLib::FrameDataReader *iVar1;
		SokuLib::FrameData *pFVar2;
		unsigned uVar3;

		iVar1 = this->frameDataReader;
		uVar3 = this->animationCounter;
		if (iVar1->frameDataArrayStart != nullptr && uVar3 < (((unsigned)iVar1->frameDataArrayEnd - (unsigned)iVar1->frameDataArrayStart) / 0xa8)) {
			pFVar2 = &iVar1->frameDataArrayStart[uVar3];
			this->image = pFVar2;
			this->animationSubFrameMax = *(unsigned short *)&pFVar2->offset_0x08;
			reinterpret_cast<void (__thiscall *)(SokuLib::ObjectManager *)>(0x43a250)(this);
			return;
		}
		printf("0x%p == nullptr || %u >= (0x%p - 0x%p) / 0xa8 [%u]\n", iVar1->frameDataArrayStart, uVar3, iVar1->frameDataArrayEnd, iVar1->frameDataArrayStart, (((unsigned)iVar1->frameDataArrayEnd - (unsigned)iVar1->frameDataArrayStart) / 0xa8));
		puts("Error 2");*/
	}

	void ObjectManager::animate()
	{
		(*(void (__thiscall **)(SokuLib::ObjectManager *))(*(int *)&this->vtable + 0x10))(this);
		return;
		int local_c;
		int **local_8[2];
		int ***pppiVar3;

		local_c = this->action;
		pppiVar3 = reinterpret_cast<int ***(__thiscall *)(void *, int ***, int *)>(0x43f2f0)(this->offset_0x160, local_8, &local_c);
		if (*pppiVar3 == nullptr || pppiVar3[1] == (int **)(*pppiVar3)[1]) {
			printf("0x%p == nullptr || 0x%p == 0x%p\n", *pppiVar3, pppiVar3[1], (*pppiVar3)[1]);
			puts("Error 1");
			return;
		}
		this->frameDataReader = reinterpret_cast<SokuLib::FrameDataReader *>(pppiVar3[1][4]);
		if (this->frameDataReader->frameDataArrayStart == nullptr)
			this->animationCounterMax = 0;
		else
			this->animationCounterMax = ((unsigned)this->frameDataReader->frameDataArrayEnd - (unsigned)this->frameDataReader->frameDataArrayStart) / 0xA8;
		(*(void (__thiscall **)(SokuLib::ObjectManager *))(*(int *)&this->vtable + 0x18))(this);
	}

	void ObjectManager::doAnimation()
	{
		((unsigned (__thiscall *)(SokuLib::ObjectManager *))0x438c60)(this);
		return;

		if (!this->animationSubFrameMax)
			return;
		this->frameCount++;
		this->animationSubFrame++;
		this->animationSubFrame %= this->animationSubFrameMax;
		if (this->animationSubFrame == 0 && this->animationCounterMax) {
			this->animationCounter++;
			this->animationCounter %= this->animationCounterMax;
			if (this->animationCounter == 0) {
				unsigned iVar1;
				unsigned short uVar2;

				if (this->frameDataReader->nextFrameDataArray != nullptr) {
					this->actionBlockId++;
					this->frameCount = 0;
					this->frameDataReader = this->frameDataReader->nextFrameDataArray;
				}
				iVar1 = (unsigned)this->frameDataReader->frameDataArrayStart;
				if (iVar1 == 0)
					uVar2 = 0;
				else
					uVar2 = (((unsigned)this->frameDataReader->frameDataArrayEnd - iVar1) / 0xa8);
				this->animationCounterMax = uVar2;
				(*(void (__thiscall **)(SokuLib::ObjectManager *, int))(*(int *)&this->vtable + 0x1c))(this, 0);
				if (this->frameDataReader->maxAnimationSomething == 0) {
					this->actionBlockId = 0;
					this->frameCount = 0;
				}
			}
			this->animate2();
		}
	}
}