//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_KEY_HPP
#define SOKULIB_KEY_HPP


//From swrs.h (SWRSToys)

#include "SokuFct.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �V�X�e���L�[�����V���b�g
	__forceinline bool CheckKeyOneshot(int a, int b, int c, int d)
	{
		return reinterpret_cast<bool (*)(int, int, int, int)>(ADDR_CHECK_KEY_ONESHOT)(a, b, c, d);
	}
}


#endif //SOKULIB_KEY_HPP
