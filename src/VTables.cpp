//
// Created by PinkySmile on 20/04/2021.
//

#include "VTables.hpp"
#include "Menus/ConnectMenu.hpp"
#include "Menus/ProfileDeckEdit.hpp"
#include "Packet.hpp"

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
	Menu_VTABLE<MenuResult>     &VTable_Result         = *reinterpret_cast<Menu_VTABLE<MenuResult>     *>(ADDR_VTBL_RESULT_MENU);
	Menu_VTABLE<PauseMenu>      &VTable_PauseMenu      = *reinterpret_cast<Menu_VTABLE<PauseMenu>      *>(ADDR_VTBL_PAUSE_MENU);
	BattleManager_VTABLE        &VTable_BattleManager  = *reinterpret_cast<BattleManager_VTABLE        *>(ADDR_VTBL_BATTLE_MANAGER);
	DPP_VTABLE<DPP_REPLAY>      &VTable_DPP_REPLAY     = *reinterpret_cast<DPP_VTABLE<DPP_REPLAY>      *>(ADDR_VTBL_DPP_REPLAY);

	int _vtable_offset_helper::r0()  { return 0; }
	int _vtable_offset_helper::r1()  { return 1; }
	int _vtable_offset_helper::r2()  { return 2; }
	int _vtable_offset_helper::r3()  { return 3; }
	int _vtable_offset_helper::r4()  { return 4; }
	int _vtable_offset_helper::r5()  { return 5; }
	int _vtable_offset_helper::r6()  { return 6; }
	int _vtable_offset_helper::r7()  { return 7; }
	int _vtable_offset_helper::r8()  { return 8; }
	int _vtable_offset_helper::r9()  { return 9; }
	int _vtable_offset_helper::r10() { return 10; }
	int _vtable_offset_helper::r11() { return 11; }
	int _vtable_offset_helper::r12() { return 12; }
	int _vtable_offset_helper::r13() { return 13; }
	int _vtable_offset_helper::r14() { return 14; }
	int _vtable_offset_helper::r15() { return 15; }
	int _vtable_offset_helper::r16() { return 16; }
	int _vtable_offset_helper::r17() { return 17; }
	int _vtable_offset_helper::r18() { return 18; }
	int _vtable_offset_helper::r19() { return 19; }
	int _vtable_offset_helper::r20() { return 20; }
	int _vtable_offset_helper::r21() { return 21; }
	int _vtable_offset_helper::r22() { return 22; }
	int _vtable_offset_helper::r23() { return 23; }
	int _vtable_offset_helper::r24() { return 24; }
	int _vtable_offset_helper::r25() { return 25; }
	int _vtable_offset_helper::r26() { return 26; }
	int _vtable_offset_helper::r27() { return 27; }
}