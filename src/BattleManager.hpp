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
	struct BattleManager {
		struct BattleManager_VTABLE *vtable;
		// 0x004
		char unknown[0x8];
		// 0x00C
		CharacterManager &leftCharacterManager;
		// 0x010
		CharacterManager &rightCharacterManager;
		// 0x014
		char offset_0x014[0x74];
		// 0x088
		char matchState;
		// 0x089
		char offset_0x089[0x87B];
		// 0x904
		char currentRound;
	};

	//! @brief Changes the current battle mode
	extern void (__cdecl * const setBattleMode)(BattleMode comm, BattleSubMode sub);
	BattleManager &getBattleMgr();
}


#endif //SOKULIB_BATTLEMANAGER_HPP
