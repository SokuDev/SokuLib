//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"
#include "Key.hpp"

namespace SokuLib
{
	// �V�X�e���L�[�����V���b�g
	bool (* const checkKeyOneshot)(int, int, int, int) = reinterpret_cast<bool (*)(int, int, int, int)>(ADDR_CHECK_KEY_ONESHOT);
}