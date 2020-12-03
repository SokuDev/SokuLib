//
// Created by PinkySmile on 02/12/2020.
//


#include "Renderer.hpp"
#include "SokuFct.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	extern bool (__thiscall Renderer::* const CRenderer_Begin)() = union_cast<bool (Renderer::*)()>(ADDR_RENDERER_BEGIN);
	extern void (__thiscall Renderer::* const CRenderer_End)()   = union_cast<void (Renderer::*)()>(ADDR_RENDERER_END);
}