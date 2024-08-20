//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_FONT_HPP
#define SOKULIB_FONT_HPP


#include <Windows.h>
#include "String.hpp"
#include "Vector2.hpp"

namespace SokuLib
{
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
		HDC hdc;
		HFONT font;
		HGDIOBJ gdiobj;
		FontDescription description; // sizeof = 0x128
		Vector2i cursor;
		LONG tmAscent;
		void* output1;
		void* output2;
		int maxHeight, maxWidth;
		int lineWidth;
		void* gradient1;
		void* gradient2;
		char unknown15C[0xC]; // this is probably a list or stack
		unsigned int singleColor;
		bool inAccentTag;
		bool inRubyTag;
		// align 0x2
		String rubyParam; // sizeof = 0x1c
		char unknown18C[0x8]; // final object size may be 0x18C or 0x194

		void create();
		void destruct();
		void setIndirect(const FontDescription &pdesc);
	};


	extern const char * const defaultFontName;
}


#endif //SOKULIB_FONT_HPP
