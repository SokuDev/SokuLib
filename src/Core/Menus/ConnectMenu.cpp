//
// Created by Gegel85 on 05/11/2020.
//

#include "ConnectMenu.hpp"

namespace SokuLib
{
	void setupHost(uint port, bool spectate)
	{
		typedef void(__thiscall* func)(void*);
		func hostFun = (func)ADDR_HOST_FCT;

		MenuConnect *menu = getMenuObj();
		menu->port = port;
		menu->spectate = spectate;
		menu->choice = MenuConnect::CHOICE_HOST;
		menu->subchoice = 2;

		hostFun(menu);
	}

	void joinHost(const char *ip, uint port, bool spectate)
	{
		typedef void(__thiscall* func)(void*);
		func joinFun = (func)ADDR_JOIN_FCT;
		MenuConnect *menu = getMenuObj();

		if (ip != nullptr) {
			//Unsafe
			strcpy(menu->IPString, ip);
			menu->port = port;
		}
		menu->choice = MenuConnect::CHOICE_ASSIGN_IP_CONNECT;
		menu->subchoice = (spectate ? 6 : 3);
		menu->unknownJoinFlag = 1;
		menu->notSpectateFlag = (byte)!spectate;

		joinFun(menu);
	}

	void clearMenu()
	{
		getMenuObj()->choice = 0;
		getMenuObj()->subchoice = 0;
	}
}