//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_TAMPER_HPP
#define SOKULIB_TAMPER_HPP


#include <windows.h>
#include <cassert>

namespace SokuLib
{
	// DWORD��������
	template<typename T, typename T2>
	inline T2 TamperDword(T2 *baseAddr, T target) {
		auto old = *reinterpret_cast<PDWORD>(baseAddr);

		*reinterpret_cast<PDWORD>(baseAddr) = *reinterpret_cast<PDWORD>(&target);
		return SokuLib::union_cast<T2>(old);
	}

	// DWORD��������
	template<typename T>
	inline T TamperDword(DWORD addr, T target) {
		auto old = *reinterpret_cast<PDWORD>(addr);

		*reinterpret_cast<PDWORD>(addr) = *reinterpret_cast<PDWORD>(&target);
		return SokuLib::union_cast<T>(old);
	}

	// DWORD���Z
	inline DWORD TamperDwordAdd(DWORD addr, DWORD delta) {
		DWORD old = *reinterpret_cast<PDWORD>(addr);

		*reinterpret_cast<PDWORD>(addr) += delta;
		return old;
	}

	// NEAR JMP�I�y�����h��������
	template<typename T>
	inline T TamperNearJmpOpr(DWORD addr, T targetFct) {
		auto target = SokuLib::union_cast<DWORD>(targetFct);
		DWORD old = *reinterpret_cast<PDWORD>(addr + 1) + (addr + 5);

		*reinterpret_cast<PDWORD>(addr + 1) = target - (addr + 5);
		return SokuLib::union_cast<T>(old);
	}

	// NEAR JMP��������
	template<typename T>
	inline T TamperNearJmp(DWORD addr, T target) {
		*reinterpret_cast<PBYTE>(addr + 0) = 0xE9;
		return TamperNearJmpOpr(addr, target);
	}

	// NEAR CALL��������
	template<typename T>
	inline T TamperNearCall(DWORD addr, T target) {
		*reinterpret_cast<PBYTE>(addr + 0) = 0xE8;
		return TamperNearJmpOpr(addr, target);
	}

	class Trampoline {
	private:
		unsigned char *_trampoline;
		unsigned _base;
		int _offset;

	public:
		unsigned char *getTrampoline()
		{
			return this->_trampoline;
		}

		const unsigned char *getTrampoline() const
		{
			return this->_trampoline;
		}

		Trampoline(unsigned addr, void (*target)(), int offset) :
			_base(addr),
			_offset(offset)
		{
			assert(target);
			assert(offset >= 5);

			auto lpAddr = (unsigned char *)addr;
			auto lpTramp = new unsigned char[offset + 22];
			DWORD dwOldProtect;

			lpTramp[0] = 0x50; // push eax
			lpTramp[1] = 0x57; // push edi
			lpTramp[2] = 0x51; // push ecx
			lpTramp[3] = 0x56; // push esi
			lpTramp[4] = 0x53; // push ebx
			lpTramp[5] = 0x52; // push edx

			lpTramp[6] = 0xE8; // call target
			*(int *)&lpTramp[7] = (int)target - (int)(lpTramp + 6 + 5);

			lpTramp[11] = 0x5A; // pop edx
			lpTramp[12] = 0x5B; // pop ebx
			lpTramp[13] = 0x5E; // pop esi
			lpTramp[14] = 0x59; // pop ecx
			lpTramp[15] = 0x5F; // pop edi
			lpTramp[16] = 0x58; // pop eax

			// Copy overwritten data
			memcpy(&lpTramp[17], lpAddr, offset);

			lpTramp[offset + 17] = 0xE9; // jmp addr + offset
			*(int *)&lpTramp[offset + 18] = (int)addr - (int)(lpTramp + 22);
			::VirtualProtect(lpTramp, offset + 22, PAGE_EXECUTE_READWRITE, &dwOldProtect);

			::VirtualProtect(lpAddr, offset, PAGE_EXECUTE_READWRITE, &dwOldProtect);
			*lpAddr = 0xE9; // jmp trampoline
			*(int *)(lpAddr + 1) = (int)lpTramp - (int)lpAddr - 5;
			::VirtualProtect(lpAddr, offset, dwOldProtect, &dwOldProtect);

			::FlushInstructionCache(GetCurrentProcess(), nullptr, 0);
			this->_trampoline = lpTramp;
		}

		~Trampoline() {
			auto lpAddr = (unsigned char *)this->_base;
			auto lpTramp = this->_trampoline;
			DWORD dwOldProtect;

			::VirtualProtect(lpAddr, this->_offset, PAGE_EXECUTE_READWRITE, &dwOldProtect);
			memcpy(lpAddr, &lpTramp[17], this->_offset);
			::VirtualProtect(lpAddr, this->_offset, dwOldProtect, &dwOldProtect);

			::VirtualProtect(lpTramp, this->_offset + 5, PAGE_READWRITE, &dwOldProtect);
			::FlushInstructionCache(GetCurrentProcess(), nullptr, 0);
			delete[] lpTramp;
		}

		template<typename fct, typename ...Args>
		auto operator()(Args ...args) {
			return reinterpret_cast<fct>(&this->_trampoline[17])(args...);
		}
	};
}


#endif //SOKULIB_TAMPER_HPP
