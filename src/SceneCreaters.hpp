//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_SCENECREATERS_HPP
#define SOKULIB_SCENECREATERS_HPP


#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �N���X�\�z�֐�caller
	enum SceneCreater {
		CSelectSV_Creater       = ADDR_SELECT_SV_CREATER,
		CSelectCL_Creater       = ADDR_SELECT_CL_CREATER,
		CBattleManager_Creater  = ADDR_BATTLE_MANAGER_CREATER,
	};
}


#endif //SOKULIB_SCENECREATERS_HPP
