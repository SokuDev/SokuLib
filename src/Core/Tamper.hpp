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
}


#endif //SOKULIB_TAMPER_HPP
