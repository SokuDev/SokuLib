//
// Created by PinkySmile on 20/07/2021.
//

#include "Misc.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	bool &SWRUnlinked = *reinterpret_cast<bool *>(ADDR_SWR_UNLINKED);
}