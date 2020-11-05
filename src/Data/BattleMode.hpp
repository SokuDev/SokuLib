//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMODE_HPP
#define SOKULIB_BATTLEMODE_HPP

//From swrs.h (SWRSToys)

#include <vector>
#include <string>
#include <array>
#include "../Core/SokuAddresses.hpp"

namespace SokuLib
{
	#pragma pack(push, 1)
	enum BattleMode {
		BATTLE_MODE_STORY,
		BATTLE_MODE_ARCADE,
		BATTLE_MODE_VSCOM,
		BATTLE_MODE_VSPLAYER,
		BATTLE_MODE_VSCLIENT,
		BATTLE_MODE_VSSERVER,
		BATTLE_MODE_VSWATCH,
		BATTLE_MODE_PRACTICE = 8
	};

	enum BattleSubMode {
		BATTLE_SUBMODE_PLAYING1,
		BATTLE_SUBMODE_PLAYING2,
		BATTLE_SUBMODE_REPLAY
	};
	#pragma pack(pop)

	// ���[�h
	// int
	__forceinline BattleMode getMainMode()
	{
		return static_cast<BattleMode>(*reinterpret_cast<char *>(ADDR_COMM_MODE));
	}

	__forceinline BattleSubMode getSubMode()
	{
		return static_cast<BattleSubMode>(*reinterpret_cast<char *>(ADDR_SUB_MODE));
	}

	__forceinline int getMenuMode()
	{
		return (*reinterpret_cast<int *>(ADDR_MENU_MODE));
	}

	//From me
	extern std::vector<std::array<std::string, 3>> modeNames;
}

#endif //SOKULIB_BATTLEMODE_HPP
