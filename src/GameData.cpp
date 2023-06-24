//
// Created by DPhoenix on 20/06/2023.
//

#include "GameData.hpp"

using namespace SokuLib;

v2::GameDataManager*& v2::GameDataManager::instance = *reinterpret_cast<GameDataManager**>(SokuLib::ADDR_GAME_DATA_MANAGER);
v2::SaveDataManager& v2::SaveDataManager::instance = *reinterpret_cast<SaveDataManager*>(0x899f60);
void v2::SaveDataManager::enableCharacter(int characterId) { return (this->*union_cast<void (v2::SaveDataManager::*)(int)>(0x42ee80))(characterId); }
bool v2::SaveDataManager::loadData() { return (this->*union_cast<bool (v2::SaveDataManager::*)()>(0x433330))(); };
void v2::SaveDataManager::saveData() { return (this->*union_cast<void (v2::SaveDataManager::*)()>(0x42fa10))(); };
