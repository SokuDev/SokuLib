//
// Created by PinkySmile on 20/07/2021.
//

#include "Misc.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	bool &SWRUnlinked = *reinterpret_cast<bool *>(ADDR_SWR_UNLINKED);
	unsigned int rand(unsigned int v) { if (v == 0) return 0; return reinterpret_cast<unsigned int(*)(unsigned int)>(0x4099f0)(v); }
	unsigned int rand() { return reinterpret_cast<unsigned int(*)()>(0x4098d0)(); }
	float cos(float angle) { return reinterpret_cast<float(*)(float)>(0x4095f0)(angle); }
	float sin(float angle) { return reinterpret_cast<float(*)(float)>(0x409580)(angle); }
}