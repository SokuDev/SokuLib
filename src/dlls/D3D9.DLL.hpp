//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_D3D9_DLL_HPP
#define SOKULIB_D3D9_DLL_HPP

#include <d3d9.h>

namespace SokuLib::DLL
{
	struct DLLD3D9 {
		IDirect3D9 *(__stdcall *Direct3DCreate9)(unsigned SDKVersion);
	};
	extern DLLD3D9 &d3d9;
}

#endif //SOKULIB_D3D9_DLL_HPP
