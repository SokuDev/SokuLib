//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_VECTOR_HPP
#define SOKULIB_VECTOR_HPP


#include "SokuAddresses.hpp"
#include "SokuFct.hpp"

namespace SokuLib
{
	// �x�N�^�I�u�W�F�N�g
	#ifndef SOKU_VER_110
	template<typename T=void>
	#endif
	__forceinline void Vector_Create(void *t, size_t s, size_t d, int i, int k)
	{
		//TODO: Find this for version 1.10a
		return ((void (__stdcall *)(void *, size_t, size_t, int, int))ADDR_VECTOR_CREATE)(t, s, d, i, k);
	}

	#ifndef SOKU_VER_110
	template<typename T=void>
	#endif
	__forceinline void Vector_Destruct(void *t, size_t s, size_t d, int i)
	{
		//TODO: Find this for version 1.10a
		return ((void (__stdcall *)(void *, size_t, size_t, int))ADDR_VECTOR_DESTRUCT)(t, s, d, i);
	}
}


#endif //SOKULIB_VECTOR_HPP
