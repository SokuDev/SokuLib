//
// Created by PinkySmile on 20/04/2021.
//

#include "VTables.hpp"
#include "Menus/ConnectMenu.hpp"
#include "Menus/ProfileDeckEdit.hpp"

namespace SokuLib
{
	Scene_VTABLE<Select>        &VTable_Select         = *reinterpret_cast<Scene_VTABLE<Select>        *>(ADDR_VTBL_SELECT);
	Scene_VTABLE<Logo>          &VTable_Logo           = *reinterpret_cast<Scene_VTABLE<Logo>          *>(ADDR_VTBL_LOGO);
	Scene_VTABLE<Title>         &VTable_Title          = *reinterpret_cast<Scene_VTABLE<Title>         *>(ADDR_VTBL_TITLE);
	Scene_VTABLE<Battle>        &VTable_Battle         = *reinterpret_cast<Scene_VTABLE<Battle>        *>(ADDR_VTBL_BATTLE);
	Scene_VTABLE<BattleClient>  &VTable_BattleClient   = *reinterpret_cast<Scene_VTABLE<BattleClient>  *>(ADDR_VTBL_BATTLE_CL);
	Scene_VTABLE<BattleServer>  &VTable_BattleServer   = *reinterpret_cast<Scene_VTABLE<BattleServer>  *>(ADDR_VTBL_BATTLE_SV);
	Scene_VTABLE<BattleWatch>   &VTable_BattleWatch    = *reinterpret_cast<Scene_VTABLE<BattleWatch>   *>(ADDR_VTBL_BATTLE_WATCH);
	Scene_VTABLE<SelectServer>  &VTable_SelectServer   = *reinterpret_cast<Scene_VTABLE<SelectServer>  *>(ADDR_VTBL_SELECT_SV);
	Scene_VTABLE<SelectClient>  &VTable_SelectClient   = *reinterpret_cast<Scene_VTABLE<SelectClient>  *>(ADDR_VTBL_SELECT_CL);
	Scene_VTABLE<Loading>       &VTable_Loading        = *reinterpret_cast<Scene_VTABLE<Loading>       *>(ADDR_VTBL_LOADING);
	Scene_VTABLE<LoadingServer> &VTable_LoadingServer  = *reinterpret_cast<Scene_VTABLE<LoadingServer> *>(ADDR_VTBL_LOADINGSV);
	Scene_VTABLE<LoadingClient> &VTable_LoadingClient  = *reinterpret_cast<Scene_VTABLE<LoadingClient> *>(ADDR_VTBL_LOADINGCL);
	Scene_VTABLE<LoadingWatch>  &VTable_LoadingWatch   = *reinterpret_cast<Scene_VTABLE<LoadingWatch>  *>(ADDR_VTBL_LOADING_WATCH);
	Menu_VTABLE<MenuConnect>    &VTable_ConnectMenu    = *reinterpret_cast<Menu_VTABLE<MenuConnect>    *>(ADDR_VTBL_VS_NETWORK_MENU);
	Menu_VTABLE<ProfileDeckEdit>&VTable_ProfileDeckEdit= *reinterpret_cast<Menu_VTABLE<ProfileDeckEdit>*>(ADDR_VTBL_DECK_CONSTRUCTION_CHR_SELECT_MENU);
	BattleManager_VTABLE        &VTable_BattleManager = *reinterpret_cast<BattleManager_VTABLE         *>(ADDR_VTBL_BATTLE_MANAGER);
}