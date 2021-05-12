//
// Created by PinkySmile on 11/05/2021.
//

#include "WS2_32.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	DLLWS2_32 &ws2_32 = *reinterpret_cast<DLLWS2_32 *>(ADDR_WS2_32_DLL);
}