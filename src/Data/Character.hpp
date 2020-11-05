//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_CHARACTER_HPP
#define SOKULIB_CHARACTER_HPP


#include <vector>
#include <string>
#include <windows.h>
#include "../Core/SokuAddresses.hpp"

//From me

namespace SokuLib
{
	enum Character {
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

	//From swrs.h (SWRSToys)
	// �L�����N�^���̎擾
	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline LPCSTR GetCharacterAbbr(int id)
	{
		return ((LPCSTR (__cdecl *)(int id))ADDR_GET_CHARACTER_ABBR)(id);
	}

	//From swrs.h (SWRSToys)
	// �L�����N�^ID
	// int
	__forceinline Character getLeftChar()
	{
		return *reinterpret_cast<Character *>(ADDR_LCHARID);
	}

	//From swrs.h (SWRSToys)
	__forceinline Character getRightChar()
	{
		return *reinterpret_cast<Character *>(ADDR_RCHARID);
	}
}


#endif //SOKULIB_CHARACTER_HPP
