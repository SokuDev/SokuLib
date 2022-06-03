//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"
#include "Menus.hpp"
#include "Scenes.hpp"

namespace SokuLib
{
	void (* const activateMenu)(void *addr) = reinterpret_cast<void (*)(void *)>(ADDR_ACTIVATE_MENU);
	List<IMenu*> &menuManager = *reinterpret_cast<List<IMenu*>*>(ADDR_MENU_LIST);

	std::string getCurrentMenuName()
	{
		switch (getCurrentMenu()) {
		case MENU_NONE:
			return "Title screen";
		case MENU_CONNECT:
			return "VSNetwork";
		case MENU_REPLAY:
			return "Replay";
		case MENU_MUSICROOM:
			return "Musicroom";
		case MENU_RESULT:
			return "Result";
		case MENU_PROFILE:
			return "Profile";
		case MENU_CONFIG:
			return "Config";
		case MENU_DECK_CONSTRUCTION:
			return "Deck construction";
		case MENU_KEYS:
			return "Keys";
		case MENU_COUNT:
			return "Unknown menu";
		}
		return "Invalid menu";
	}

	Menu getCurrentMenu()
	{
		if (sceneId != SCENE_TITLE)
			return MENU_COUNT;

		if (!menuManager.size())
			return MENU_NONE;

		switch (*getMenuObj<DWORD>()) {
		case ADDR_VTBL_CONFIG_MENU:
			return MENU_CONFIG;
		case ADDR_VTBL_VS_NETWORK_MENU:
			return MENU_CONNECT;
		case ADDR_VTBL_MUSIC_ROOM_MENU:
			return MENU_MUSICROOM;
		case ADDR_VTBL_REPLAY_MENU:
			return MENU_REPLAY;
		case ADDR_VTBL_RESULT_MENU:
			return MENU_RESULT;
		case ADDR_VTBL_PROFILE_MENU:
			return MENU_PROFILE;
		case ADDR_VTBL_DECK_CONSTRUCTION_MENU:
		case ADDR_VTBL_DECK_CONSTRUCTION_CHR_SELECT_MENU:
			return MENU_DECK_CONSTRUCTION;
		case ADDR_VTBL_CHANGE_KEYS_MENU:
			return MENU_KEYS;
		default:
			return MENU_COUNT;
		}
	}

	bool MenuCursor::update() {
		return (this->*union_cast<bool (MenuCursor::*)()>(ADDR_MENUCURSOR_UPDATE))();
	}

	void MenuCursor::render(float x, float y, float width) {
		union_cast<void(*)(float, float, float)>(ADDR_MENUCURSOR_RENDER)(x, y, width);
	}
}