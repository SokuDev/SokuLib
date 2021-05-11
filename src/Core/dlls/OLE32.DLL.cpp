//
// Created by PinkySmile on 11/05/2021.
//

#include "OLE32.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	DLLOLE32 &ole32 = *reinterpret_cast<DLLOLE32 *>(ADDR_OLE32_DLL);
}