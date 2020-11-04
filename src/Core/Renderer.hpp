//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_RENDERER_HPP
#define SOKULIB_RENDERER_HPP


//From swrs.h (SWRSToys)

#include "SokuFct.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �����_�����\�b�h
	__forceinline bool CRenderer_Begin(void *p)
	{
		return SokuLib_Ccall(p, ADDR_RENDERER_BEGIN, bool, ())();
	}

	__forceinline void CRenderer_End(void *p)
	{
		SokuLib_Ccall(p, ADDR_RENDERER_END, void, ())();
	}
}


#endif //SOKULIB_RENDERER_HPP
