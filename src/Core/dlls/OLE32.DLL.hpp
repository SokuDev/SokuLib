//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_OLE32_DLL_HPP
#define SOKULIB_OLE32_DLL_HPP

#include <windows.h>

namespace SokuLib::DLL
{
	struct DLLOLE32 {
		HRESULT (__stdcall *CoInitialize)(LPVOID pvReserved);
		void (__stdcall *CoUninitialize)(void);
		HRESULT (__stdcall *CoCreateInstance)(IID * rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, IID * riid, LPVOID * ppv);
	};
	extern DLLOLE32 &ole32;
}

#endif //SOKULIB_OLE32_DLL_HPP
