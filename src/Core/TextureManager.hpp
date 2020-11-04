//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_TEXTUREMANAGER_HPP
#define SOKULIB_TEXTUREMANAGER_HPP

// From swrs.h (SWRSToys)

#include <Windows.h>
#include "SokuFct.hpp"
#include "SokuAddresses.hpp"
#include "HandleManager.hpp"

struct IDirect3DDevice9;
struct IDirect3DTexture9;

namespace SokuLib
{
	// �e�N�X�`���}�l�[�W�����\�b�h
	__forceinline int *CTextureManager_LoadTexture(void *p, int *ret, LPCSTR path, void *unk1, void *unk2)
	{
		return SokuLib_Ccall(p, ADDR_TEXTURE_MANAGER_LOAD_TEXTURE, int *, (int *, LPCSTR, void *, void *))(ret, path, unk1, unk2);
	}

	__forceinline int *CTextureManager_CreateTextTexture(void *p, int *ret, LPCSTR str, void *pdesc, int width, int height, int *p1, int *p2)
	{
		return SokuLib_Ccall(p, ADDR_TEXTURE_MANAGER_CREATE_TEXT, int*,(int *, LPCSTR, void *, int, int, int *, int *))(ret, str, pdesc, width, height, p1, p2);
	}

	__forceinline void *CTextureManager_Remove(void *p, int id)
	{
		return SokuLib_Ccall(p, ADDR_TEXTURE_MANAGER_REMOVE, void *, (int))(id);
	}

	__forceinline void CTextureManager_SetTexture(void *p, int id, int stage)
	{
		SokuLib_Ccall(p, ADDR_TEXTURE_MANAGER_SET_TEXTURE, void, (int, int))(id, stage);
	}

	__forceinline void CTextureManager_GetSize(void *p, int *w, int *h)
	{
		SokuLib_Ccall(p, ADDR_TEXTURE_MANAGER_GET_SIZE, void, (int *, int *))(w, h);
	}

	// �e�N�X�`���}�l�[�W�����\�b�h(�n���h���}�l�[�W������̌p��)
	//TODO: Remove template when the address is found
	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline IDirect3DTexture9 **CTextureManager_Get(void *p, int id)
	{
		return CHandleManager_Get<IDirect3DTexture9 *>(p, id);
	}

	__forceinline IDirect3DTexture9 **CTextureManager_Allocate(void *p, int *id)
	{
		return reinterpret_cast<IDirect3DTexture9 **>(CHandleManager_Allocate(p, id));
	}

	__forceinline void CTextureManager_Deallocate(void *p, int id)
	{
		CHandleManager_Deallocate(p, id);
	}

	// �v���t�@�C���f�[�^���\�b�h
	#ifdef SOKU_VER_110a
	template<typename T = void>
	#endif
	__forceinline void Profile_RefreshStringTexture(void *p, int r, int g, int b)
	{
		SokuLib_Ccall(p, ADDR_PROFILE_REFRESH_STR_TEXTURE, void, (int, int, int))(r, g, b);
	}

	static_assert(
		ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1 ==
		ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2,
		"Profile name 1 and 2 print code don't have so the same size"
	);

	struct ProfileNameCode {
		char code[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1];
	};

	// �l�b�g�ΐ펞�v���t�@�C�����\���֐����Ăяo���Ă���A�h���X
	__forceinline ProfileNameCode *getProfileNamePrintCode1()
	{
		return reinterpret_cast<ProfileNameCode *>(ADDR_PROFILENAME_PRINT_CODE1);
	}

	__forceinline ProfileNameCode *getProfileNamePrintCode2()
	{
		return reinterpret_cast<ProfileNameCode *>(ADDR_PROFILENAME_PRINT_CODE2);
	}

	// �e�N�X�`���}�l�[�W��
	// CHandleManager<IDirect3DTexture *>
	__forceinline IDirect3DTexture9 *getTextureMgr()
	{
		return (reinterpret_cast<IDirect3DTexture9 *>(ADDR_TEXTURE_MANAGER));
	}

	// Direct3D�f�o�C�X
	// IDirect3DDevice9*
	__forceinline IDirect3DDevice9 *getPd3dDev()
	{
		return (*reinterpret_cast<IDirect3DDevice9 **>(ADDR_D3D9_DEVICE));
	}

	// �����_��
	// CRenderer
	__forceinline void *getRenderer()
	{
		return reinterpret_cast<void *>(ADDR_RENDERER);
	}
}

#endif //SOKULIB_TEXTUREMANAGER_HPP
