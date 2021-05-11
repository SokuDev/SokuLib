//
// Created by PinkySmile on 11/05/2021.
//

#include "IMM32.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	DLLIMM32 &imm32 = *reinterpret_cast<DLLIMM32 *>(ADDR_IMM32_DLL);
}