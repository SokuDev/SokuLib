//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMANAGER_HPP
#define SOKULIB_BATTLEMANAGER_HPP


#include "SokuAddresses.hpp"
#include "CharacterManager.hpp"
#include "BattleMode.hpp"
#include "String.hpp"

namespace SokuLib
{
    //! @brief Represents the state of the battle between characters, but not the state of the battle scene itself.
 	struct BattleManager {
		// 0x000
		char unknown[0xC];
		// 0x00C
		CharacterManager &leftCharacterManager;
		// 0x010
		CharacterManager &rightCharacterManager;
		// 0x014
		char offset_0x014[0x8F0];
		// 0x904
		char currentRound;
	};

    //! @brief Changes the current battle mode
	extern void (__cdecl * const setBattleMode)(BattleMode comm, BattleSubMode sub);
	BattleManager &getBattleMgr();
}


#endif //SOKULIB_BATTLEMANAGER_HPP
