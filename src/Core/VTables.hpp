//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_VTABLES_HPP
#define SOKULIB_VTABLES_HPP


#include "SokuAddresses.hpp"

namespace SokuLib
{
	enum VTableScenesOffsets {
		OFFSET_ON_PROCESS = 0x4,
		OFFSET_ON_RENDER  = 0x8,
	};

	enum VTableBattleManagerOffsets {
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
	enum VTable {
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
}


#endif //SOKULIB_VTABLES_HPP
