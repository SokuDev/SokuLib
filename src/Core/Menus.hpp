//
// Created by Gegel85 on 05/11/2020.
//

#ifndef SOKULIB_MENUS_HPP
#define SOKULIB_MENUS_HPP

#include "SokuAddresses.hpp"

namespace SokuLib
{
	// Made by Slen https://github.com/S-len
	__forceinline void activateMenu(void *addr)
	{
		((void (*)(void *))ADDR_ACTIVATE_MENU)(addr);
	}
}

#include "Menus/ConnectMenu.hpp"

#endif //SOKULIB_MENUS_HPP
