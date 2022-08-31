//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMODE_HPP
#define SOKULIB_BATTLEMODE_HPP


#include <vector>
#include <string>
#include <array>
#include "SokuAddresses.hpp"

namespace SokuLib
{
	enum BattleMode : unsigned char {
		BATTLE_MODE_STORY,
		BATTLE_MODE_ARCADE,
		BATTLE_MODE_VSCOM,
		BATTLE_MODE_VSPLAYER,
		BATTLE_MODE_VSCLIENT,
		BATTLE_MODE_VSSERVER,
		BATTLE_MODE_VSWATCH,
		BATTLE_MODE_TIME_TRIAL,
		BATTLE_MODE_PRACTICE
	};

	enum BattleSubMode : unsigned char {
		BATTLE_SUBMODE_PLAYING1,
		BATTLE_SUBMODE_PLAYING2,
		BATTLE_SUBMODE_REPLAY
	};

	// ���[�h
	// int
	extern int &menuMode;
	extern BattleMode &mainMode;
	extern BattleSubMode &subMode;
	extern std::vector<std::array<std::string, 3>> modeNames;
}


#endif //SOKULIB_BATTLEMODE_HPP
