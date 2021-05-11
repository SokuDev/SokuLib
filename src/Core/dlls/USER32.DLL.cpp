//
// Created by PinkySmile on 11/05/2021.
//

#include "USER32.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	extern DLLUSER32 &user32 = *reinterpret_cast<DLLUSER32 *>(ADDR_USER32_DLL);
}