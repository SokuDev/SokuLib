//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_CHARACTER_HPP
#define SOKULIB_CHARACTER_HPP


#include <vector>
#include <string>
#include <windows.h>
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

	extern std::vector<std::string> charactersName;

	// �L�����N�^���̎擾
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline LPCSTR GetCharacterAbbr(int id)
	{
		//TODO: Find this for version 1.10a
		return ((LPCSTR (__cdecl *)(int id))ADDR_GET_CHARACTER_ABBR)(id);
	}

	extern Character &leftChar;
	extern Character &rightChar;
}


#endif //SOKULIB_CHARACTER_HPP
