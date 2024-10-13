//
// Created by DPhoenix on 20/09/2022.
//

#include "Player.hpp"
#include "TextureManager.hpp"
#include "VTables.hpp"
#include <shlwapi.h>

#define IMPL_PLAYER_VIRTUALS(CLS, VTB) \
	void CLS::setActionSequence(short a0, short a1) \
		{ return (this->*union_cast<void(CLS::*)(short, short)>(VTB[1]))(a0, a1); } \
	bool CLS::setAction(short a0) \
		{ return (this->*union_cast<bool(CLS::*)(short)>(VTB[2]))(a0); } \
	void CLS::setSequence(short a0) \
		{ return (this->*union_cast<void(CLS::*)(short)>(VTB[3]))(a0); } \
	void CLS::resetSequence() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[4]))(); } \
	bool CLS::nextSequence() \
		{ return (this->*union_cast<bool(CLS::*)()>(VTB[5]))(); } \
	void CLS::prevSequence() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[6]))(); } \
	void CLS::setPose(short a0) \
		{ return (this->*union_cast<void(CLS::*)(short)>(VTB[7]))(a0); } \
	bool CLS::nextPose() \
		{ return (this->*union_cast<bool(CLS::*)()>(VTB[8]))(); } \
	void CLS::prevPose() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[9]))(); } \
	void CLS::update() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[10]))(); } \
	void CLS::render() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[11]))(); } \
	void CLS::render2() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[12]))(); } \
	void CLS::applyTransform() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[13]))(); } \
	void CLS::onRenderEnd() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[14]))(); } \
	void CLS::initializeAction() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[15]))(); } \
	void CLS::updatePhysics() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[16]))(); } \
	void CLS::initialize() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[17]))(); } \
	bool CLS::VUnknown48() \
		{ return (this->*union_cast<bool(CLS::*)()>(VTB[18]))(); } \
	bool CLS::VUnknown4C(int a0) \
		{ return (this->*union_cast<bool(CLS::*)(int)>(VTB[19]))(a0); } \
	void CLS::handleInputs() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[20]))(); } \
	void CLS::checkAllMotionInputs() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[21]))(); } \
	void CLS::VUnknown58() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[22]))(); } \
	void CLS::VUnknown5C() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[23]))(); } \
	bool CLS::VUnknown60(int a) \
		{ return (this->*union_cast<bool(CLS::*)(int)>(VTB[24]))(a); }

namespace SokuLib {
	const int _vtable_info<v2::PlayerReimu>::baseAddr       = 0x0085bf4c;
	const int _vtable_info<v2::PlayerMarisa>::baseAddr      = 0x0085c37c;
	const int _vtable_info<v2::PlayerSakuya>::baseAddr      = 0x0085c704;
	const int _vtable_info<v2::PlayerAlice>::baseAddr       = 0x0085c9f4;
	const int _vtable_info<v2::PlayerPatchouli>::baseAddr   = 0x0085cd2c;
	const int _vtable_info<v2::PlayerYoumu>::baseAddr       = 0x0085cfdc;
	const int _vtable_info<v2::PlayerRemilia>::baseAddr     = 0x0085d284;
	const int _vtable_info<v2::PlayerYuyuko>::baseAddr      = 0x0085d524;
	const int _vtable_info<v2::PlayerYukari>::baseAddr      = 0x0085d7bc;
	const int _vtable_info<v2::PlayerSuika>::baseAddr       = 0x0085da84;
	const int _vtable_info<v2::PlayerUdonge>::baseAddr      = 0x0085dd5c;
	const int _vtable_info<v2::PlayerAya>::baseAddr         = 0x0085e23c;
	const int _vtable_info<v2::PlayerKomachi>::baseAddr     = 0x0085dfac;
	const int _vtable_info<v2::PlayerIku>::baseAddr         = 0x0085e4a4;
	const int _vtable_info<v2::PlayerTenshi>::baseAddr      = 0x0085e71c;
	const int _vtable_info<v2::PlayerSanae>::baseAddr       = 0x0085efec;
	const int _vtable_info<v2::PlayerChirno>::baseAddr      = 0x0085eab4;
	const int _vtable_info<v2::PlayerMeirin>::baseAddr      = 0x0085ed3c;
	const int _vtable_info<v2::PlayerUtsuho>::baseAddr      = 0x0085f49c;
	const int _vtable_info<v2::PlayerSuwako>::baseAddr      = 0x0085f2bc;
	const int _vtable_info<v2::PlayerNamazu>::baseAddr      = 0x0085f824;

static void pathAppendA(char* buffer, const char* str) {
	auto blen = strlen(buffer);
	auto slen = strlen(str);
	if (blen+slen+1 > MAX_PATH) return;
	if (blen) buffer[blen] = '\\';
	strcpy(buffer+blen+1, str);
}

namespace v2 {
	auto& commonPatternData = *reinterpret_cast<Map<int, CharacterSequenceData*>*>(0x89aae8);
	auto& commonTextures = *reinterpret_cast<Vector<int>*>(0x89aac4);

