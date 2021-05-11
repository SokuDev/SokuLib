//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_KERNEL32_DLL_HPP
#define SOKULIB_KERNEL32_DLL_HPP

#include <windows.h>

namespace SokuLib::DLL
{
	struct DLLKERNEL32 {
		BOOL (__stdcall *SetCurrentDirectoryA)(LPCSTR lpPathName);
		DWORD (__stdcall *GetModuleFileNameA)(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
		DWORD (__stdcall *GetLastError)(void);
		HANDLE (__stdcall *CreateMutexA)(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName);
		BOOL (__stdcall *SetEvent)(HANDLE hEvent);
		BOOL (__stdcall *MoveFileA)(LPCSTR lpExistingFileName, LPCSTR lpNewFileName);
		BOOL (__stdcall *CopyFileA)(LPCSTR lpExistingFileName, LPCSTR lpNewFileName, BOOL bFailIfExists);
		BOOL (__stdcall *DeleteFileA)(LPCSTR lpFileName);
		DWORD (__stdcall *GetFileAttributesA)(LPCSTR lpFileName);
		BOOL (__stdcall *CreateDirectoryA)(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
		HANDLE (__stdcall *FindFirstFileA)(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
		BOOL (__stdcall *FindNextFileA)(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
		BOOL (__stdcall *FindClose)(HANDLE hFindFile);
		LONG (__stdcall *InterlockedCompareExchange)(LONG * Destination, LONG Exchange, LONG Comperand);
		BOOL (__stdcall *GetStringTypeExA)(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
		BOOL (__stdcall *SetEnvironmentVariableA)(LPCSTR lpName, LPCSTR lpValue);
		BOOL (__stdcall *WriteFile)(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
		DWORD (__stdcall *GetFileSize)(HANDLE hFile, LPDWORD lpFileSizeHigh);
		int (__stdcall *CompareStringW)(LCID Locale, DWORD dwCmpFlags, PCNZWCH lpString1, int cchCount1, PCNZWCH lpString2, int cchCount2);
		int (__stdcall *CompareStringA)(LCID Locale, DWORD dwCmpFlags, PCNZCH lpString1, int cchCount1, PCNZCH lpString2, int cchCount2);
		BOOL (__stdcall *WriteConsoleW)(HANDLE hConsoleOutput, void * lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved);
		UINT (__stdcall *GetConsoleOutputCP)(void);
		BOOL (__stdcall *WriteConsoleA)(HANDLE hConsoleOutput, void * lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved);
		BOOL (__stdcall *FlushFileBuffers)(HANDLE hFile);
		LCID (__stdcall *GetUserDefaultLCID)(void);
		DWORD (__stdcall *SetFilePointer)(HANDLE hFile, LONG lDistanceToMove, PLONG lpDistanceToMoveHigh, DWORD dwMoveMethod);
		BOOL (__stdcall *ReadFile)(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
		HANDLE (__stdcall *CreateFileA)(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
		DWORD (__stdcall *WaitForSingleObject)(HANDLE hHandle, DWORD dwMilliseconds);
		BOOL (__stdcall *CloseHandle)(HANDLE hObject);
		HANDLE (__stdcall *CreateEventA)(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCSTR lpName);
		BOOL (__stdcall *GetStringTypeW)(DWORD dwInfoType, LPCWSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
		BOOL (__stdcall *GetStringTypeA)(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType);
		int (__stdcall *GetLocaleInfoA)(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData);
		HMODULE (__stdcall *LoadLibraryA)(LPCSTR lpLibFileName);
		LONG (__stdcall *InterlockedExchange)(LONG * Target, LONG Value);
		BOOL (__stdcall *FreeLibrary)(HMODULE hLibModule);
		BOOL (__stdcall *GetConsoleMode)(HANDLE hConsoleHandle, LPDWORD lpMode);
		UINT (__stdcall *GetConsoleCP)(void);
		BOOL (__stdcall *SetStdHandle)(DWORD nStdHandle, HANDLE hHandle);
		int (__stdcall *LCMapStringW)(LCID Locale, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest);
		int (__stdcall *MultiByteToWideChar)(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
		LPVOID (__stdcall *VirtualAlloc)(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
		DWORD (__stdcall *GetCurrentProcessId)(void);
		DWORD (__stdcall *GetTickCount)(void);
		BOOL (__stdcall *QueryPerformanceCounter)(LARGE_INTEGER * lpPerformanceCount);
		BOOL (__stdcall *VirtualFree)(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
		HANDLE (__stdcall *HeapCreate)(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
		BOOL (__stdcall *HeapDestroy)(HANDLE hHeap);
		DWORD (__stdcall *GetFileType)(HANDLE hFile);
		UINT (__stdcall *SetHandleCount)(UINT uNumber);
		LPWCH (__stdcall *GetEnvironmentStringsW)(void);
		BOOL (__stdcall *FreeEnvironmentStringsW)(LPWCH param_1);
		LPCH (__stdcall *GetEnvironmentStrings)(void);
		BOOL (__stdcall *GetVersionExA)(LPOSVERSIONINFOA lpVersionInformation);
		BOOL (__stdcall *TryEnterCriticalSection)(LPCRITICAL_SECTION lpCriticalSection);
		void (__stdcall *InitializeCriticalSection)(LPCRITICAL_SECTION lpCriticalSection);
		void (__stdcall *LeaveCriticalSection)(LPCRITICAL_SECTION lpCriticalSection);
		void (__stdcall *EnterCriticalSection)(LPCRITICAL_SECTION lpCriticalSection);
		void (__stdcall *DeleteCriticalSection)(LPCRITICAL_SECTION lpCriticalSection);
		LPVOID (__stdcall *GlobalLock)(HGLOBAL hMem);
		BOOL (__stdcall *GlobalUnlock)(HGLOBAL hMem);
		DWORD (__stdcall *GetPrivateProfileStringA)(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpDefault, LPSTR lpReturnedString, DWORD nSize, LPCSTR lpFileName);
		DWORD (__stdcall *GetCurrentDirectoryA)(DWORD nBufferLength, LPSTR lpBuffer);
		UINT (__stdcall *GetPrivateProfileIntA)(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault, LPCSTR lpFileName);
		BOOL (__stdcall *SetThreadPriority)(HANDLE hThread, int nPriority);
		BOOL (__stdcall *GetExitCodeThread)(HANDLE hThread, LPDWORD lpExitCode);
		HANDLE (__stdcall *CreateThread)(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
		void (__stdcall *ExitProcess)(UINT uExitCode);
		int (__stdcall *lstrlenA)(LPCSTR lpString);
		void (__stdcall *RtlUnwind)(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue);
		BOOL (__stdcall *TerminateProcess)(HANDLE hProcess, UINT uExitCode);
		HANDLE (__stdcall *GetCurrentProcess)(void);
		LONG (__stdcall *UnhandledExceptionFilter)(_EXCEPTION_POINTERS * ExceptionInfo);
		LPTOP_LEVEL_EXCEPTION_FILTER (__stdcall *SetUnhandledExceptionFilter)(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);
		BOOL (__stdcall *IsDebuggerPresent)(void);
		void (__stdcall *RaiseException)(DWORD dwExceptionCode, DWORD dwExceptionFlags, DWORD nNumberOfArguments, ULONG_PTR * lpArguments);
		void (__stdcall *GetSystemTimeAsFileTime)(LPFILETIME lpSystemTimeAsFileTime);
		LPSTR (__stdcall *GetCommandLineA)(void);
		BOOL (__stdcall *HeapFree)(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
		LPVOID (__stdcall *HeapAlloc)(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
		HANDLE (__stdcall *GetProcessHeap)(void);
		void (__stdcall *GetStartupInfoA)(LPSTARTUPINFOA lpStartupInfo);
		LPVOID (__stdcall *HeapReAlloc)(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);
		FARPROC (__stdcall *GetProcAddress)(HMODULE hModule, LPCSTR lpProcName);
		HMODULE (__stdcall *GetModuleHandleA)(LPCSTR lpModuleName);
		HANDLE (__stdcall *GetStdHandle)(DWORD nStdHandle);
		LPVOID (__stdcall *TlsGetValue)(DWORD dwTlsIndex);
		DWORD (__stdcall *TlsAlloc)(void);
		BOOL (__stdcall *TlsSetValue)(DWORD dwTlsIndex, LPVOID lpTlsValue);
		BOOL (__stdcall *TlsFree)(DWORD dwTlsIndex);
		LONG (__stdcall *InterlockedIncrement)(LONG * lpAddend);
		void (__stdcall *SetLastError)(DWORD dwErrCode);
		DWORD (__stdcall *GetCurrentThreadId)(void);
		LONG (__stdcall *InterlockedDecrement)(LONG * lpAddend);
		BOOL (__stdcall *GetCPInfo)(UINT CodePage, LPCPINFO lpCPInfo);
		UINT (__stdcall *GetACP)(void);
		UINT (__stdcall *GetOEMCP)(void);
		BOOL (__stdcall *IsValidCodePage)(UINT CodePage);
		int (__stdcall *WideCharToMultiByte)(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte, LPCSTR lpDefaultChar, LPBOOL lpUsedDefaultChar);
		DWORD (__stdcall *GetTimeZoneInformation)(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
		void (__stdcall *Sleep)(DWORD dwMilliseconds);
		SIZE_T (__stdcall *HeapSize)(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);
		BOOL (__stdcall *FreeEnvironmentStringsA)(LPCH param_1);
	};

	extern DLLKERNEL32 &kernel32;
}

#endif //SOKULIB_KERNEL32_DLL_HPP
