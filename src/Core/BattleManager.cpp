//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"
#include "BattleManager.hpp"

namespace SokuLib
{
	BattleManager &getBattleMgr()
	{
		return **reinterpret_cast<BattleManager **>(ADDR_BATTLE_MANAGER);
	}

	void (__cdecl * const setBattleMode)(int comm, int sub) = reinterpret_cast<void (__cdecl *)(int, int)>(ADDR_SET_BATTLE_MODE);
	const String &player1Profile = *reinterpret_cast<String *>(ADDR_PLAYER1_PROFILE_STR);
	const String &player2Profile = *reinterpret_cast<String *>(ADDR_PLAYER2_PROFILE_STR);
}