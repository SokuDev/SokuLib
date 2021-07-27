//
// Created by PinkySmile on 02/12/2020.
//


#include "SokuAddresses.hpp"
#include "Memory.hpp"

namespace SokuLib
{
	void *(* const NewFct)(size_t size) = reinterpret_cast<void *(__cdecl *)(size_t)>(ADDR_NEW_FUNCTION);
	void (* const DeleteFct)(void *p) = reinterpret_cast<void (__cdecl *)(void *)>(ADDR_DELETE_FUNCTION);
}