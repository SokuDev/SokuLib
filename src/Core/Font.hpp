//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_FONT_HPP
#define SOKULIB_FONT_HPP


#include <Windows.h>

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

	struct SWRFont {};

	// �t�H���g�I�u�W�F�N�g���\�b�h
	extern void (__thiscall SWRFont::* const SWRFont_Create)();
	extern void (__thiscall SWRFont::* const SWRFont_Destruct)();
	extern void (__thiscall SWRFont::* const SWRFont_SetIndirect)(void *pdesc);

	// �f�t�H���g�t�H���g��
	extern const char * const defaultFontName;
}


#endif //SOKULIB_FONT_HPP
