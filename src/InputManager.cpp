//
// Created by PinkySmile on 02/12/2020.
//

#include "InputManager.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �C���v�b�g�}�l�[�W��
	// CInputManager ?
	InputManager &inputMgr = *reinterpret_cast<InputManager *>(ADDR_INPUT_MANAGER);

	// �C���v�b�g�}�l�[�W���N���X�^
	// CInputManagerCluster
	InputManagerCluster &inputMgrs = *reinterpret_cast<InputManagerCluster *>(ADDR_INPUT_MANAGER_CLUSTER);
}