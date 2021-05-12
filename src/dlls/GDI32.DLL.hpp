//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_GDI32_DLL_HPP
#define SOKULIB_GDI32_DLL_HPP


#include <Windows.h>

namespace SokuLib
{
	namespace DLL
	{
		struct DLLGDI32 {
			BOOL (__stdcall *DeleteObject)(HGDIOBJ ho);
			HGDIOBJ (__stdcall *SelectObject)(HDC hdc, HGDIOBJ h);
			HGDIOBJ (__stdcall *GetStockObject)(int i);
			HFONT (__stdcall *CreateFontA)(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);
			BOOL (__stdcall *GetTextMetricsA)(HDC hdc, LPTEXTMETRICA lptm);
			DWORD (__stdcall *GetGlyphOutlineA)(HDC hdc, UINT uChar, UINT fuFormat, LPGLYPHMETRICS lpgm, DWORD cjBuffer, LPVOID pvBuffer, MAT2 * lpmat2);
		};

		extern DLLGDI32 &gdi32;
	}
}


#endif //SOKULIB_GDI32_DLL_HPP
