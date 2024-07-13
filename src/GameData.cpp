//
// Created by DPhoenix on 20/06/2023.
//

#include "GameData.hpp"

namespace SokuLib {
	float (&v2::groundHeight)[1280] = *(float (*)[1280])0x8971D8;

	v2::GameDataManager*& v2::GameDataManager::instance = *reinterpret_cast<GameDataManager**>(SokuLib::ADDR_GAME_DATA_MANAGER);
	v2::SaveDataManager& v2::SaveDataManager::instance = *reinterpret_cast<SaveDataManager*>(0x899f60);
	void v2::SaveDataManager::enableStage(int stageId) { return (this->*union_cast<void (v2::SaveDataManager::*)(int)>(0x430c60))(stageId); }
	void v2::SaveDataManager::enableCharacter(int characterId) { return (this->*union_cast<void (v2::SaveDataManager::*)(int)>(0x42ee80))(characterId); }
	void v2::SaveDataManager::enableBgm(const char* filename) { return (this->*union_cast<void (v2::SaveDataManager::*)(const char*)>(0x430ca0))(filename); }
	bool v2::SaveDataManager::loadData() { return (this->*union_cast<bool (v2::SaveDataManager::*)()>(0x433330))(); };
	void v2::SaveDataManager::saveData() { return (this->*union_cast<void (v2::SaveDataManager::*)()>(0x42fa10))(); };
	void v2::SaveDataManager::saveScenarioResult(int characterId, unsigned char score)
		{ return (this->*union_cast<void (v2::SaveDataManager::*)(int, unsigned char)>(0x431c20))(characterId, score); }
}
