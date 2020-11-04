//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMANAGER_HPP
#define SOKULIB_BATTLEMANAGER_HPP


//From swrs.h (SWRSToys)

#include "SokuAddresses.hpp"

namespace SokuLib
{
	struct BattleManager;

	// �o�g�����[�h�ݒ�
	__forceinline void SetBattleMode(int comm, int sub)
	{
		return reinterpret_cast<void (__cdecl *)(int comm, int sub)>(ADDR_SET_BATTLE_MODE)(comm, sub);
	}

	// �o�g���}�l�[�W��
	// CBattleManager *
	__forceinline BattleManager *getBattleMgr()
	{
		return (*reinterpret_cast<BattleManager **>(ADDR_BATTLE_MANAGER));
	}
}


#endif //SOKULIB_BATTLEMANAGER_HPP
