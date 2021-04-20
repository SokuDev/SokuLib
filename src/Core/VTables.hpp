//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_VTABLES_HPP
#define SOKULIB_VTABLES_HPP


#include "BattleManager.hpp"
#include "../Data/Scenes.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	enum [[deprecated("Replaced with struct Scene_VTABLE")]] VTableScenesOffsets {
		OFFSET_ON_PROCESS = 0x4,
		OFFSET_ON_RENDER  = 0x8,
	};

	enum [[deprecated("Replaced with struct BattleManager_VTABLE")]] VTableBattleManagerOffsets {
		BATTLE_MGR_OFFSET_ON_DESTRUCT              = 0x00, // Destructor
		BATTLE_MGR_OFFSET_ON_ARENA_START           = 0x04, // After select arena start, best place for initializing girls
		                                                   // void *(void *, int, int)
		BATTLE_MGR_OFFSET_ON_EXIT                  = 0x08, // After exit on selection screen menu
		BATTLE_MGR_OFFSET_ON_PROCESS               = 0x0C, // Progress??
		BATTLE_MGR_OFFSET_ON_SAY_START             = 0x10, // Announcement say start round
		BATTLE_MGR_OFFSET_AFTER_BLACK_SCREEN       = 0x14, // After load black screen
		BATTLE_MGR_OFFSET_MAYBE_ON_PROGRESS        = 0x18, // Progress???
		BATTLE_MGR_OFFSET_ON_ROUND_END             = 0x1C, // After round
		BATTLE_MGR_OFFSET_ON_KO                    = 0x20, // After battle (KO)
		BATTLE_MGR_OFFSET_ON_GIRL_TALK             = 0x24, // After girls talk
		BATTLE_MGR_OFFSET_UNKNOWN                  = 0x28, // ??????????
		BATTLE_MGR_OFFSET_ON_LAST_ROUND_HIT        = 0x2C, // Before last hit in round
		BATTLE_MGR_OFFSET_ON_ROUND_START           = 0x30, // After stat round and before end pure battle()
		BATTLE_MGR_OFFSET_ON_SHOW_LOGO             = 0x34, // at the start before "start round" logo int is 1
		                                                   // becomes 2 after logo
		                                                   // becomes 3 the end of round
		                                                   // becomes 5 after final round before logo
		                                                   // becomes 6 after final
		                                                   // becomes 7 after girls talk
		                                                   // void *(void *, int, int)
		BATTLE_MGR_OFFSET_ON_RENDER                = 0x38, // After select arena render or draw()
		BATTLE_MGR_OFFSET_MAYBE_ON_RENDER          = 0x3C, // After select arena render????
		BATTLE_MGR_OFFSET_MAYBE_ON_RENDER2         = 0x40, // After select arena render???? Last function???
	};

	// ���z�֐��e�[�u��

	enum [[deprecated("Replaced with globals")]] VTable {
		//TODO: Find this for version 1.10a
		#ifdef SOKU_VER_110
		vtbl_Ending               = ADDR_VTBL_ENDING,
		vtbl_Opening              = ADDR_VTBL_OPENING,
		vtbl_CSelectScenario      = ADDR_VTBL_SELECT_SCENARIO,
		vtbl_CBattleManagerStory  = ADDR_VTBL_BATTLE_MANAGER_STORY,
		vtbl_CBattleManagerArcade = ADDR_VTBL_BATTLE_MANAGER_ARCADE,
		vtbl_CInfoManager         = ADDR_VTBL_INFO_MANAGER,
		vtbl_CInfoManagerStory    = ADDR_VTBL_INFO_MANAGER_STORY,
		#endif
		vtbl_CSelect              = ADDR_VTBL_SELECT,
		vtbl_CLogo                = ADDR_VTBL_LOGO,
		vtbl_CTitle               = ADDR_VTBL_TITLE,
		vtbl_CBattle              = ADDR_VTBL_BATTLE,
		vtbl_CBattleCL            = ADDR_VTBL_BATTLE_CL,
		vtbl_CBattleSV            = ADDR_VTBL_BATTLE_SV,
		vtbl_CBattleWatch         = ADDR_VTBL_BATTLE_WATCH,
		vtbl_CSelectSV            = ADDR_VTBL_SELECT_SV,
		vtbl_CSelectCL            = ADDR_VTBL_SELECT_CL,
		vtbl_CLoading             = ADDR_VTBL_LOADING,
		vtbl_CLoadingSV           = ADDR_VTBL_LOADINGSV,
		vtbl_CLoadingCL           = ADDR_VTBL_LOADINGCL,
		vtbl_CLoadingWatch        = ADDR_VTBL_LOADING_WATCH,
		vtbl_CBattleManager       = ADDR_VTBL_BATTLE_MANAGER,
	};

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
	extern BattleManager_VTABLE        &VTable_BattleManager;
}


#endif //SOKULIB_VTABLES_HPP
