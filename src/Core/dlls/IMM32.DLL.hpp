//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_IMM32_DLL_HPP
#define SOKULIB_IMM32_DLL_HPP

#include <windows.h>

namespace SokuLib::DLL
{
	struct DLLIMM32 {
		HIMC (__stdcall *ImmGetContext)(HWND param_1);
		BOOL (__stdcall *ImmReleaseContext)(HWND param_1, HIMC param_2);
		LONG (__stdcall *ImmGetCompositionStringA)(HIMC param_1, DWORD param_2, LPVOID lpBuf, DWORD dwBufLen);
		BOOL (__stdcall *ImmSetCandidateWindow)(HIMC param_1, LPCANDIDATEFORM lpCandidate);
	};

	extern DLLIMM32 &imm32;
}

#endif //SOKULIB_IMM32_DLL_HPP
