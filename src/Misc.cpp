//
// Created by PinkySmile on 20/07/2021.
//

#include "Misc.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	bool &SWRUnlinked = *reinterpret_cast<bool *>(ADDR_SWR_UNLINKED);
	unsigned int Rand(unsigned int v) { if (v == 0) return 0; return reinterpret_cast<unsigned int(*)(unsigned int)>(0x4099f0)(v); }
}