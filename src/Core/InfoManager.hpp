//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_INFOMANAGER_HPP
#define SOKULIB_INFOMANAGER_HPP

//From swrs.h (SWRSToys)

#include "SokuAddresses.hpp"

namespace SokuLib
{
	struct InfoManager;

	// �C���t�H�}�l�[�W��
	// CInfoManager *
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline InfoManager *getInfoMgr()
	{
		return *(InfoManager **)ADDR_INFO_MANAGER;
	}
}


#endif //SOKULIB_INFOMANAGER_HPP
