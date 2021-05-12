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

	void (__cdecl * const setBattleMode)(BattleMode comm, BattleSubMode sub) = reinterpret_cast<void (__cdecl *)(BattleMode, BattleSubMode)>(ADDR_SET_BATTLE_MODE);
}