//
// Created by PinkySmile on 11/05/2021.
//

#include "D3DX9_33.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	DLLD3DX9_33 &d3dx9_33 = *reinterpret_cast<DLLD3DX9_33 *>(ADDR_D3DX9_33_DLL);
}