//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_RENDERER_HPP
#define SOKULIB_RENDERER_HPP


namespace SokuLib
{
	struct Renderer {};

	extern bool (__thiscall Renderer::* const CRenderer_Begin)();
	extern void (__thiscall Renderer::* const CRenderer_End)();
}


#endif //SOKULIB_RENDERER_HPP
