//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_SCENECREATERS_HPP
#define SOKULIB_SCENECREATERS_HPP


#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �N���X�\�z�֐�caller
	enum SceneCreater {
		//TODO: Add these for version 1.10a
		#ifdef SOKU_VER_110
		CLogo_Creater           = ADDR_LOGO_CREATER,
		Opening_Creater         = ADDR_OPENING_CREATER,
		CLoading_Creater        = ADDR_LOADING_CREATER,
		CTitle_Creater          = ADDR_TITLE_CREATER,
		CSelect_Creater         = ADDR_SELECT_CREATER,
		CSelectScenario_Creater = ADDR_SELECT_SCENARIO_CREATER,
		CBattle_Creater         = ADDR_BATTLE_CREATER,
		Ending_Creater          = ADDR_ENDING_CREATER,
		CLoadingSV_Creater      = ADDR_LOADINGSV_CREATER,
		CBattleSV_Creater       = ADDR_BATTLESV_CREATER,
		CLoadingCL_Creater      = ADDR_LOADINGCL_CREATER,
		CBattleCL_Creater       = ADDR_BATTLECL_CREATER,
		CLoadingWatch_Creater   = ADDR_LOADING_WATCH_CREATER,
		CBattleWatch_Creater    = ADDR_BATTLE_WATCH_CREATER,
		#endif
		CSelectSV_Creater       = ADDR_SELECT_SV_CREATER,
		CSelectCL_Creater       = ADDR_SELECT_CL_CREATER,
		CBattleManager_Creater  = ADDR_BATTLE_MANAGER_CREATER,
	};
}


#endif //SOKULIB_SCENECREATERS_HPP
