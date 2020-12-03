//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_MISC_HPP
#define SOKULIB_MISC_HPP


#include "SokuAddresses.hpp"

namespace SokuLib
{
	// argc/argv
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline int __argc()
	{
		return *(int*)ADDR_ARGC;
	}

	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline char **__argv()
	{
		return *(char***)ADDR_ARGV;
	}
}


#endif //SOKULIB_MISC_HPP