	Player::Player(const PlayerInfo& playerInfo) : keyManager(*playerInfo.keyManager) {
		gameData.owner = gameData.ally = this;

		gameData.patternMap = SokuLib::New<Map<int, CharacterSequenceData*>>(1, commonPatternData);
		textures = SokuLib::New<Vector<int>>(1, commonTextures);
		gameData.soundTable = SokuLib::New<int>(400);
		memset(gameData.soundTable, 0, 400 * 4);

		characterIndex = playerInfo.character;
		teamId = playerInfo.isRight;
		paletteId = playerInfo.palette;
		deckInfo.original = playerInfo.effectiveDeck;
		deckInfo.queue = playerInfo.effectiveDeck;
		if (playerInfo.keyManager)
			inputData.unknown7CC = playerInfo.padding2;
		else
			inputData.unknown7CC = 0;
	}

	Player::~Player() {
		for (int i = commonTextures.size(); i < textures->size(); ++i) SokuLib::textureMgr.remove(textures->at(i));
		for (int i : spellBgTextures) SokuLib::textureMgr.remove(i);
		if (portraitTexId) SokuLib::textureMgr.remove(portraitTexId);
		for (int i = 0; i < 256; ++i) ((TextureManager *)0x89F9F8)->removeSound(gameData.soundTable[i]);
		SokuLib::Delete(gameData.soundTable);
		if (objectList) delete objectList; // has virtual destructor so we use delete
		SokuLib::Delete(textures);
		SokuLib::Delete(gameData.patternMap);
		for (int i : deckInfo.textures) SokuLib::textureMgr.remove(i);
		if (stand.texId) SokuLib::textureMgr.remove(stand.texId);
	}

	SokuLib::CardInfo* Player::DeckInfo::cardLookup(unsigned short id)
		{ return (this->*union_cast<SokuLib::CardInfo* (Player::DeckInfo::*)(unsigned short)>(0x436620))(id); }

