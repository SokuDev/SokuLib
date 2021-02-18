//
// Created by PinkySmile on 15/02/2021.
//

#include <SokuLib.hpp>

#define my_assert(val1, val2) if (val1 != val2) return fprintf(stderr, "Assertion "#val1" == "#val2" failed: Expected %#x but got %#x\n", (unsigned)val2, (unsigned)val1), 1

int main()
{
	SokuLib::CharacterManager *manager = (SokuLib::CharacterManager *)&manager;

	my_assert((unsigned)&manager->objectBase.offset_0x000 - (unsigned)manager, 0x000);
	my_assert((unsigned)&manager->objectBase.position.x   - (unsigned)manager, 0x0EC);
	my_assert((unsigned)&manager->objectBase.position.y   - (unsigned)manager, 0x0F0);
	my_assert((unsigned)&manager->objectBase.speed.x      - (unsigned)manager, 0x0F4);
	my_assert((unsigned)&manager->objectBase.speed.y      - (unsigned)manager, 0x0F8);

	my_assert((unsigned)&manager->objectBase.offset_0x0FC - (unsigned)manager, 0x0FC);
	my_assert((unsigned)&manager->objectBase.direction    - (unsigned)manager, 0x104);

	my_assert((unsigned)&manager->objectBase.offset_0x105     - (unsigned)manager, 0x105);
	my_assert((unsigned)&manager->objectBase.action           - (unsigned)manager, 0x13C);
	my_assert((unsigned)&manager->objectBase.actionBlockId    - (unsigned)manager, 0x13E);
	my_assert((unsigned)&manager->objectBase.animationCounter - (unsigned)manager, 0x140);
	my_assert((unsigned)&manager->objectBase.animationSubFrame- (unsigned)manager, 0x142);
	my_assert((unsigned)&manager->objectBase.frameCount       - (unsigned)manager, 0x144);

	my_assert((unsigned)&manager->objectBase.offset_0x148 - (unsigned)manager, 0x148);
	my_assert((unsigned)&manager->objectBase.offset_0x154 - (unsigned)manager, 0x154);
	my_assert((unsigned)&manager->objectBase.hp           - (unsigned)manager, 0x184);

	my_assert((unsigned)&manager->objectBase.offset_0x186 - (unsigned)manager, 0x186);
	my_assert((unsigned)&manager->objectBase.hitstop      - (unsigned)manager, 0x196);

	my_assert((unsigned)&manager->objectBase.offset_0x198 - (unsigned)manager, 0x198);
	my_assert((unsigned)&manager->objectBase.hitBoxCount  - (unsigned)manager, 0x1CB);
	my_assert((unsigned)&manager->objectBase.hurtBoxCount - (unsigned)manager, 0x1CC);

	my_assert((unsigned)&manager->objectBase.offset_0x1CD - (unsigned)manager, 0x1CD);
	my_assert((unsigned)&manager->objectBase.hurtBoxes    - (unsigned)manager, 0x1D0);
	my_assert((unsigned)&manager->objectBase.hurtBoxes[0] - (unsigned)manager, 0x1D0);
	my_assert((unsigned)&manager->objectBase.hurtBoxes[1] - (unsigned)manager, 0x1E0);
	my_assert((unsigned)&manager->objectBase.hurtBoxes[2] - (unsigned)manager, 0x1F0);
	my_assert((unsigned)&manager->objectBase.hurtBoxes[3] - (unsigned)manager, 0x200);
	my_assert((unsigned)&manager->objectBase.hurtBoxes[4] - (unsigned)manager, 0x210);
	my_assert((unsigned)&manager->objectBase.hitBoxes     - (unsigned)manager, 0x220);
	my_assert((unsigned)&manager->objectBase.hitBoxes[0]  - (unsigned)manager, 0x220);
	my_assert((unsigned)&manager->objectBase.hitBoxes[1]  - (unsigned)manager, 0x230);
	my_assert((unsigned)&manager->objectBase.hitBoxes[2]  - (unsigned)manager, 0x240);
	my_assert((unsigned)&manager->objectBase.hitBoxes[3]  - (unsigned)manager, 0x250);
	my_assert((unsigned)&manager->objectBase.hitBoxes[4]  - (unsigned)manager, 0x260);

	my_assert((unsigned)&manager->objectBase.offset_0x270        - (unsigned)manager, 0x270);
	my_assert((unsigned)&manager->objectBase.hitBoxesRotation    - (unsigned)manager, 0x320);
	my_assert((unsigned)&manager->objectBase.hitBoxesRotation[0] - (unsigned)manager, 0x320);
	my_assert((unsigned)&manager->objectBase.hitBoxesRotation[1] - (unsigned)manager, 0x324);
	my_assert((unsigned)&manager->objectBase.hitBoxesRotation[2] - (unsigned)manager, 0x328);
	my_assert((unsigned)&manager->objectBase.hitBoxesRotation[3] - (unsigned)manager, 0x32C);
	my_assert((unsigned)&manager->objectBase.hitBoxesRotation[4] - (unsigned)manager, 0x330);
	my_assert((unsigned)&manager->objectBase.hurtBoxesRotation   - (unsigned)manager, 0x334);
	my_assert((unsigned)&manager->objectBase.hurtBoxesRotation[0]- (unsigned)manager, 0x334);
	my_assert((unsigned)&manager->objectBase.hurtBoxesRotation[1]- (unsigned)manager, 0x338);
	my_assert((unsigned)&manager->objectBase.hurtBoxesRotation[2]- (unsigned)manager, 0x33C);
	my_assert((unsigned)&manager->objectBase.hurtBoxesRotation[3]- (unsigned)manager, 0x340);
	my_assert((unsigned)&manager->objectBase.hurtBoxesRotation[4]- (unsigned)manager, 0x344);

	my_assert((unsigned)&manager->offset_0x348 - (unsigned)manager, 0x348);
	my_assert((unsigned)&manager->airdashCount - (unsigned)manager, 0x49B);

	my_assert((unsigned)&manager->offset_0x49C     - (unsigned)manager, 0x49C);
	my_assert((unsigned)&manager->currentSpirit    - (unsigned)manager, 0x49E);
	my_assert((unsigned)&manager->maxSpirit        - (unsigned)manager, 0x4A0);
	my_assert((unsigned)&manager->spiritRegenDelay - (unsigned)manager, 0x4A2);
	my_assert((unsigned)&manager->timeWithBrokenOrb- (unsigned)manager, 0x4A4);

	my_assert((unsigned)&manager->offset_0x4A6 - (unsigned)manager, 0x4A6);
	my_assert((unsigned)&manager->timeStop     - (unsigned)manager, 0x4A8);

	my_assert((unsigned)&manager->offset_0x4AA - (unsigned)manager, 0x4AA);
	my_assert((unsigned)&manager->correction   - (unsigned)manager, 0x4AD);

	my_assert((unsigned)&manager->offset_0x4AE - (unsigned)manager, 0x4AE);
	my_assert((unsigned)&manager->combo        - (unsigned)manager, 0x4B0);
	my_assert((unsigned)&manager->combo.rate   - (unsigned)manager, 0x4B0);
	my_assert((unsigned)&manager->combo.nbHits - (unsigned)manager, 0x4B4);
	my_assert((unsigned)&manager->combo.damages- (unsigned)manager, 0x4B6);
	my_assert((unsigned)&manager->combo.limit  - (unsigned)manager, 0x4B8);

	my_assert((unsigned)&manager->offset_0x4BA - (unsigned)manager, 0x4BA);
	my_assert((unsigned)&manager->speedPower   - (unsigned)manager, 0x4D0);

	my_assert((unsigned)&manager->offset_0x4D4                - (unsigned)manager, 0x4D4);
	my_assert((unsigned)&manager->swordOfRaptureDebuffTimeLeft- (unsigned)manager, 0x526);
	my_assert((unsigned)&manager->healingCharmTimeLeft        - (unsigned)manager, 0x528);

	my_assert((unsigned)&manager->offset_0x52A - (unsigned)manager, 0x52A);
	my_assert((unsigned)&manager->attackPower  - (unsigned)manager, 0x530);
	my_assert((unsigned)&manager->defensePower - (unsigned)manager, 0x534);

	my_assert((unsigned)&manager->offset_0x538 - (unsigned)manager, 0x538);
	my_assert((unsigned)&manager->grimoires    - (unsigned)manager, 0x560);

	my_assert((unsigned)&manager->offset_0x562 - (unsigned)manager, 0x562);
	my_assert((unsigned)&manager->score        - (unsigned)manager, 0x573);

	my_assert((unsigned)&manager->offset_0x574          - (unsigned)manager, 0x574);
	my_assert((unsigned)&manager->deckInfos             - (unsigned)manager, 0x57C);
	my_assert((unsigned)&manager->deckInfos.cardGauge   - (unsigned)manager, 0x5E4);
	my_assert((unsigned)&manager->deckInfos.cardCount   - (unsigned)manager, 0x5E6);
	my_assert((unsigned)&manager->deckInfos.handCardBase- (unsigned)manager, 0x5EC);
	my_assert((unsigned)&manager->deckInfos.handCardMax - (unsigned)manager, 0x5F0);
	my_assert((unsigned)&manager->deckInfos.selectedCard- (unsigned)manager, 0x5F4);
	my_assert((unsigned)&manager->deckInfos.cardCount2  - (unsigned)manager, 0x5F8);

	my_assert((unsigned)&manager->offset_0x5FC - (unsigned)manager, 0x5FC);
	my_assert((unsigned)&manager->skillMap     - (unsigned)manager, 0x6C4);
	my_assert((unsigned)&manager->skillMap[0]  - (unsigned)manager, 0x6C4);
	my_assert((unsigned)&manager->skillMap[1]  - (unsigned)manager, 0x6C5);
	my_assert((unsigned)&manager->skillMap[2]  - (unsigned)manager, 0x6C6);
	my_assert((unsigned)&manager->skillMap[3]  - (unsigned)manager, 0x6C7);
	my_assert((unsigned)&manager->skillMap[4]  - (unsigned)manager, 0x6C8);
	my_assert((unsigned)&manager->skillMap[5]  - (unsigned)manager, 0x6C9);
	my_assert((unsigned)&manager->skillMap[6]  - (unsigned)manager, 0x6CA);
	my_assert((unsigned)&manager->skillMap[7]  - (unsigned)manager, 0x6CB);
	my_assert((unsigned)&manager->skillMap[8]  - (unsigned)manager, 0x6CC);
	my_assert((unsigned)&manager->skillMap[9]  - (unsigned)manager, 0x6CD);
	my_assert((unsigned)&manager->skillMap[10] - (unsigned)manager, 0x6CE);
	my_assert((unsigned)&manager->skillMap[11] - (unsigned)manager, 0x6CF);
	my_assert((unsigned)&manager->skillMap[12] - (unsigned)manager, 0x6D0);
	my_assert((unsigned)&manager->skillMap[13] - (unsigned)manager, 0x6D1);
	my_assert((unsigned)&manager->skillMap[14] - (unsigned)manager, 0x6D2);
	my_assert((unsigned)&manager->skillMap[15] - (unsigned)manager, 0x6D3);

	my_assert((unsigned)&manager->offset_0x6D4 - (unsigned)manager, 0x6D4);
	my_assert((unsigned)&manager->offset_0x6FC - (unsigned)manager, 0x6FC);
	my_assert((unsigned)&manager->offset_0x754 - (unsigned)manager, 0x754);
	my_assert((unsigned)&manager->tenguFans    - (unsigned)manager, 0x834);

	my_assert((unsigned)&manager->offset_0x836    - (unsigned)manager, 0x836);
	my_assert((unsigned)&manager->sacrificialDolls- (unsigned)manager, 0x840);
	my_assert((unsigned)&manager->controlRod      - (unsigned)manager, 0x844);

	my_assert((unsigned)&manager->offset_0x848      - (unsigned)manager, 0x848);
	my_assert((unsigned)&manager->dragonStarTimeLeft- (unsigned)manager, 0x84E);
	my_assert((unsigned)&manager->drops             - (unsigned)manager, 0x850);
	my_assert((unsigned)&manager->dropInvulTimeLeft - (unsigned)manager, 0x852);

	my_assert((unsigned)&manager->offset_0x854              - (unsigned)manager, 0x854);
	my_assert((unsigned)&manager->milleniumVampireTime      - (unsigned)manager, 0x890);
	my_assert((unsigned)&manager->philosophersStoneTime     - (unsigned)manager, 0x890);
	my_assert((unsigned)&manager->sakuyasWorldTime          - (unsigned)manager, 0x890);
	my_assert((unsigned)&manager->privateSquare             - (unsigned)manager, 0x892);
	my_assert((unsigned)&manager->orreriesTimeLeft          - (unsigned)manager, 0x892);
	my_assert((unsigned)&manager->missingPurplePowerTimeLeft- (unsigned)manager, 0x892);

	my_assert((unsigned)&manager->offset_0x894               - (unsigned)manager, 0x894);
	my_assert((unsigned)&manager->reisenD632                 - (unsigned)manager, 0x898);
	my_assert((unsigned)&manager->reisenA632                 - (unsigned)manager, 0x89A);
	my_assert((unsigned)&manager->kanakoTimeLeft             - (unsigned)manager, 0x89C);
	my_assert((unsigned)&manager->suwakoTimeLeft             - (unsigned)manager, 0x8A0);
	my_assert((unsigned)&manager->elixirUsed                 - (unsigned)manager, 0x8A0);
	my_assert((unsigned)&manager->diamondHardEffectLeft      - (unsigned)manager, 0x8A0);
	my_assert((unsigned)&manager->resurrectionButterfliesUsed- (unsigned)manager, 0x8A0);

	my_assert((unsigned)&manager->offset_0x8A4         - (unsigned)manager, 0x8A4);
	my_assert((unsigned)&manager->infraredMoonTimeLeft - (unsigned)manager, 0x8B2);
	my_assert((unsigned)&manager->fantasyHeavenTimeLeft- (unsigned)manager, 0x8B4);
	my_assert((unsigned)&manager->fantasyHeavenStacks  - (unsigned)manager, 0x8B6);

	my_assert((unsigned)&manager->offset_0x8B8      - (unsigned)manager, 0x8B8);
	my_assert((unsigned)&manager->youmuCloneTimeLeft- (unsigned)manager, 0x8D6);

	my_assert((unsigned)&manager->offset_0x8D8           - (unsigned)manager, 0x8D8);
	my_assert((unsigned)&manager->stateOfEnlightenmentTimeLeft- (unsigned)manager, 0x924);

	my_assert((unsigned)&manager->offset_0x926 - (unsigned)manager, 0x926);
	return 0;
}