//
// Created by Gegel85 on 05/11/2020.
//

#ifndef SOKULIB_MENUS_HPP
#define SOKULIB_MENUS_HPP


#include <string>

namespace SokuLib
{
	enum Menu {
		MENU_NONE,
		MENU_CONNECT,
		MENU_REPLAY,
		MENU_MUSICROOM,
		MENU_RESULT,
		MENU_PROFILE,
		MENU_CONFIG,
		MENU_DECK_CONSTRUCTION,
		MENU_KEYS,
		MENU_COUNT
	};

	extern void (* const activateMenu)(void *addr);

	template<typename T>
	//! @brief Gives the currently used menu object.
	//! @tparam T The type of the expected object.
	//! @warning Unsafe if not currently in a title screen submenu.
	//! @return The current menu object.
	T *getMenuObj()
	{
		return reinterpret_cast<T *>(menuManager.unknownPointer->unknownPointer->CMenuObj);
	}

	//! @brief Returns the name of the currently active menu.
	std::string getCurrentMenuName();

	Menu getCurrentMenu();
}

#include "Menus/ConnectMenu.hpp"

#endif //SOKULIB_MENUS_HPP
