//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �V�X�e���L�[�����V���b�g
	bool (* const checkKeyOneshot)(int a, int b, int c, int d) = reinterpret_cast<bool (*)(int, int, int, int)>(ADDR_CHECK_KEY_ONESHOT);
}