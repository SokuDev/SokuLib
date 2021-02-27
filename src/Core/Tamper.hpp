//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_TAMPER_HPP
#define SOKULIB_TAMPER_HPP


#include <windows.h>

namespace SokuLib
{
	// DWORD��������
	inline DWORD TamperDword(DWORD addr, DWORD target) {
		DWORD old = *reinterpret_cast<PDWORD>(addr);
		*reinterpret_cast<PDWORD>(addr) = target;
		return old;
	}

	// DWORD���Z
	inline DWORD TamperDwordAdd(DWORD addr, DWORD delta) {
		DWORD old = *reinterpret_cast<PDWORD>(addr);
		*reinterpret_cast<PDWORD>(addr) += delta;
		return old;
	}

	// NEAR JMP�I�y�����h��������
	inline DWORD TamperNearJmpOpr(DWORD addr, DWORD target) {
		DWORD old = *reinterpret_cast<PDWORD>(addr + 1) + (addr + 5);
		*reinterpret_cast<PDWORD>(addr + 1) = target - (addr + 5);
		return old;
	}

	// NEAR JMP��������
	inline void TamperNearJmp(DWORD addr, DWORD target) {
		*reinterpret_cast<PBYTE>(addr + 0) = 0xE9;
		TamperNearJmpOpr(addr, target);
	}

	// NEAR CALL��������
	inline void TamperNearCall(DWORD addr, DWORD target) {
		*reinterpret_cast<PBYTE>(addr + 0) = 0xE8;
		TamperNearJmpOpr(addr, target);
	}

	// Trampoline - can hook function entries so all calls run the custom code
	//   addr - address where to insert code
	//   target - address of the custom code
	//   offset - how many bytes to replace, used to align assembly OPs,
	//          minimal required offset is 5(five)
	//   return - allocated data that runs the original code.
	DWORD TrampolineCreate(DWORD addr, DWORD target, int offset) {
		char* lpAddr = (char*)addr;
		char* lpTramp = new char[offset + 5];
		DWORD tramp = (DWORD) lpTramp;
		DWORD dwOldProtect;

		for (int i = 0; i < offset; ++i) *lpTramp++ = *lpAddr++;
		*lpTramp++ = 0xE9;
		*(int*)lpTramp = (int)addr - (int)tramp - 5;
		::VirtualProtect(reinterpret_cast<LPVOID>(tramp), offset+5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		::VirtualProtect(reinterpret_cast<LPVOID>(addr), offset, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		*(char*)addr = 0xE9;
		*(int*)(addr + 1) = (int)target - (int)addr - 5;
		::VirtualProtect(reinterpret_cast<LPVOID>(addr), offset, dwOldProtect, &dwOldProtect);

		::FlushInstructionCache(GetCurrentProcess(), 0, 0);
		return tramp;
	}

	// Remove a trampoline
	//   addr - address where to insert code
	//   tramp - value returned by the Create function
	//   offset - same offset as the Create function
	void TrampolineRemove(DWORD addr, DWORD tramp, int offset) {
		char* lpAddr = (char*)addr;
		char* lpTramp = (char*)tramp;
		DWORD dwOldProtect;

		::VirtualProtect(reinterpret_cast<LPVOID>(addr), offset, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		for (int i = 0; i < offset; ++i) *lpAddr++ = *lpTramp++;
		::VirtualProtect(reinterpret_cast<LPVOID>(addr), offset, dwOldProtect, &dwOldProtect);

		::VirtualProtect(reinterpret_cast<LPVOID>(tramp), offset+5, PAGE_READWRITE, &dwOldProtect);
		::FlushInstructionCache(GetCurrentProcess(), 0, 0);
		delete[] (char*)tramp;
	}
}


#endif //SOKULIB_TAMPER_HPP
