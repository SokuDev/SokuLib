//
// Created by PinkySmile on 02/12/2020.
//

#include "SceneSize.hpp"

namespace SokuLib
{
	const unsigned int &CSelectCL_Size = *reinterpret_cast<unsigned int *>(ADDR_SELECT_CL_SIZE);
	const unsigned int &CSelectSV_Size = *reinterpret_cast<unsigned int *>(ADDR_SELECT_SV_SIZE);
	const unsigned int &CBattleManager_Size = *reinterpret_cast<unsigned int *>(ADDR_BATTLE_MANAGER_SIZE);
}