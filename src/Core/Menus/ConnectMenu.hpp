#pragma once
#include "../SokuAddresses.hpp"
#include "../Memory.hpp"
#include <Windows.h>
#include <cwchar>
#include <string>

typedef unsigned uint;

namespace SokuLib
{
	typedef void *(__thiscall *MenuInitFun)(void *buffer);

	//! @brief Pointer to the original host soku function.
	//! @param menu Pointer to the current menu object.
	//! @warning: This function is unsafe if not in the network menu.
	//! @note It is recommended to use setupHost instead.
	extern void (__thiscall * const host)(void *menu);

	//! @brief Pointer to the original join host soku function.
	//! @param menu Pointer to the current menu object.
	//! @warning: This function is unsafe if not in the network menu.
	//! @note It is recommended to use joinHost instead.
	extern void (__thiscall * const join)(void *menu);

	//! @brief Pointer to the original network menu object init soku function.
	//! @param buffer Pointer to the buffer to use for the menu object.
	//! @warning: This function is unsafe if the allocated buffer is not big enough.
	//! @note It is recommended to use initNetworkMenu instead.
	extern const MenuInitFun networkMenuInit;

	//! @brief The buffer size needed to hold the network menu.
	constexpr unsigned networkMenuBufferSize  = 0x118C;

	struct UnknownStruct3 {
		byte unknownField[8];
		void *CMenuObj;
	};

	struct UnknownStruct2 {
		byte unknownField[4];
		UnknownStruct3 *unknownPointer;
	};

	struct UnknownStruct1 {
		UnknownStruct2 *unknownPointer;
		bool isInMenu;
	};

	extern UnknownStruct1 &menuManager;

	typedef struct {
		void *vftable;
		void *CNetworkBasePtr;
		byte choice;
		byte subchoice;
		byte unknownField0[2];
		void *CDesignBasePtr;
		byte UNKNOWN_1[48];
		void *menuItemSprites[7];
		byte unknownField2[860];
		byte notSpectateFlag;
		byte spectate;
		byte unknownField3[2];
		uint menuItemCount;
		byte unknownField4[8];
		uint cursorPos;
		uint cursorPos2;
		byte unknownField5[48];
		uint numberInputArrowPos;
		byte unknownField6[36];
		uint port;
		byte unknownField7[4];
		char IPString[20]; //Final/Used val
		char IPWString; //Unknown size
		byte unknownField8[2051];
		uint notInSubMenuFlag;
		byte unknownField9[332];
		byte inSubMenuFlag;
		byte unknownField10[171];
		byte unknownJoinFlag;
		byte unknownField12[835];

		enum Choice {
			CHOICE_NOTHING,
			CHOICE_HOST,
			CHOICE_ASSIGN_IP_CONNECT,
			CHOICE_IP_LIST_CONNECT,
			CHOICE_HISTORY_LIST_CONNECT,
			CHOICE_CLIPBOARD_CONNECT,
			CHOICE_SELECT_PROFILE,
		};
	} MenuConnect;

	template<typename T>
	//! @brief Gives the currently used menu object.
	//! @tparam T The type of the expected object.
	//! @warning Unsafe if not currently in a title screen submenu.
	//! @return The current menu object.
	T *getMenuObj()
	{
		return reinterpret_cast<T *>(menuManager.unknownPointer->unknownPointer->CMenuObj);
	}

	//! @brief Inits a new network menu to give to activateMenu.
	//! @return The newly created menu.
	void *initNetworkMenu();

	//! @brief Returns the name of the currently active menu.
	std::string getCurrentMenuName();

	//! @brief Returns whether the currently active menu is the network menu.
	bool isInNetworkMenu();

	//! @brief Moves to the connect menu.
	//! @note Might cause some instability if the title screen hasn't been fully loaded (TLDR, unsafe if the title screen buttons has still never been displayed)
	void moveToConnectMenu();

	//! @brief Starts hosting.
	//! @param port The port you which to host on.
	//! @param spectate Whether spectators are allowed or not.
	void setupHost(uint port, bool spectate);

	//! @brief Starts connecting to an host.
	//! @param ip The ip of the host.
	//! @param port The port of the host.
	//! @param spectate Connect as spectator or not.
	void joinHost(const char *ip, uint port, bool spectate = false);

	//! @brief Resets choice/subchoice and clears any messagebox
	void clearMenu();
}
