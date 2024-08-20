//
// Created by PinkySmile on 05/11/2020.
//

#include "ConnectMenu.hpp"
#include "../Exceptions.hpp"
#include "../UnionCast.hpp"
#include "../Scenes.hpp"
#include "../Menus.hpp"

namespace SokuLib
{
	void MenuConnect::setupHost(unsigned port, bool spectate)
	{
		this->port = port;
		this->spectate = spectate;
		this->choice = MenuConnect::CHOICE_HOST;
		this->subchoice = 2;
		this->host();
	}

	void MenuConnect::joinHost(const char *ip, unsigned port, bool spectate)
	{
		if (ip != nullptr) {
			//Unsafe
			strcpy(this->IPString, ip);
			this->port = port;
		}
		this->choice = MenuConnect::CHOICE_ASSIGN_IP_CONNECT;
		this->subchoice = (spectate ? 6 : 3);
		this->unknownJoinFlag = 1;
		this->notSpectateFlag = (byte)!spectate;
		this->join();
	}

	void MenuConnect::clear()
	{
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

	MenuConnect &MenuConnect::moveToConnectMenu()
	{
		while (SokuLib::sceneId != SCENE_TITLE) {
			changeScene(SCENE_TITLE);
			waitForSceneChange();
		}

		if (getCurrentMenu() != MENU_CONNECT) {
			auto result = create();

			activateMenu(result);
			return *result;
		}
		return *getMenuObj<MenuConnect>();
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