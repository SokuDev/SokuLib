//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_BATTLEMANAGER_HPP
#define SOKULIB_BATTLEMANAGER_HPP


#include "Cards.hpp"
#include "SokuAddresses.hpp"
#include "../Data/String.hpp"

namespace SokuLib
{
	struct Skill {
		unsigned char level : 7;
		bool notUsed : 1;
	};

	struct CharacterManager {
		// 0x000
		char unknown[0x560];
		// 0x560
		unsigned short grimoires;
		// 0x562
		char unknown2[0x11];
		// 0x573
		char score;
		// 0x574
		char UNKNOWN[8];
		// 0x57C
		mDeckInfo2 mDeckInfo2Obj;
		// 0x5FC
		char unknown3[0xC8];
		// 0x6C4
		Skill skillMap[16];
		// 0x6D4
		char unknown4[0x160];
		// 0x834
		unsigned short tenguFans;
		// 0x836
		char unknown5[0xA];
		// 0x840
		float sacrificialDolls;
		// 0x844
		float controlRod;
		// 0x848
		char unknown6[8];
		// 0x850
		unsigned short drops;
		// 0x852
	};

	struct BattleManager {
		char unknown[0xC];
		CharacterManager *leftCharacterManager;
		CharacterManager *rightCharacterManager;
	};

	//! @brief Changes the current battle mode
	extern void (__cdecl * const setBattleMode)(int comm, int sub);
	BattleManager &getBattleMgr();
	extern String &player1Profile;
	extern String &player2Profile;
}


#endif //SOKULIB_BATTLEMANAGER_HPP