	void Player::loadResources() { return (this->*union_cast<void(Player::*)()>(0x46c0b0))(); }
	bool Player::updateGroundMovement(float value) { return (this->*union_cast<bool(Player::*)(float)>(0x487740))(value); }
	bool Player::updateAirMovement(float a0, float a1) { return (this->*union_cast<bool(Player::*)(float,float)>(0x4877C0))(a0, a1); }
	void Player::addCardMeter(int value) { return (this->*union_cast<void(Player::*)(int)>(0x487870))(value); }
	void Player::Unknown487C20() { return (this->*union_cast<void(Player::*)()>(0x487C20))(); }
	void Player::playSpellBackground(int a0, int a1) { return (this->*union_cast<void(Player::*)(int, int)>(0x46b370))(a0, a1); }
	bool Player::applyGroundMechanics() { return (this->*union_cast<bool(Player::*)()>(0x487ca0))(); }
	bool Player::applyAirMechanics() { return (this->*union_cast<bool(Player::*)()>(0x487ea0))(); }
	void Player::playSFX(int id) { return (this->*union_cast<void(Player::*)(int)>(0x464980))(id); }
	void Player::consumeSpirit(int cost, int delay) { return (this->*union_cast<void(Player::*)(int, int)>(0x47a9e0))(cost, delay); }
	void Player::consumeCard(int a0, int a1, int a2) { return (this->*union_cast<void(Player::*)(int, int, int)>(0x469c70))(a0, a1, a2); }
	void Player::eventSkillUse() { return (this->*union_cast<void(Player::*)()>(0x483ce0))(); }
	void Player::eventSpellUse() { return (this->*union_cast<void(Player::*)()>(0x483d60))(); }
	void Player::eventWeatherCycle() { return (this->*union_cast<void(Player::*)()>(0x483db0))(); }
	bool Player::handleCardSwitch() { return (this->*union_cast<bool(Player::*)()>(0x487890))(); }
	void Player::FUN_0046d950() { return (this->*union_cast<void(Player::*)()>(0x46d950))(); }
	bool Player::handleHJ() { return (this->*union_cast<bool(Player::*)()>(0x487900))(); }
	bool Player::handleGroundBE() { return (this->*union_cast<bool(Player::*)()>(0x487990))(); }
	bool Player::handleGroundDash(int moveLock, int hjCancelable) { return (this->*union_cast<bool(Player::*)(int, int)>(0x48a220))(moveLock, hjCancelable); }
	bool Player::handleHJInput(int moveLock, int hjCancelable) { return (this->*union_cast<bool(Player::*)(int, int)>(0x489e90))(moveLock, hjCancelable); }
	bool Player::handleAirBE() { return (this->*union_cast<bool(Player::*)()>(0x487ab0))(); }
	bool Player::handleFwdAirDash(int moveLock, int hjCancelable, int allowedAirMoves, int airDashCancelSeq) { return (this->*union_cast<bool(Player::*)(int, int, int, int)>(0x48a380))(moveLock, hjCancelable, allowedAirMoves, airDashCancelSeq); }
	bool Player::handleBackAirDash(int moveLock, int hjCancelable, int allowedAirMoves, int airDashCancelSeq) { return (this->*union_cast<bool(Player::*)(int, int, int, int)>(0x48a470))(moveLock, hjCancelable, allowedAirMoves, airDashCancelSeq); }
	bool Player::handleNormalFlight(int moveLock, int hjCancelable, int allowedAirMoves) { return (this->*union_cast<bool(Player::*)(int, int, int)>(0x48a560))(moveLock, hjCancelable, allowedAirMoves); }
	void Player::initializeAction() { (this->*union_cast<void(Player::*)()>(0x48b210))(); }
	void Player::applyTransform() { return (this->*union_cast<void(Player::*)()>(0x46A510))(); }
	void Player::updatePhysics() { return (this->*union_cast<void(Player::*)()>(0x487EF0))(); }
	void Player::initialize() { return (this->*union_cast<void(Player::*)()>(0x48B000))(); }
	bool Player::VUnknown48() { return (this->*union_cast<bool(Player::*)()>(0x4636D0))(); }
	bool Player::VUnknown4C(int a) { return (this->*union_cast<bool(Player::*)(int)>(0x487220))(a); }
	void Player::checkAllMotionInputs() { return (this->*union_cast<void(Player::*)()>(0x487020))(); }
	void Player::updateDefaultBehavior() { return (this->*union_cast<void(Player::*)()>(0x483F40))(); }
	bool Player::isGrounded() { return (this->*union_cast<bool(Player::*)()>(0x463530))(); }
	bool Player::canActivateCard(int slot) { return (this->*union_cast<bool(Player::*)(int)>(0x468E80))(slot); }
	bool Player::useSystemCard(int moveLock) { return (this->*union_cast<bool(Player::*)(int)>(0x48A700))(moveLock); }
	void Player::useSpellCard(int id, short action) { return (this->*union_cast<void(Player::*)(int, short)>(0x487B60))(id, action); }
	void Player::useSkill(int id, short action) { return (this->*union_cast<void(Player::*)(int, short)>(0x487BA0))(id, action); }
	unsigned short Player::getMoveLock(unsigned short action) { return (this->*union_cast<unsigned short(Player::*)(unsigned short)>(0x489610))(action); }
	void Player::onSkillUpgrade() { return (this->*union_cast<void(Player::*)()>(0x489660))(); }
	SokuLib::v2::GameObject *Player::createObject(short action, float x, float y, char direction, char layer, float *extraData, unsigned int extraDataSize) {
		// Mimics 0x46EB30
		return this->objectList->createObject(nullptr, this, action, x, y, direction, layer, extraData, extraDataSize);
	}

