//
// Created by PinkySmile on 11/05/2021.
//

#include "GDI32.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib
{
	namespace DLL
	{
		DLLGDI32 &gdi32 = *reinterpret_cast<DLLGDI32 *>(ADDR_GDI32_DLL);
	}
}