//
// Created by PinkySmile on 15/02/2021.
//

#include <SokuLib.hpp>

#define assert_equal(val1, val2) if ((val1) != (val2)) fprintf(stderr, "Assertion "#val1" == "#val2" failed: Expected %#x but got %#x\n", (unsigned)val2, (unsigned)val1)
#define check_offset(v, field, offset) assert_equal((int)&(v)->field - (int)(v), offset)

void testCharacterManager()
{
	SokuLib::CharacterManager *manager = (SokuLib::CharacterManager *)&manager;

	check_offset(manager, objectBase.vtable      , 0x000);
	check_offset(manager, objectBase.sprite     , 0x004);
	check_offset(manager, objectBase.position.x  , 0x0EC);
	check_offset(manager, objectBase.position.y  , 0x0F0);
	check_offset(manager, objectBase.speed.x     , 0x0F4);
	check_offset(manager, objectBase.speed.y     , 0x0F8);

	check_offset(manager, objectBase.gravity     , 0x0FC);
	check_offset(manager, objectBase.direction   , 0x104);

	check_offset(manager, objectBase.offset_0x105       , 0x105);
	check_offset(manager, objectBase.action             , 0x13C);
	check_offset(manager, objectBase.actionBlockId      , 0x13E);
	check_offset(manager, objectBase.animationCounter   , 0x140);
	check_offset(manager, objectBase.animationSubFrame  , 0x142);
	check_offset(manager, objectBase.frameCount         , 0x144);
	check_offset(manager, objectBase.animationCounterMax, 0x148);

	check_offset(manager, objectBase.offset_0x14A, 0x14A);
	check_offset(manager, objectBase.offset_0x154, 0x154);
	check_offset(manager, objectBase.hp          , 0x184);

	check_offset(manager, objectBase.offset_0x186, 0x186);
	check_offset(manager, objectBase.hitCount    , 0x194);
	check_offset(manager, objectBase.offset_0x195, 0x195);
	check_offset(manager, objectBase.hitstop     , 0x196);

	check_offset(manager, objectBase.offset_0x198, 0x198);
	check_offset(manager, objectBase.hitBoxCount , 0x1CB);
	check_offset(manager, objectBase.hurtBoxCount, 0x1CC);

	check_offset(manager, objectBase.offset_0x1CD, 0x1CD);
	check_offset(manager, objectBase.hurtBoxes   , 0x1D0);
	check_offset(manager, objectBase.hurtBoxes[0], 0x1D0);
	check_offset(manager, objectBase.hurtBoxes[1], 0x1E0);
	check_offset(manager, objectBase.hurtBoxes[2], 0x1F0);
	check_offset(manager, objectBase.hurtBoxes[3], 0x200);
	check_offset(manager, objectBase.hurtBoxes[4], 0x210);
	check_offset(manager, objectBase.hitBoxes    , 0x220);
	check_offset(manager, objectBase.hitBoxes[0] , 0x220);
	check_offset(manager, objectBase.hitBoxes[1] , 0x230);
	check_offset(manager, objectBase.hitBoxes[2] , 0x240);
	check_offset(manager, objectBase.hitBoxes[3] , 0x250);
	check_offset(manager, objectBase.hitBoxes[4] , 0x260);

	check_offset(manager, objectBase.offset_0x270        , 0x270);
	check_offset(manager, objectBase.hitBoxesRotation    , 0x320);
	check_offset(manager, objectBase.hitBoxesRotation[0] , 0x320);
	check_offset(manager, objectBase.hitBoxesRotation[1] , 0x324);
	check_offset(manager, objectBase.hitBoxesRotation[2] , 0x328);
	check_offset(manager, objectBase.hitBoxesRotation[3] , 0x32C);
	check_offset(manager, objectBase.hitBoxesRotation[4] , 0x330);
	check_offset(manager, objectBase.hurtBoxesRotation   , 0x334);
	check_offset(manager, objectBase.hurtBoxesRotation[0], 0x334);
	check_offset(manager, objectBase.hurtBoxesRotation[1], 0x338);
	check_offset(manager, objectBase.hurtBoxesRotation[2], 0x33C);
	check_offset(manager, objectBase.hurtBoxesRotation[3], 0x340);
	check_offset(manager, objectBase.hurtBoxesRotation[4], 0x344);

	check_offset(manager, offset_0x348, 0x348);

	check_offset(manager, airDashCount, 0x49B);

	check_offset(manager, offset_0x49C     , 0x49C);
	check_offset(manager, currentSpirit    , 0x49E);
	check_offset(manager, maxSpirit        , 0x4A0);
	check_offset(manager, spiritRegenDelay , 0x4A2);
	check_offset(manager, timeWithBrokenOrb, 0x4A4);

	check_offset(manager, nextTimeStop, 0x4A6);
	check_offset(manager, timeStop    , 0x4A8);

	check_offset(manager, offset_0x4AA, 0x4AA);
	check_offset(manager, correction  , 0x4AD);

	check_offset(manager, offset_0x4AE , 0x4AE);
	check_offset(manager, combo        , 0x4B0);
	check_offset(manager, combo.rate   , 0x4B0);
	check_offset(manager, combo.nbHits , 0x4B4);
	check_offset(manager, combo.damages, 0x4B6);
	check_offset(manager, combo.limit  , 0x4B8);
	check_offset(manager, untech       , 0x4BA);

	check_offset(manager, offset_0x4BC, 0x4BC);
	check_offset(manager, speedPower  , 0x4D0);

	check_offset(manager, offset_0x4D4                , 0x4D4);
	check_offset(manager, swordOfRaptureDebuffTimeLeft, 0x526);
	check_offset(manager, healingCharmTimeLeft        , 0x528);

	check_offset(manager, offset_0x52A, 0x52A);
	check_offset(manager, attackPower , 0x530);
	check_offset(manager, defensePower, 0x534);
	check_offset(manager, noSuperArmor, 0x538);

	check_offset(manager, offset_0x53C, 0x53C);
	check_offset(manager, grimoires   , 0x560);

	check_offset(manager, offset_0x562, 0x562);
	check_offset(manager, score       , 0x573);

	check_offset(manager, roundLost             , 0x574);
	check_offset(manager, deckInfo              , 0x57C);
	check_offset(manager, cardGauge             , 0x5E4);
	check_offset(manager, cardCount             , 0x5E6);
	check_offset(manager, hand                  , 0x5E8);
	check_offset(manager, hand.handCardBase, 0x5EC);
	check_offset(manager, hand.handCardMax , 0x5F0);
	check_offset(manager, hand.selectedCard, 0x5F4);
	check_offset(manager, hand.size        , 0x5F8);

	check_offset(manager, offset_0x610        , 0x610);
	check_offset(manager, skillLevels         , 0x6A4);
	check_offset(manager, skillLevels[0] , 0x6A4);
	check_offset(manager, skillLevels[1] , 0x6A5);
	check_offset(manager, skillLevels[2] , 0x6A6);
	check_offset(manager, skillLevels[3] , 0x6A7);
	check_offset(manager, skillLevels[4] , 0x6A8);
	check_offset(manager, skillLevels[5] , 0x6A9);
	check_offset(manager, skillLevels[6] , 0x6AA);
	check_offset(manager, skillLevels[7] , 0x6AB);
	check_offset(manager, skillLevels[8] , 0x6AC);
	check_offset(manager, skillLevels[9] , 0x6AD);
	check_offset(manager, skillLevels[10], 0x6AE);
	check_offset(manager, skillLevels[11], 0x6AF);
	check_offset(manager, skillLevels[12], 0x6B0);
	check_offset(manager, skillLevels[13], 0x6B1);
	check_offset(manager, skillLevels[14], 0x6B2);
	check_offset(manager, skillLevels[15], 0x6B3);

	check_offset(manager, offset_0x6B4, 0x6B4);
	check_offset(manager, skillMap    , 0x6C4);
	check_offset(manager, skillMap[0] , 0x6C4);
	check_offset(manager, skillMap[1] , 0x6C5);
	check_offset(manager, skillMap[2] , 0x6C6);
	check_offset(manager, skillMap[3] , 0x6C7);
	check_offset(manager, skillMap[4] , 0x6C8);
	check_offset(manager, skillMap[5] , 0x6C9);
	check_offset(manager, skillMap[6] , 0x6CA);
	check_offset(manager, skillMap[7] , 0x6CB);
	check_offset(manager, skillMap[8] , 0x6CC);
	check_offset(manager, skillMap[9] , 0x6CD);
	check_offset(manager, skillMap[10], 0x6CE);
	check_offset(manager, skillMap[11], 0x6CF);
	check_offset(manager, skillMap[12], 0x6D0);
	check_offset(manager, skillMap[13], 0x6D1);
	check_offset(manager, skillMap[14], 0x6D2);
	check_offset(manager, skillMap[15], 0x6D3);

	check_offset(manager, offset_0x6D4         , 0x6D4);
	//check_offset(manager, patternData          , 0x6FC);
	check_offset(manager, offset_0x6FC         , 0x6FC);
	check_offset(manager, keyMap               , 0x754);
	check_offset(manager, keyMap.horizontalAxis, 0x754);
	check_offset(manager, keyMap.verticalAxis  , 0x758);
	check_offset(manager, keyMap.a             , 0x75C);
	check_offset(manager, keyMap.b             , 0x760);
	check_offset(manager, keyMap.c             , 0x764);
	check_offset(manager, keyMap.d             , 0x768);
	check_offset(manager, keyMap.changeCard    , 0x76C);
	check_offset(manager, keyMap.spellcard     , 0x770);

	check_offset(manager, keyMap.pause , 0x774);
	check_offset(manager, chargedAttack, 0x7F4);

	check_offset(manager, offset_0x7F5 , 0x7F5);
	check_offset(manager, damageLimited, 0x7F7);
	check_offset(manager, offset_0x7F8 , 0x7F8);
	check_offset(manager, tenguFans    , 0x834);

	check_offset(manager, offset_0x836       , 0x836);
	check_offset(manager, sacrificialDolls   , 0x840);
	check_offset(manager, controlRod         , 0x844);
	check_offset(manager, magicPotionTimeLeft, 0x848);

	check_offset(manager, offset_0x84C      , 0x84C);
	check_offset(manager, dragonStarTimeLeft, 0x84E);
	check_offset(manager, drops             , 0x850);
	check_offset(manager, dropInvulTimeLeft , 0x852);

	check_offset(manager, offset_0x854              , 0x854);
	check_offset(manager, milleniumVampireTime      , 0x890);
	check_offset(manager, philosophersStoneTime     , 0x890);
	check_offset(manager, sakuyasWorldTime          , 0x890);
	check_offset(manager, privateSquare             , 0x892);
	check_offset(manager, orreriesTimeLeft          , 0x892);
	check_offset(manager, missingPurplePowerTimeLeft, 0x892);

	check_offset(manager, offset_0x894               , 0x894);
	check_offset(manager, reisenD632                 , 0x898);
	check_offset(manager, reisenA632                 , 0x89A);
	check_offset(manager, kanakoTimeLeft             , 0x89C);
	check_offset(manager, suwakoTimeLeft             , 0x8A0);
	check_offset(manager, elixirUsed                 , 0x8A0);
	check_offset(manager, diamondHardEffectLeft      , 0x8A0);
	check_offset(manager, resurrectionButterfliesUsed, 0x8A0);

	check_offset(manager, offset_0x8A4         , 0x8A4);
	check_offset(manager, infraredMoonTimeLeft , 0x8B2);
	check_offset(manager, fantasyHeavenTimeLeft, 0x8B4);
	check_offset(manager, fantasyHeavenStacks  , 0x8B6);

	check_offset(manager, offset_0x8B8      , 0x8B8);
	check_offset(manager, youmuCloneTimeLeft, 0x8D6);

	check_offset(manager, offset_0x8D8                , 0x8D8);
	check_offset(manager, stateOfEnlightenmentTimeLeft, 0x924);

	check_offset(manager, offset_0x926, 0x926);

	// v2
	using namespace SokuLib;

	assert_equal(sizeof(v2::GameObjectBase), 0x34C);
	assert_equal(offsetof(v2::GameObjectBase, gameData), 0x158);
	assert_equal(offsetof(v2::GameObjectBase, HP), 0x184);
	assert_equal(offsetof(v2::GameObjectBase, boxData), 0x1B4);

	assert_equal(sizeof(v2::GameObject), 0x3AC);
	assert_equal(offsetof(v2::GameObject, lifetime), 0x34C);
	assert_equal(offsetof(v2::GameObject, parentB), 0x39C);

	assert_equal(sizeof(v2::Player), 0x890);
	assert_equal(offsetof(v2::Player, characterIndex), 0x34C);
	assert_equal(offsetof(v2::Player, redHP), 0x498);
	assert_equal(offsetof(v2::Player, deckInfo), 0x57C);
	assert_equal(offsetof(v2::Player, handInfo), 0x5E4);
	assert_equal(offsetof(v2::Player, unknown610), 0x610);
	assert_equal(offsetof(v2::Player, objectList), 0x6f8);
	assert_equal(offsetof(v2::Player, unknown714), 0x714);
	assert_equal(offsetof(v2::Player, inputData), 0x754);
	assert_equal(offsetof(v2::Player, dashTimer), 0x7D0);
}

