//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_TAMPER_HPP
#define SOKULIB_TAMPER_HPP


#include <windows.h>
#include <cassert>

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

	template<typename R, typename ...Args>
	class Trampoline {
	private:
		R (*_base)(Args...);
		R (*_trampoline)(Args...);
		int _offset;

	public:
		Trampoline(R (*addr)(Args...), const unsigned char *target, int offset) :
			_base(addr),
			_offset(offset)
		{
			assert(target);
			assert(offset >= 5);

			auto lpAddr = (unsigned char *)addr;
			auto lpTramp = new unsigned char[offset + 5];
			DWORD dwOldProtect;

			memcpy(lpTramp, lpAddr, offset);
			lpTramp[offset] = 0xE9;
			*(int *)&lpTramp[offset + 1] = (int)addr - (int)lpTramp - 5;
			::VirtualProtect(lpTramp, offset + 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

			::VirtualProtect(lpAddr, offset, PAGE_EXECUTE_READWRITE, &dwOldProtect);
			*lpAddr = 0xE9;
			*(int *)(lpAddr + 1) = (int)target - (int)lpAddr - 5;
			::VirtualProtect(lpAddr, offset, dwOldProtect, &dwOldProtect);

			::FlushInstructionCache(GetCurrentProcess(), nullptr, 0);
			this->_trampoline = reinterpret_cast<R (*)(Args...)>(lpTramp);
		}

		~Trampoline() {
			auto lpAddr = (unsigned char *)this->_base;
			auto lpTramp = (unsigned char *)this->_trampoline;
			DWORD dwOldProtect;

			::VirtualProtect(lpAddr, this->_offset, PAGE_EXECUTE_READWRITE, &dwOldProtect);
			memcpy(lpAddr, lpTramp, this->_offset);
			::VirtualProtect(lpAddr, this->_offset, dwOldProtect, &dwOldProtect);

			::VirtualProtect(lpTramp, this->offset + 5, PAGE_READWRITE, &dwOldProtect);
			::FlushInstructionCache(GetCurrentProcess(), nullptr, 0);
			delete[] lpTramp;
		}

		R operator()(Args... args)
		{
			this->_trampoline(args...);
		}
	};
}


#endif //SOKULIB_TAMPER_HPP
