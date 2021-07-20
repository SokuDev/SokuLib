//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_D3DX9_33_DLL_HPP
#define SOKULIB_D3DX9_33_DLL_HPP

#include <d3dx9.h>

namespace SokuLib::DLL
{
	struct DLLD3DX9_33 {
		HRESULT (__stdcall *D3DXCreateEffect)(LPDIRECT3DDEVICE9 pDevice, LPCVOID pSrcData, UINT SrcDataLen, const D3DXMACRO *pDefines, LPD3DXINCLUDE pInclude, DWORD Flags, LPD3DXEFFECTPOOL pPool, LPD3DXEFFECT *ppEffect, LPD3DXBUFFER *ppCompilationErrors);
		D3DXVECTOR2 *(__stdcall *D3DXVec2Hermite)(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV1, const D3DXVECTOR2 *pT1, const D3DXVECTOR2 *pV2, const D3DXVECTOR2 *pT2, FLOAT s);
		HRESULT (__stdcall *D3DXCreateTexture)(LPDIRECT3DDEVICE9 pDevice, UINT Width, UINT Height, UINT MipLevels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DTEXTURE9 *ppTexture);
		D3DXVECTOR2 *(__stdcall *D3DXVec2Normalize)(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV);
	};
	extern DLLD3DX9_33 &d3dx9_33;
}

#endif //SOKULIB_D3DX9_33_DLL_HPP
