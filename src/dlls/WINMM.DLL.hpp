//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_WINMM_DLL_HPP
#define SOKULIB_WINMM_DLL_HPP

#include <windows.h>
#include <timeapi.h>

namespace SokuLib::DLL
{
	struct DLLWINMM32 {
		MMRESULT (__stdcall *timeBeginPeriod)(UINT uPeriod);
		DWORD (__stdcall *timeGetTime)(void);
	};
	extern DLLWINMM32 &winmm32;
}

#endif //SOKULIB_WINMM_DLL_HPP
