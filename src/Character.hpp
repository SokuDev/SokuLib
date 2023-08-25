//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_CHARACTER_HPP
#define SOKULIB_CHARACTER_HPP


#include <vector>
#include <string>
#include <windows.h>
#include "Deque.hpp"
#include "InputManager.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	enum Character : unsigned int {
		/* 0  */ CHARACTER_REIMU,
		/* 1  */ CHARACTER_MARISA,
		/* 2  */ CHARACTER_SAKUYA,
		/* 3  */ CHARACTER_ALICE,
		/* 4  */ CHARACTER_PATCHOULI,
		/* 5  */ CHARACTER_YOUMU,
		/* 6  */ CHARACTER_REMILIA,
		/* 7  */ CHARACTER_YUYUKO,
		/* 8  */ CHARACTER_YUKARI,
		/* 9  */ CHARACTER_SUIKA,
		/* 10 */ CHARACTER_REISEN,
		/* 10 */ CHARACTER_UDONGE = CHARACTER_REISEN,
		/* 11 */ CHARACTER_AYA,
		/* 12 */ CHARACTER_KOMACHI,
		/* 13 */ CHARACTER_IKU,
		/* 14 */ CHARACTER_TENSHI,
		/* 15 */ CHARACTER_SANAE,
		/* 16 */ CHARACTER_CIRNO,
		/* 16 */ CHARACTER_CHIRNO = CHARACTER_CIRNO,
		/* 17 */ CHARACTER_MEILING,
		/* 17 */ CHARACTER_MEIRIN = CHARACTER_MEILING,
		/* 18 */ CHARACTER_UTSUHO,
		/* 19 */ CHARACTER_SUWAKO,
		/* 20 */ CHARACTER_RANDOM,
		/* 21 */ CHARACTER_NAMAZU,
		//Soku2 Characters
		/* 22 */ CHARACTER_MOMIJI,
		/* 23 */ CHARACTER_CLOWNPIECE,
		/* 24 */ CHARACTER_FLANDRE,
		/* 25 */ CHARACTER_ORIN,
		/* 26 */ CHARACTER_YUUKA,
		/* 27 */ CHARACTER_KAGUYA,
		/* 28 */ CHARACTER_MOKOU,
		/* 29 */ CHARACTER_MIMA,
		/* 30 */ CHARACTER_SHOU,
		/* 31 */ CHARACTER_MURASA,
		/* 32 */ CHARACTER_SEKIBANKI,
		/* 33 */ CHARACTER_SATORI,
		/* 34 */ CHARACTER_RAN
	};

	struct PlayerInfo {
		Character character;
		unsigned char isRight;
		unsigned char palette;
		unsigned char padding2;
		unsigned char deck;
		Deque<unsigned short> effectiveDeck;
		KeyManager *keyManager;
	};

	struct GameStartParams {
		char offset_0x00[4];
		unsigned char stageId;
		unsigned char musicId;
		char offset_0x06[2];
		PlayerInfo leftPlayerInfo;
		PlayerInfo rightPlayerInfo;
		unsigned int randomSeed;
	};

	extern std::vector<std::string> charactersName;

	extern Character &leftChar;
	extern Character &rightChar;
	extern PlayerInfo &leftPlayerInfo;
	extern PlayerInfo &rightPlayerInfo;
	extern GameStartParams &gameParams;
}


#endif //SOKULIB_CHARACTER_HPP
