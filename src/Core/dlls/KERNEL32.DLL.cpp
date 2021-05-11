//
// Created by PinkySmile on 11/05/2021.
//

#include "KERNEL32.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	DLLKERNEL32 &kernel32 = *reinterpret_cast<DLLKERNEL32 *>(ADDR_KERNEL32_DLL);
}