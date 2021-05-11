//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SWRSTOYS_D3D9_DLL_HPP
#define SWRSTOYS_D3D9_DLL_HPP

#include "directx/d3d9.h"

namespace SokuLib::DLL
{
	struct DLLD3D9 {
		IDirect3D9 *(__stdcall *Direct3DCreate9)(unsigned SDKVersion);
	};
	extern DLLD3D9 &d3d9;
}

#endif //SWRSTOYS_D3D9_DLL_HPP
