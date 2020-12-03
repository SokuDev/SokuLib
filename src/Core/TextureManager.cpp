//
// Created by PinkySmile on 02/12/2020.
//

#include <Windows.h>
#include "TextureManager.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �e�N�X�`���}�l�[�W�����\�b�h
	int *(TextureManager::* const CTextureManager_LoadTexture)(int *ret, LPCSTR path, void *unk1, void *unk2)
		= union_cast<int *(TextureManager::*)(int *, LPCSTR, void *, void *)>(ADDR_TEXTURE_MANAGER_LOAD_TEXTURE);
	int *(TextureManager::* const CTextureManager_CreateTextTexture)(int *ret, LPCSTR str, void *pdesc, int width, int height, int *p1, int *p2)
		= union_cast<int *(TextureManager::*)(int *, LPCSTR, void *, int, int, int *, int *)>(ADDR_TEXTURE_MANAGER_CREATE_TEXT);
	void *(TextureManager::* const CTextureManager_Remove)(int id)
		= union_cast<void *(TextureManager::*)(int)>(ADDR_TEXTURE_MANAGER_REMOVE);
	void (TextureManager::* const CTextureManager_SetTexture)(int id, int stage)
		= union_cast<void (TextureManager::*)(int, int)>(ADDR_TEXTURE_MANAGER_SET_TEXTURE);
	void (TextureManager::* const CTextureManager_GetSize)(int *w, int *h)
		= union_cast<void (TextureManager::*)(int *, int *)>(ADDR_TEXTURE_MANAGER_GET_SIZE);
	IDirect3DTexture9 **(* const CTextureManager_Allocate)(void *p, int *id) = reinterpret_cast<IDirect3DTexture9 **(*)(void *, int *)>(CHandleManager_Allocate);
	void (* const CTextureManager_Deallocate)(void *p, int id) = CHandleManager_Deallocate;

	// �l�b�g�ΐ펞�v���t�@�C�����\���֐����Ăяo���Ă���A�h���X
	char (&getProfile1NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1]
		= *reinterpret_cast<char (*)[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1]>(ADDR_PROFILENAME_PRINT_CODE1);

	char (&getProfile2NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2]
		= *reinterpret_cast<char (*)[ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2]>(ADDR_PROFILENAME_PRINT_CODE2);

	// �e�N�X�`���}�l�[�W��
	// CHandleManager<IDirect3DTexture *>
	IDirect3DTexture9 &textureMgr = *reinterpret_cast<IDirect3DTexture9 *>(ADDR_TEXTURE_MANAGER);

	// Direct3D�f�o�C�X
	// IDirect3DDevice9*
	IDirect3DDevice9 *(&pd3dDev) = *reinterpret_cast<IDirect3DDevice9 **>(ADDR_D3D9_DEVICE);

	// �����_��
	// CRenderer
	Renderer &renderer = *reinterpret_cast<Renderer *>(ADDR_RENDERER);
}