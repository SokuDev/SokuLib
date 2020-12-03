//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"

namespace SokuLib
{
	void (* const activateMenu)(void *addr) = reinterpret_cast<void (*)(void *)>(ADDR_ACTIVATE_MENU);
}