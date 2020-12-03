//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_MATH_HPP
#define SOKULIB_MATH_HPP


//From swrs.h (SWRSToys)

#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �p�xcos
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline float DegreeCosine(int deg)
	{
		//TODO: Find this for version 1.10a
		return ((float (__cdecl *)(int deg))ADDR_DEGREE_COSINE)(deg);
	}
}


#endif //SOKULIB_MATH_HPP
