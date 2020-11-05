//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_MEMORY_HPP
#define SOKULIB_MEMORY_HPP


//From swrs.h (SWRSToys)

#include "SokuAddresses.hpp"

namespace SokuLib
{
	// new/delete
	template<typename T = void>
	__forceinline T *New(size_t size)
	{
		return reinterpret_cast<T *(__cdecl *)(size_t)>(ADDR_NEW_FUNCTION)(size);
	}

	__forceinline void Delete(void *p)
	{
		reinterpret_cast<void (__cdecl *)(void *)>(ADDR_DELETE_FUNCTION)(p);
	}
}


#endif //SOKULIB_MEMORY_HPP