void testSelectScene()
{
	SokuLib::Select *select = reinterpret_cast<SokuLib::Select *>(&select);

	check_offset(select, base, 0x00);
//	check_offset(select, offset_0x001, 0x01);
	check_offset(select, leftKeys, 0x10);
	check_offset(select, rightKeys, 0x14);
	check_offset(select, offset_0x018, 0x18);
	// check_offset(select, leftCursor, 0x128);
	// check_offset(select, leftCursor.alwaysZero, 0x128);
	// check_offset(select, leftCursor.alwaysTwenty, 0x12C);
	// check_offset(select, leftCursor.keys, 0x130);
	// check_offset(select, leftCursor.cursorPos, 0x134);
	// check_offset(select, leftCursor.cursorPosUnused, 0x138);
	// check_offset(select, rightCursor, 0x13C);
	// check_offset(select, rightCursor.alwaysZero, 0x13C);
	// check_offset(select, rightCursor.alwaysTwenty, 0x140);
	// check_offset(select, rightCursor.keys, 0x144);
	// check_offset(select, rightCursor.cursorPos, 0x148);
	// check_offset(select, rightCursor.cursorPosUnused, 0x14C);
	// check_offset(select, leftSelect, 0x150);
	// check_offset(select, leftSelect.alwaysFive, 0x150);
	// check_offset(select, leftSelect.alwaysZero, 0x154);
	// check_offset(select, leftSelect.keys, 0x158);
	// check_offset(select, leftSelect.deck, 0x15C);
	// check_offset(select, leftSelect.deckUnused, 0x160);
	// check_offset(select, leftSelect.alwaysEight, 0x164);
	// check_offset(select, leftSelect.alwaysZero2, 0x168);
	// check_offset(select, leftSelect.palette, 0x170);
	// check_offset(select, leftSelect.paletteUnused, 0x174);
	// check_offset(select, rightSelect, 0x178);
	// check_offset(select, rightSelect.alwaysFive, 0x178);
	// check_offset(select, rightSelect.alwaysZero, 0x17C);
	// check_offset(select, rightSelect.keys, 0x180);
	// check_offset(select, rightSelect.deck, 0x184);
	// check_offset(select, rightSelect.deckUnused, 0x188);
	// check_offset(select, rightSelect.alwaysEight, 0x18C);
	// check_offset(select, rightSelect.alwaysZero2, 0x190);
	// check_offset(select, rightSelect.palette, 0x198);
	// check_offset(select, rightSelect.paletteUnused, 0x19C);
	check_offset(select, designBase3, 0x1A0);
	check_offset(select, leftSelectionStage, 0x22C0);
	check_offset(select, rightSelectionStage, 0x22C1);
	check_offset(select, leftRandomDeck, 0x22C2);
	check_offset(select, rightRandomDeck, 0x22C3);
	check_offset(select, offset_0x23C4, 0x22C4);
	check_offset(select, selectedStage, 0x2438);
	check_offset(select, selectedStageUnused, 0x243C);
	check_offset(select, offset_0x2440, 0x2440);
	check_offset(select, selectedMusic, 0x244C);
}

