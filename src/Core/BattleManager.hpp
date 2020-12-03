//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMANAGER_HPP
#define SOKULIB_BATTLEMANAGER_HPP


#include "SokuAddresses.hpp"
#include "../Data/String.hpp"

namespace SokuLib
{
	struct CharacterManager {
		char unknown[0x573];
		char score;
	};

	struct BattleManager {
		char unknown[0xC];
		CharacterManager *leftCharacterManager;
		CharacterManager *rightCharacterManager;
	};

	//! @brief Changes the current battle mode
	extern void (__cdecl * const setBattleMode)(int comm, int sub);
	BattleManager &getBattleMgr();
	extern const String &player1Profile;
	extern const String &player2Profile;
}


#endif //SOKULIB_BATTLEMANAGER_HPP
