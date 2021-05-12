//
// Created by PinkySmile on 11/05/2021.
//

#include "D3D9.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	DLLD3D9 &d3d9 = *reinterpret_cast<DLLD3D9 *>(ADDR_D3D9_DLL);
}