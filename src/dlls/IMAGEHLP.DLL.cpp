//
// Created by PinkySmile on 11/05/2021.
//

#include "IMAGEHLP.DLL.hpp"
#include "../SokuAddresses.hpp"

namespace SokuLib::DLL
{
	DLLIMAGEHLP &imagehlp = *reinterpret_cast<DLLIMAGEHLP *>(ADDR_IMAGEHLP_DLL);
}