//
// Created by PinkySmile on 11/05/2021.
//

#include "WINMM.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	DLLWINMM32 &winmm32 = *reinterpret_cast<DLLWINMM32 *>(ADDR_WINMM32_DLL);
}