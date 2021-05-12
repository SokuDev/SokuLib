//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_USER32_DLL_HPP
#define SOKULIB_USER32_DLL_HPP

#include <windows.h>

namespace SokuLib::DLL
{
	struct DLLUSER32 {
		int (__cdecl *wsprintfA)(LPSTR param_1, LPCSTR param_2, ...);
		BOOL (__stdcall *UpdateWindow)(HWND hWnd);
		BOOL (__stdcall *ShowWindow)(HWND hWnd, int nCmdShow);
		HWND (__stdcall *CreateWindowExA)(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
		ATOM (__stdcall *RegisterClassExA)(WNDCLASSEXA * param_1);
		HCURSOR (__stdcall *LoadCursorA)(HINSTANCE hInstance, LPCSTR lpCursorName);
		int (__stdcall *LoadStringA)(HINSTANCE hInstance, UINT uID, LPSTR lpBuffer, int cchBufferMax);
		BOOL (__stdcall *SetWindowPos)(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
		BOOL (__stdcall *GetWindowInfo)(HWND hwnd, PWINDOWINFO pwi);
		LONG (__stdcall *GetWindowLongA)(HWND hWnd, int nIndex);
		HDC (__stdcall *GetDC)(HWND hWnd);
		int (__stdcall *ReleaseDC)(HWND hWnd, HDC hDC);
		int (__stdcall *ToAscii)(UINT uVirtKey, UINT uScanCode, BYTE * lpKeyState, LPWORD lpChar, UINT uFlags);
		BOOL (__stdcall *GetWindowRect)(HWND hWnd, LPRECT lpRect);
		HANDLE (__stdcall *GetClipboardData)(UINT uFormat);
		BOOL (__stdcall *CloseClipboard)(void);
		BOOL (__stdcall *OpenClipboard)(HWND hWndNewOwner);
		BOOL (__stdcall *GetMessageA)(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
		int (__stdcall *ShowCursor)(BOOL bShow);
		BOOL (__stdcall *SetWindowTextA)(HWND hWnd, LPCSTR lpString);
		BOOL (__stdcall *PeekMessageA)(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
		LRESULT (__stdcall *DefWindowProcA)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		LRESULT (__stdcall *DispatchMessageA)(MSG * lpMsg);
		void (__stdcall *PostQuitMessage)(int nExitCode);
		BOOL (__stdcall *TranslateMessage)(MSG * lpMsg);
		HANDLE (__stdcall *LoadImageA)(HINSTANCE hInst, LPCSTR name, UINT type, int cx, int cy, UINT fuLoad);
		HICON (__stdcall *LoadIconA)(HINSTANCE hInstance, LPCSTR lpIconName);
		int (__stdcall *GetSystemMetrics)(int nIndex);
		LRESULT (__stdcall *SendMessageA)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		BOOL (__stdcall *SetRect)(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom);
		int (__stdcall *MessageBoxA)(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
	};
	extern DLLUSER32 &user32;
}

#endif //SOKULIB_USER32_DLL_HPP
