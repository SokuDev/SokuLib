//
// Created by Gegel85 on 05/11/2020.
//

#include "../Menus.hpp"
#include "../../Data/Scenes.hpp"
#include "ConnectMenu.hpp"
#include "../Exceptions.hpp"
#include "../SokuFct.hpp"


namespace SokuLib
{
	UnknownStruct1 &menuManager = *reinterpret_cast<UnknownStruct1 *>(ADDR_UNKNOWN_VAR_MENU);

	void MenuConnect::setupHost(uint port, bool spectate)
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

		menu->host();
	}

	void MenuConnect::joinHost(const char *ip, uint port, bool spectate)
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

		menu->join();
	}

	void MenuConnect::clear()
	{
#ifdef _SOKU_LIB_DEBUG
		if (!isInNetworkMenu())
			throw InvalidMenuException(getCurrentMenuName(), "Network menu");
#endif
		//TODO: Add the clearing of the message box.
		//GetMsgBox()->active = false;
		this->choice = 0;
		this->subchoice = 0;
	}

	MenuConnect *MenuConnect::create()
	{
		auto result = New<MenuConnect>(networkMenuBufferSize);

		result->init();
		return result;
	}

	void MenuConnect::moveToConnectMenu()
	{
		changeScene(SCENE_TITLE);
		waitForSceneChange();
		activateMenu(create());
	}

	bool MenuConnect::isInNetworkMenu()
	{
		return getCurrentMenu() == MENU_CONNECT;
	}

	void MenuConnect::host()
	{
		(this->*union_cast<void (__thiscall MenuConnect::*)()>(ADDR_HOST_FCT))();
	}

	void MenuConnect::join()
	{
		(this->*union_cast<void (__thiscall MenuConnect::*)()>(ADDR_JOIN_FCT))();
	}

	void MenuConnect::init()
	{
		(this->*union_cast<void (__thiscall MenuConnect::*)()>(ADDR_NETWORK_MENU_INIT))();
	}
}