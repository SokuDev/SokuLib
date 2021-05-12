//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_CHARACTER_HPP
#define SOKULIB_CHARACTER_HPP


#include <vector>
#include <string>
#include <windows.h>
#include "../Core/Stack.hpp"
#include "../Core/SokuAddresses.hpp"

namespace SokuLib
{
	enum Character : unsigned int {
		CHARACTER_REIMU,
		CHARACTER_MARISA,
		CHARACTER_SAKUYA,
		CHARACTER_ALICE,
		CHARACTER_PATCHOULI,
		CHARACTER_YOUMU,
		CHARACTER_REMILIA,
		CHARACTER_YUYUKO,
		CHARACTER_YUKARI,
		CHARACTER_SUIKA,
		CHARACTER_REISEN,
		CHARACTER_AYA,
		CHARACTER_KOMACHI,
		CHARACTER_IKU,
		CHARACTER_TENSHI,
		CHARACTER_SANAE,
		CHARACTER_CIRNO,
		CHARACTER_MEILING,
		CHARACTER_UTSUHO,
		CHARACTER_SUWAKO,
		CHARACTER_RANDOM
	};

	struct PlayerInfo {
		Character character;
		unsigned char padding1;
		unsigned char palette;
		unsigned char padding2;
		unsigned char deck;
		Dequeue<unsigned short> effectiveDeck;
	};

	extern std::vector<std::string> charactersName;

	extern Character &leftChar;
	extern Character &rightChar;
	extern PlayerInfo &leftPlayerInfo;
	extern PlayerInfo &rightPlayerInfo;
}


#endif //SOKULIB_CHARACTER_HPP
