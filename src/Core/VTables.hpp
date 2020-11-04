//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_VTABLES_HPP
#define SOKULIB_VTABLES_HPP


//From swrs.h (SWRSToys)

#include "SokuAddresses.hpp"

namespace SokuLib
{
	// ���z�֐��e�[�u��
	enum VTable {
		#ifndef SOKU_VER_110a
		vtbl_CLoadingSV           = ADDR_VTBL_LOADINGSV,
		vtbl_CLoadingCL           = ADDR_VTBL_LOADINGCL,
		vtbl_CBattleWatch         = ADDR_VTBL_BATTLE_WATCH,
		vtbl_CLoading             = ADDR_VTBL_LOADING,
		vtbl_Ending               = ADDR_VTBL_ENDING,
		vtbl_Opening              = ADDR_VTBL_OPENING,
		vtbl_CSelect              = ADDR_VTBL_SELECT,
		vtbl_CSelectScenario      = ADDR_VTBL_SELECT_SCENARIO,
		vtbl_CTitle               = ADDR_VTBL_TITLE,
		vtbl_CLoadingWatch        = ADDR_VTBL_LOADING_WATCH,
		vtbl_CBattleManagerStory  = ADDR_VTBL_BATTLE_MANAGER_STORY,
		vtbl_CBattleManagerArcade = ADDR_VTBL_BATTLE_MANAGER_ARCADE,
		vtbl_CInfoManager         = ADDR_VTBL_INFO_MANAGER,
		vtbl_CInfoManagerStory    = ADDR_VTBL_INFO_MANAGER_STORY,
		#endif
		vtbl_CLogo                = ADDR_VTBL_LOGO,
		vtbl_CBattle              = ADDR_VTBL_BATTLE,
		vtbl_CBattleCL            = ADDR_VTBL_BATTLECL,
		vtbl_CBattleSV            = ADDR_VTBL_BATTLESV,
		vtbl_CSelectSV            = ADDR_VTBL_SELECT_SV,
		vtbl_CSelectCL            = ADDR_VTBL_SELECT_CL,
		vtbl_CBattleManager       = ADDR_VTBL_BATTLE_MANAGER,
	};
}


#endif //SOKULIB_VTABLES_HPP
