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

	// ���z�֐��e�[�u��
	enum VTable {
		//TODO: Find this for version 1.10a
		#ifdef SOKU_VER_110
		vtbl_CLoadingSV           = ADDR_VTBL_LOADINGSV,
		vtbl_CLoadingCL           = ADDR_VTBL_LOADINGCL,
		vtbl_Ending               = ADDR_VTBL_ENDING,
		vtbl_Opening              = ADDR_VTBL_OPENING,
		vtbl_CSelect              = ADDR_VTBL_SELECT,
		vtbl_CSelectScenario      = ADDR_VTBL_SELECT_SCENARIO,
		vtbl_CBattleManagerStory  = ADDR_VTBL_BATTLE_MANAGER_STORY,
		vtbl_CBattleManagerArcade = ADDR_VTBL_BATTLE_MANAGER_ARCADE,
		vtbl_CInfoManager         = ADDR_VTBL_INFO_MANAGER,
		vtbl_CInfoManagerStory    = ADDR_VTBL_INFO_MANAGER_STORY,
		#endif
		vtbl_CLogo                = ADDR_VTBL_LOGO,
		vtbl_CTitle               = ADDR_VTBL_TITLE,
		vtbl_CBattle              = ADDR_VTBL_BATTLE,
		vtbl_CBattleCL            = ADDR_VTBL_BATTLE_CL,
		vtbl_CBattleSV            = ADDR_VTBL_BATTLE_SV,
		vtbl_CBattleWatch         = ADDR_VTBL_BATTLE_WATCH,
		vtbl_CSelectSV            = ADDR_VTBL_SELECT_SV,
		vtbl_CSelectCL            = ADDR_VTBL_SELECT_CL,
		vtbl_CLoading             = ADDR_VTBL_LOADING,
		vtbl_CLoadingWatch        = ADDR_VTBL_LOADING_WATCH,
		vtbl_CBattleManager       = ADDR_VTBL_BATTLE_MANAGER,
	};
}


#endif //SOKULIB_VTABLES_HPP