void testFrameData()
{
	SokuLib::FrameData *frameData = reinterpret_cast<SokuLib::FrameData *>(&frameData);

	check_offset(frameData, VTable, 0x0);
	check_offset(frameData, offset, 0x4);
	check_offset(frameData, offset.x, 0x4);
	check_offset(frameData, offset.y, 0x6);
	check_offset(frameData, offset_0x08, 0x8);
	check_offset(frameData, number, 0xA);
	check_offset(frameData, offset_0x0C, 0xC);
	check_offset(frameData, okuuCapeOffset, 0x10);
	check_offset(frameData, okuuCapeOffset.x, 0x10);
	check_offset(frameData, okuuCapeOffset.y, 0x12);
	check_offset(frameData, offset_0x014, 0x14);
	check_offset(frameData, offset_0x014, 0x14);
	check_offset(frameData, damage, 0x1C);
	check_offset(frameData, spiritDamage, 0x22);
	check_offset(frameData, offset_0x24, 0x24);
	check_offset(frameData, frameFlags, 0x4C);
	check_offset(frameData, attackFlags, 0x50);
	check_offset(frameData, collisionBox, 0x54);
	check_offset(frameData, offset_0x58, 0x58);
	assert_equal(sizeof(*frameData), 0xA8);

	// v2
	assert_equal(sizeof(SokuLib::v2::FrameData), 0x1C);
	assert_equal(offsetof(SokuLib::v2::FrameData, offset.x), 0x4);
	assert_equal(offsetof(SokuLib::v2::FrameData, offset.y), 0x6);
	assert_equal(sizeof(SokuLib::v2::CharacterFrameData), 0xA8);
	assert_equal(offsetof(SokuLib::v2::CharacterFrameData, damage), 0x1C);
	assert_equal(offsetof(SokuLib::v2::CharacterFrameData, spiritdamage), 0x22);
	assert_equal(offsetof(SokuLib::v2::CharacterFrameData, frameFlags), 0x4C);
	assert_equal(offsetof(SokuLib::v2::CharacterFrameData, attackFlags), 0x50);
	assert_equal(offsetof(SokuLib::v2::CharacterFrameData, collisionBox), 0x54);
}

