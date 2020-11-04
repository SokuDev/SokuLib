//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_MISC_HPP
#define SOKULIB_MISC_HPP


//From swrs.h (SWRSToys)

#include "SokuAddresses.hpp"

namespace SokuLib
{
	// argc/argv
	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline int __argc()
	{
		return *(int*)ADDR_ARGC;
	}

		#ifdef SOKU_VER_110a
	template<typename T = void>
		#endif
	__forceinline char **__argv()
	{
		return *(char***)ADDR_ARGV;
	}
}


#endif //SOKULIB_MISC_HPP
