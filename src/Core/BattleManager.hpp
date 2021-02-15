//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMANAGER_HPP
#define SOKULIB_BATTLEMANAGER_HPP


#include "SokuAddresses.hpp"
#include "../Data/String.hpp"
#include "CharacterManager.hpp"

namespace SokuLib
{
	struct BattleManager {
		char unknown[0xC];
		CharacterManager &leftCharacterManager;
		CharacterManager &rightCharacterManager;
	};

	//! @brief Changes the current battle mode
	extern void (__cdecl * const setBattleMode)(int comm, int sub);
	BattleManager &getBattleMgr();
	extern String &player1Profile;
	extern String &player2Profile;
}


#endif //SOKULIB_BATTLEMANAGER_HPP
