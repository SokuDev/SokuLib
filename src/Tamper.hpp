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

		void _placeCCall(size_t &index, unsigned char *buffer, int target, const std::vector<unsigned char> *extra)
		{
			// TODO: Saving only caller saved registers should be enough
			//       As the target is meant to be a void() function
			if (extra)
				for (auto c : *extra)
					buffer[index++] = c;

			buffer[index++] = 0x50; // push eax
			buffer[index++] = 0x57; // push edi
			buffer[index++] = 0x51; // push ecx
			buffer[index++] = 0x56; // push esi
			buffer[index++] = 0x53; // push ebx
			buffer[index++] = 0x52; // push edx

			buffer[index] = 0xE8; // call target
			*(int *)&buffer[index + 1] = (int)target - (int)(buffer + index + 5);
			index += 5;

			buffer[index++] = 0x5A; // pop edx
			buffer[index++] = 0x5B; // pop ebx
			buffer[index++] = 0x5E; // pop esi
			buffer[index++] = 0x59; // pop ecx
			buffer[index++] = 0x5F; // pop edi
			buffer[index++] = 0x58; // pop eax
		}

	public:
		unsigned char *getTrampoline()
		{
			return this->_trampoline;
		}

		const unsigned char *getTrampoline() const
		{
			return this->_trampoline;
		}

		Trampoline(unsigned addr, void (*target)(), int offset, const std::vector<unsigned char> *extra = nullptr, bool execCodeAfterHook = false, bool placeJumpAtEnd = false) :
			_base(addr),
			_offset(offset)
		{
			assert(target);
			assert(offset >= 5);

			auto lpAddr = (unsigned char *)addr;
			auto lpTramp = new unsigned char[offset + 22];
			DWORD dwOldProtect;
			size_t index = 0;

			if (execCodeAfterHook) {
				memcpy(&lpTramp[index], lpAddr, offset);
				index += offset;
			}

			this->_placeCCall(index, lpTramp, (int)target, extra);

			if (!execCodeAfterHook) {
				memcpy(&lpTramp[index], lpAddr, offset);
				index += offset;
			}

			lpTramp[index++] = 0xE9; // jmp addr + offset
			*(int *)&lpTramp[index] = (int)(addr + offset) - (int)(lpTramp + index + 4);
			::VirtualProtect(lpTramp, index, PAGE_EXECUTE_READWRITE, &dwOldProtect);

			::VirtualProtect(lpAddr, offset, PAGE_EXECUTE_READWRITE, &dwOldProtect);
			memset(lpAddr, 0x90, offset);
			if (placeJumpAtEnd) {
				lpAddr[offset - 5] = 0xE9; // jmp trampoline
				*(int *)&lpAddr[offset - 4] = (int)lpTramp - (int)&lpAddr[offset - 5] - 5;
			} else {
				lpAddr[0] = 0xE9; // jmp trampoline
				*(int *)&lpAddr[1] = (int)lpTramp - (int)lpAddr - 5;
			}
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
	};
}


#endif //SOKULIB_TAMPER_HPP
