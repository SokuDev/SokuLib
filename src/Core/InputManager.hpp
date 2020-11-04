//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_INPUTMANAGER_HPP
#define SOKULIB_INPUTMANAGER_HPP


//From swrs.h (SWRSToys)

#include "SokuAddresses.hpp"

namespace SokuLib
{
	struct InputManager;
	struct InputManagerCluster;

	// �C���v�b�g�}�l�[�W��
	// CInputManager ?
	__forceinline InputManager *getInputMgr()
	{
		return reinterpret_cast<InputManager *>(ADDR_INPUT_MANAGER);
	}

	// �C���v�b�g�}�l�[�W���N���X�^
	// CInputManagerCluster
	__forceinline InputManagerCluster *getInputMgrs()
	{
		return reinterpret_cast<InputManagerCluster *>(ADDR_INPUT_MANAGER_CLUSTER);
	}
}


#endif //SOKULIB_INPUTMANAGER_HPP
