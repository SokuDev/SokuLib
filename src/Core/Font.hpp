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

	struct SWRFont {
		char data[0x1A4];

		// �t�H���g�I�u�W�F�N�g���\�b�h
		void create();
		void destruct();
		void setIndirect(const FontDescription &pdesc);
	};


	// �f�t�H���g�t�H���g��
	extern const char * const defaultFontName;
}


#endif //SOKULIB_FONT_HPP
