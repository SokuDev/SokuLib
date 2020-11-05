// Made by S-len https://github.com/S-len
#pragma once
#include "../SokuAddresses.hpp"
#include <Windows.h>
#include <cwchar>

#define UNKNOWN_GLOBAL 0x0089a888
#define IN_MENU *(char*)(0x089a888 + 4)

#define CMENU_OBJ (*(*((*(void****)UNKNOWN_GLOBAL)+1)+2))

typedef unsigned uint;

namespace SokuLib
{
	typedef struct {
		void *vftable;
		void *CNetworkBasePtr;
		byte choice;
		byte subchoice;
		byte UNKNOWN_0[2];
		void *CDesignBasePtr;
		byte UNKNOWN_1[48];
		void *menuItemSprites[7];
		byte UNKNOWN_2[860];
		byte notSpectateFlag;
		byte spectate;
		byte UNKNOWN_3[2];
		uint menuItemCount;
		byte UNKNOWN_4[8];
		uint cursorPos;
		uint cursorPos2;
		byte UNKNOWN_5[48];
		uint numberInputArrowPos;
		byte UNKNOWN_6[36];
		uint port;
		byte UNKNOWN_7[4];
		char IPString[20]; //Final/Used val
		char IPWString; //Unknown size
		byte UNKNOWN_8[2051];
		uint NotInSubMenuFlag;
		byte UNKNOWN_9[332];
		byte inSubMenuFlag;
		byte UNKNOWN_10[171];
		byte unknownJoinFlag;
		byte UNKNOWN_12[835];

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

	__forceinline MenuConnect *getMenuObj()
	{
		return (MenuConnect*)CMENU_OBJ;
	}

	void setupHost(uint port, bool spectate);
	void joinHost(const char *ip, uint port, bool spectate = false);
	//! @brief Resets choice/subchoice and clears any messagebox
	void clearMenu();
}
