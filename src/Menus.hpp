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

	struct UnknownStruct3 {
		char unknownField[8];
		void *CMenuObj;
	};

	struct UnknownStruct2 {
		char unknownField[4];
		UnknownStruct3 *unknownPointer;
	};

	struct UnknownStruct1 {
		UnknownStruct2 *unknownPointer;
		bool isInMenu;
	};

	extern UnknownStruct1 &menuManager;

	class IMenu {
	public:
		virtual ~IMenu() = default;
		virtual void _() = 0;
		virtual int onProcess() = 0;
		virtual int onRender() = 0;
	};

	class MenuCursor {
	public:
		int max = 1, unknown04 = 0;
		const int* valueAddr = 0; // valueAddr = &inputMgrs.input.<key>;
		int pos = 0, unknown10 = 0;

		inline void set(const int* valueAddr, int max = 1, int pos = 0) {
			this->max = max;
			//this->unknown04 = 0;
			this->valueAddr = valueAddr;
			this->pos = this->unknown10 = pos;
		}

		bool update();
		static void render(float x, float y, float width);
	};
}

#include "Menus/ConnectMenu.hpp"
#include "Menus/ProfileDeckEdit.hpp"
#include "Menus/ResultMenu.hpp"

#endif //SOKULIB_MENUS_HPP