	IMPL_PLAYER_VIRTUALS(PlayerReimu, ((void** const)_vtable_info<v2::PlayerReimu>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerMarisa, ((void** const)_vtable_info<v2::PlayerMarisa>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerSakuya, ((void** const)_vtable_info<v2::PlayerSakuya>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerAlice, ((void** const)_vtable_info<v2::PlayerAlice>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerPatchouli, ((void** const)_vtable_info<v2::PlayerPatchouli>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerYoumu, ((void** const)_vtable_info<v2::PlayerYoumu>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerRemilia, ((void** const)_vtable_info<v2::PlayerRemilia>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerYuyuko, ((void** const)_vtable_info<v2::PlayerYuyuko>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerYukari, ((void** const)_vtable_info<v2::PlayerYukari>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerSuika, ((void** const)_vtable_info<v2::PlayerSuika>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerUdonge, ((void** const)_vtable_info<v2::PlayerUdonge>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerAya, ((void** const)_vtable_info<v2::PlayerAya>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerKomachi, ((void** const)_vtable_info<v2::PlayerKomachi>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerIku, ((void** const)_vtable_info<v2::PlayerIku>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerTenshi, ((void** const)_vtable_info<v2::PlayerTenshi>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerSanae, ((void** const)_vtable_info<v2::PlayerSanae>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerChirno, ((void** const)_vtable_info<v2::PlayerChirno>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerMeirin, ((void** const)_vtable_info<v2::PlayerMeirin>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerUtsuho, ((void** const)_vtable_info<v2::PlayerUtsuho>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerSuwako, ((void** const)_vtable_info<v2::PlayerSuwako>::baseAddr))
	IMPL_PLAYER_VIRTUALS(PlayerNamazu, ((void** const)_vtable_info<v2::PlayerNamazu>::baseAddr))

	PlayerReimu::PlayerReimu(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Reimu(this); }
	PlayerMarisa::PlayerMarisa(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Marisa(this); }
	PlayerSakuya::PlayerSakuya(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Sakuya(this); }
	PlayerAlice::PlayerAlice(const PlayerInfo& info)
		: Player(info) { unknown138 = -6; objectList = new GameObjectList_Alice(this); }
	PlayerPatchouli::PlayerPatchouli(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Patchouli(this); }
	PlayerRemilia::PlayerRemilia(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Remilia(this); }
	PlayerYuyuko::PlayerYuyuko(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Yuyuko(this); }
	PlayerYukari::PlayerYukari(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Yukari(this); }
	PlayerSuika::PlayerSuika(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Suika(this); }
	PlayerUdonge::PlayerUdonge(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Udonge(this); }
	PlayerAya::PlayerAya(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Aya(this); }
	PlayerKomachi::PlayerKomachi(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Komachi(this); }
	PlayerIku::PlayerIku(const PlayerInfo& info)
		: Player(info) { unknown138 = -6; objectList = new GameObjectList_Iku(this); }
	PlayerTenshi::PlayerTenshi(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Tenshi(this); }
	PlayerSanae::PlayerSanae(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Sanae(this); }
	PlayerChirno::PlayerChirno(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Chirno(this); }
	PlayerMeirin::PlayerMeirin(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Meirin(this); }
	PlayerSuwako::PlayerSuwako(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Suwako(this); }
	PlayerNamazu::PlayerNamazu(const PlayerInfo& info)
		: Player(info) { objectList = new GameObjectList_Namazu(this); }

	PlayerYoumu::PlayerYoumu(const PlayerInfo& info) : Player(info) {
		memset(&unknown890[0xd0], 0, 16); // [0x8c0-0x8d0] = 0
		objectList = new GameObjectList_Youmu(this);
	}

	PlayerUtsuho::PlayerUtsuho(const PlayerInfo& info) : Player(info) {
		int texId = 0;
		((int*)this->unknown890)[1] = *SokuLib::textureMgr.loadTexture(&texId, (const char*)0x85f5e4, 0, 0);
		this->unknown890[0] = 0;
		char* const buffer = *(char**)0x8a0d08;
		GetCurrentDirectoryA(MAX_PATH, buffer);
		pathAppendA(buffer, (char*)0x858408); // "configex123.ini" // TODO better handling of shlwapi
		if (GetPrivateProfileIntA((char*)0x85a2e4, (char*)0x85a2e8, -1, buffer) == 1) { // "etc", "limit"
			this->unknown890[0] = 1;
		}
		objectList = new GameObjectList_Utsuho(this);
	}

	PlayerYoumu::~PlayerYoumu() {
		// unknown object destructor
		reinterpret_cast<void (__fastcall*)(void*)>(0x433a50)(&unknown890[0x2c]);
	}

	PlayerUtsuho::~PlayerUtsuho() {
		SokuLib::textureMgr.remove(((int*)this->unknown890)[1]); // remove texture in +0x894
	}
}
}