void testDeckConstructMenu()
{
	SokuLib::ProfileDeckEdit *menu = reinterpret_cast<SokuLib::ProfileDeckEdit *>(&menu);

	check_offset(menu, vtable, 0x0);
	check_offset(menu, offset_0x04, 0x4);
	check_offset(menu, editedCharacter, 0x8);
	check_offset(menu, offset_0x0C, 0xC);
	check_offset(menu, editedDeck, 0x468);
	check_offset(menu, deck1, 0x46C);
	check_offset(menu, deck2, 0x478);
	check_offset(menu, deck3, 0x484);
	check_offset(menu, deck4, 0x490);
	check_offset(menu, unknownMap, 0x49C);
	check_offset(menu, offset_0x4A0, 0x4A0);
	check_offset(menu, displayedNumberOfCards, 0x4B1);
	check_offset(menu, offset_0x4B2, 0x4B2);
	check_offset(menu, selectedCardIndex, 0x4C0);
	check_offset(menu, offset_0x4C4, 0x4C4);
	check_offset(menu, panel, 0x4D4);
	check_offset(menu, offset_0x4D8, 0x4D8);
	check_offset(menu, selectedDeck, 0x4E8);
	check_offset(menu, offset_0x4EC, 0x4EC);
	check_offset(menu, cursorOnDeckChangeBox, 0x4F4);
	check_offset(menu, offset_0x4F5, 0x4F5);
	check_offset(menu, guideVector, 0x4F8);
}

