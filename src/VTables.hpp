//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_VTABLES_HPP
#define SOKULIB_VTABLES_HPP


#include "BattleManager.hpp"
#include "Scenes.hpp"
#include "SokuAddresses.hpp"
#include "Menus.hpp"

namespace SokuLib
{
	template<typename T>
	struct Scene_VTABLE {
		T *(T::*destructor)(char unknown);
		int (T::*onProcess)();
		int (T::*onRender)();
		void (T::*unknown)();
		void (T::*unknown2)();
		void (T::*unknown3)();
		void (T::*unknown4)();
	};

	template<typename T>
	struct Menu_VTABLE {
		T *(T::*onDestruct)(unsigned char param);
		void *unknown;
		int (T::*onProcess)();
		int (T::*onRender)();
	};

	struct BattleManager_VTABLE {
		BattleManager *(BattleManager::*destructor)(char unknown);
		void (BattleManager::*onArenaStart)(void *param);
		void (BattleManager::*onExit)();
		int (BattleManager::*onProcess)();
		int (BattleManager::*onSayStart)();
		int (BattleManager::*afterBlackScreen)();
		int (BattleManager::*maybeOnProgress)();
		int (BattleManager::*onRoundEnd)();
		int (BattleManager::*onKO)();
		int (BattleManager::*onGirlsTalk)();
		int (BattleManager::*unknownFunction)();
		void (BattleManager::*battleResultScreen)(); //When showing the cards earned in the battle
		void (BattleManager::*onRoundStart)();
		void (BattleManager::*onShowLogo)(int param);
		void (BattleManager::*onRender)();       // After select arena render or draw()
		void (BattleManager::*maybeOnRender)();  // After select arena render????
		void (BattleManager::*maybeOnRender2)(); // After select arena render???? Last function???
	};

	extern Scene_VTABLE<Select>        &VTable_Select;
	extern Scene_VTABLE<Logo>          &VTable_Logo;
	extern Scene_VTABLE<Title>         &VTable_Title;
	extern Scene_VTABLE<Battle>        &VTable_Battle;
	extern Scene_VTABLE<BattleClient>  &VTable_BattleClient;
	extern Scene_VTABLE<BattleServer>  &VTable_BattleServer;
	extern Scene_VTABLE<BattleWatch>   &VTable_BattleWatch;
	extern Scene_VTABLE<SelectServer>  &VTable_SelectServer;
	extern Scene_VTABLE<SelectClient>  &VTable_SelectClient;
	extern Scene_VTABLE<Loading>       &VTable_Loading;
	extern Scene_VTABLE<LoadingServer> &VTable_LoadingServer;
	extern Scene_VTABLE<LoadingClient> &VTable_LoadingClient;
	extern Scene_VTABLE<LoadingWatch>  &VTable_LoadingWatch;
	extern Menu_VTABLE<MenuConnect>    &VTable_ConnectMenu;
	extern Menu_VTABLE<ProfileDeckEdit>&VTable_ProfileDeckEdit;
	extern Menu_VTABLE<MenuResult>     &VTable_Result;
	extern BattleManager_VTABLE        &VTable_BattleManager;
}


#endif //SOKULIB_VTABLES_HPP
