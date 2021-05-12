#pragma once

#include "../SokuAddresses.hpp"
#include "../Memory.hpp"
#include <Windows.h>
#include <cwchar>
#include <string>


namespace SokuLib
{
	//! @brief The buffer size needed to hold the network menu.
	constexpr unsigned networkMenuBufferSize  = 0x118C;

	struct MenuConnect {
		void *vftable;
		void *CNetworkBasePtr;
		unsigned char choice;
		unsigned char subchoice;
		unsigned char unknownField0[2];
		void *CDesignBasePtr;
		unsigned char UNKNOWN_1[48];
		void *menuItemSprites[7];
		unsigned char unknownField2[860];
		unsigned char notSpectateFlag;
		unsigned char spectate;
		unsigned char unknownField3[2];
		unsigned menuItemCount;
		unsigned char unknownField4[8];
		unsigned cursorPos;
		unsigned cursorPos2;
		unsigned char unknownField5[48];
		unsigned numberInputArrowPos;
		unsigned char unknownField6[36];
		unsigned port;
		unsigned char unknownField7[4];
		char IPString[20]; //Final/Used val
		char IPWString; //Unknown size
		unsigned char unknownField8[2051];
		unsigned notInSubMenuFlag;
		unsigned char unknownField9[332];
		unsigned char inSubMenuFlag;
		unsigned char unknownField10[171];
		unsigned char unknownJoinFlag;
		unsigned char unknownField12[835];

		enum Choice {
			CHOICE_NOTHING,
			CHOICE_HOST,
			CHOICE_ASSIGN_IP_CONNECT,
			CHOICE_IP_LIST_CONNECT,
			CHOICE_HISTORY_LIST_CONNECT,
			CHOICE_CLIPBOARD_CONNECT,
			CHOICE_SELECT_PROFILE,
		};

		//! @brief Pointer to the original host soku function.
		//! @param menu Pointer to the current menu object.
		//! @warning: This function is unsafe if not in the network menu.
		//! @note It is recommended to use setupHost instead.
		void host();

		//! @brief Pointer to the original join host soku function.
		//! @param menu Pointer to the current menu object.
		//! @warning: This function is unsafe if not in the network menu.
		//! @note It is recommended to use joinHost instead.
		void join();

		//! @brief Pointer to the original network menu object init soku function.
		//! @param buffer Pointer to the buffer to use for the menu object.
		//! @warning: This function is unsafe if the allocated buffer is not big enough.
		//! @note It is recommended to use initNetworkMenu instead.
		void init();

		//! @brief Resets choice/subchoice and clears any messagebox
		void clear();

		//! @brief Inits a new network menu to give to activateMenu.
		//! @return The newly created menu.
		static MenuConnect *create();

		//! @brief Returns whether the currently active menu is the network menu.
		static bool isInNetworkMenu();

		//! @brief Moves to the connect menu.
		//! @note Might cause some instability if the title screen hasn't been fully loaded (TLDR, unsafe if the title screen buttons has still never been displayed)
		static MenuConnect &moveToConnectMenu();

		//! @brief Starts hosting.
		//! @param port The port you which to host on.
		//! @param spectate Whether spectators are allowed or not.
		void setupHost(unsigned port, bool spectate);

		//! @brief Starts connecting to an host.
		//! @param ip The ip of the host.
		//! @param port The port of the host.
		//! @param spectate Connect as spectator or not.
		void joinHost(const char *ip, unsigned port, bool spectate = false);
	};
}
