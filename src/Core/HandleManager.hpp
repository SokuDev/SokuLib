//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_HANDLEMANAGER_HPP
#define SOKULIB_HANDLEMANAGER_HPP


#include "SokuFct.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	__declspec(naked) void **CHandleManager_Allocate(void *p, int *ret)
	{
		// thiscall�Ȃ̂ɗ�����Ǝv������edi���g���Ă����ł�����@�̊�
		__asm push edi
		__asm mov edi, [esp+8]
		__asm push [esp+12]
		__asm mov eax, ADDR_ALLOCATE_FUNCTION
		__asm call eax
		__asm pop edi
		__asm retn
	}

	__declspec(naked) void CHandleManager_Deallocate(void *p, int id)
	{
		// thiscall(����)eax���g���Ă����ł�����@�̊�
		__asm mov eax, [esp+4]
		__asm push [esp+8]
		__asm mov ecx, ADDR_DEALLOCATE_FUNCTION
		__asm call ecx
		__asm retn
	}

	// �n���h���}�l�[�W�����\�b�h
	template <typename T>
	inline T *CHandleManager_Get(void *p, int id)
	{
		//TODO: Find thi in version 1.10a
		return SokuLib_Ccall(p, ADDR_HANDLE_MANAGER_GET, T *, (int))(id);
	}
}


#endif //SOKULIB_HANDLEMANAGER_HPP
