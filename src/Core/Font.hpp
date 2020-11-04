//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_FONT_HPP
#define SOKULIB_FONT_HPP


//From swrs.h (SWRSToys)

#include <Windows.h>
#include "SokuFct.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �t�H���g�f�B�X�N���v�^
	#pragma pack(push, 4)
	struct FontDescription {
		char faceName[0x100];
		BYTE r1;
		BYTE r2;
		BYTE g1;
		BYTE g2;
		BYTE b1;
		BYTE b2;
		LONG height;
		LONG weight;
		BYTE italic;
		BYTE shadow;
		BYTE useOffset;
		DWORD bufferSize;
		DWORD offsetX;
		DWORD offsetY;
		DWORD charSpaceX;
		DWORD charSpaceY;
	};
	#pragma pack(pop)

	// �t�H���g�I�u�W�F�N�g���\�b�h
	__forceinline void SWRFont_Create(void *p)
	{
		SokuLib_Ccall(p, ADDR_SWR_FONT_CREATE, void, ())();
	}

	__forceinline void SWRFont_Destruct(void *p)
	{
		SokuLib_Ccall(p, ADDR_SWR_FONT_DESTRUCT, void, ())();
	}

	__forceinline void SWRFont_SetIndirect(void *p, void *pdesc)
	{
		SokuLib_Ccall(p, ADDR_SWR_FONT_SET_INDIRECT, void, (void * ))(pdesc);
	}

	// �f�t�H���g�t�H���g��
	__forceinline const char *getDefaultFontName()
	{
		return reinterpret_cast<const char *>(ADDR_DEFAULT_FONT_NAME);
	}
}


#endif //SOKULIB_FONT_HPP
