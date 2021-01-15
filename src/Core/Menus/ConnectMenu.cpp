//
// Created by Gegel85 on 05/11/2020.
//

#include "../Menus.hpp"
#include "../../Data/Scenes.hpp"
#include "ConnectMenu.hpp"
#include "../Exceptions.hpp"


namespace SokuLib
{
	void (__thiscall * const host)(void *) = (void (__thiscall *const)(void *))ADDR_HOST_FCT;
	void (__thiscall * const join)(void *) = (void (__thiscall *const)(void *))ADDR_JOIN_FCT;
	UnknownStruct1 &menuManager = *reinterpret_cast<UnknownStruct1 *>(ADDR_UNKNOWN_VAR_MENU);
	const MenuInitFun networkMenuInit = (MenuInitFun)ADDR_NETWORK_MENU_INIT;

	void setupHost(uint port, bool spectate)
	{
#ifdef _SOKU_LIB_DEBUG
		if (!isInNetworkMenu())
			throw InvalidMenuException(getCurrentMenuName(), "Network menu");
#endif

		auto menu = getMenuObj<MenuConnect>();

		menu->port = port;
		menu->spectate = spectate;
		menu->choice = MenuConnect::CHOICE_HOST;
		menu->subchoice = 2;

		host(menu);
	}

	void joinHost(const char *ip, uint port, bool spectate)
	{
#ifdef _SOKU_LIB_DEBUG
		if (!isInNetworkMenu())
			throw InvalidMenuException(getCurrentMenuName(), "Network menu");
#endif
		auto menu = getMenuObj<MenuConnect>();

		if (ip != nullptr) {
			//Unsafe
			strcpy(menu->IPString, ip);
			menu->port = port;
		}
		menu->choice = MenuConnect::CHOICE_ASSIGN_IP_CONNECT;
		menu->subchoice = (spectate ? 6 : 3);
		menu->unknownJoinFlag = 1;
		menu->notSpectateFlag = (byte)!spectate;

		join(menu);
	}

	void clearMenu()
	{
#ifdef _SOKU_LIB_DEBUG
		if (!isInNetworkMenu())
			throw InvalidMenuException(getCurrentMenuName(), "Network menu");
#endif
		//TODO: Add the clearing of the message box.
		//GetMsgBox()->active = false;
		getMenuObj<MenuConnect>()->choice = 0;
		getMenuObj<MenuConnect>()->subchoice = 0;
	}

	void *initNetworkMenu()
	{
		return networkMenuInit(New(networkMenuBufferSize));
	}

	void moveToConnectMenu()
	{
		changeScene(SCENE_TITLE);
		waitForSceneChange();
		activateMenu(initNetworkMenu());
	}

	bool isInNetworkMenu()
	{
		return sceneId == SCENE_TITLE && menuManager.isInMenu && !*reinterpret_cast<char *>(getMenuObj<MenuConnect>());
	}

	std::string getCurrentMenuName()
	{
		//TODO: Code this function
		return "Unknown menu";
	}

	Menu getCurrentMenu()
	{
		//TODO: Code this function
		if (isInNetworkMenu())
			return MENU_CONNECT;
		return MENU_NONE;
	}
}