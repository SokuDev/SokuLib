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
	KeymapManager &inputMgrs = *reinterpret_cast<KeymapManager *>(ADDR_INPUT_MANAGER_CLUSTER);

	bool InputManager::readReplay(const char *path)
	{
		return (reinterpret_cast<bool (__thiscall *)(InputManager *, const char *)>(ADDR_INPUT_MANAGER_READ_REPLAY))(this, path);
	}
}