void testEffectManager()
{
	using namespace SokuLib;

	assert_equal(sizeof(Deque<int>), 0x14);
	//assert_equal(sizeof(Deque<int>::iterator), 0xC);

	assert_equal(sizeof(v2::AnimationObject), 0x158);
	assert_equal(offsetof(v2::AnimationObject, position), 0xEC);
	assert_equal(offsetof(v2::AnimationObject, center), 0x108);
	assert_equal(offsetof(v2::AnimationObject, textures), 0x130);
	assert_equal(offsetof(v2::AnimationObject, frameState), 0x13C);
	assert_equal(offsetof(v2::AnimationObject, frameData), 0x150);

	assert_equal(sizeof(Sprite), 0x94);
	assert_equal(sizeof(SpriteEx), 0xE8);
	assert_equal(sizeof(v2::EffectObject), 0x178);
	assert_equal(sizeof(v2::InfoEffectObject), 0x178);
	assert_equal(sizeof(v2::SelectEffectObject), 0x170);
	assert_equal(sizeof(v2::WeatherEffectObject), 0x180);

	assert_equal(sizeof(HandleManager<void*>), 0x64);
	assert_equal(offsetof(HandleManager<void*>, deque), 0x4);
	assert_equal(offsetof(HandleManager<void*>, vector), 0x18);
	assert_equal(offsetof(HandleManager<void*>, usedIndexes), 0x28);
	assert_equal(offsetof(HandleManager<void*>, unusedIndexes), 0x38);
	assert_equal(offsetof(HandleManager<void*>, nextBase), 0x44);
	assert_equal(offsetof(HandleManager<void*>, mutex), 0x48);

	assert_equal(sizeof(HandleManagerEx<v2::EffectObject>), 0x50);
	assert_equal(offsetof(HandleManagerEx<v2::EffectObject>, vector), 0x4);
	assert_equal(offsetof(HandleManagerEx<v2::EffectObject>, usedIndexes), 0x14);
	assert_equal(offsetof(HandleManagerEx<v2::EffectObject>, unusedIndexes), 0x24);
	assert_equal(offsetof(HandleManagerEx<v2::EffectObject>, nextBase), 0x30);
	assert_equal(offsetof(HandleManagerEx<v2::EffectObject>, mutex), 0x34);
}

void testGameData()
{
	using namespace SokuLib;

	assert_equal(sizeof(v2::GameDataManager), 0x58);
	assert_equal(offsetof(v2::GameDataManager, createQueue), 0x00);
	assert_equal(offsetof(v2::GameDataManager, players), 0x28);
	assert_equal(offsetof(v2::GameDataManager, enabledPlayers), 0x38);
	assert_equal(offsetof(v2::GameDataManager, activePlayers), 0x3C);
	assert_equal(offsetof(v2::GameDataManager, destroyQueue), 0x4C);

	//assert_equal(sizeof(v2::SaveDataManager), unknown);
	assert_equal(offsetof(v2::SaveDataManager, enabledCharacters), 0x30);
	assert_equal(offsetof(v2::SaveDataManager, systemCards), 0x9C);
	assert_equal(offsetof(v2::SaveDataManager, characterCards), 0xA8);
}

int main()
{
	testFrameData();
	testCharacterManager();
	testSelectScene();
	testDeckConstructMenu();
	testEffectManager();
	testGameData();
	return 0;
}