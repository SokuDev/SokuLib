//
// Created by PinkySmile on 02/12/2020.
//

#include "NetObject.hpp"

namespace SokuLib
{
	NetObject &getNetObject()
	{
		return **reinterpret_cast<NetObject **>(ADDR_PNETOBJECT);
	}
}