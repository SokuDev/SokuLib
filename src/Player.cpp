//
// Created by DPhoenix on 20/09/2022.
//

#include "Player.hpp"
#include "TextureManager.hpp"

namespace SokuLib {
namespace v2 {
	auto& commonPatternData = *reinterpret_cast<Map<int, CharacterSequenceData*>*>(0x89aae8);
	auto& commonTextures = *reinterpret_cast<Vector<int>*>(0x89aac4);

	Player::Player(const PlayerInfo& playerInfo) : keyManager(*playerInfo.keyManager) {
		gameData.owner = gameData.owner2 = this;

		gameData.patternMap = SokuLib::New<Map<int, CharacterSequenceData*>>(1, commonPatternData);
		textures = SokuLib::New<Vector<int>>(1, commonTextures);
		gameData.soundTable = SokuLib::New<int>(400);
		memset(gameData.soundTable, 0, 400);

		characterIndex = playerInfo.character;
		playerIndex = playerInfo.isRight;
		palette = playerInfo.palette;
		deckData.original = playerInfo.effectiveDeck;
		deckData.queue = playerInfo.effectiveDeck;
		if (playerInfo.keyManager) inputData.unknown7CC = playerInfo.padding2;
		else inputData.unknown7CC = 0;
	}

	Player::~Player() {
		for (int i = commonTextures.size(); i < textures->size(); ++i) SokuLib::textureMgr.remove(textures->at(i));
		for (int i : unknown72C) SokuLib::textureMgr.remove(i);
		if (portraitTexId) SokuLib::textureMgr.remove(portraitTexId);
		for (int i = 0; i < 256; ++i) SokuLib::textureMgr.removeSound(gameData.soundTable[i]);
		SokuLib::Delete(gameData.soundTable);
		if (objectList) delete objectList; // has virtual destructor so we use delete
		SokuLib::Delete(textures);
		SokuLib::Delete(gameData.patternMap);
		for (int i : deckData.textures) SokuLib::textureMgr.remove(i);
		if (stand.texId) SokuLib::textureMgr.remove(stand.texId);
	}

	SokuLib::CardInfo* Player::DeckInfo::cardLookup(unsigned short id)
		{ return (this->*union_cast<SokuLib::CardInfo* (Player::DeckInfo::*)(unsigned short)>(0x436620))(id); }
}}