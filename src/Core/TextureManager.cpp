//
// Created by PinkySmile on 02/12/2020.
//

#include <Windows.h>
#include "TextureManager.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �e�N�X�`���}�l�[�W�����\�b�h
	TextureManager *(* const CTextureManager_Allocate)(void *, int *) = reinterpret_cast<TextureManager *(*)(void *, int *)>(CHandleManager_Allocate);
	void (* const CTextureManager_Deallocate)(TextureManager &, int id) = reinterpret_cast<void (*)(TextureManager &, int id)>(CHandleManager_Deallocate);

	// �l�b�g�ΐ펞�v���t�@�C�����\���֐����Ăяo���Ă���A�h���X
	char (&getProfile1NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1]
		= *reinterpret_cast<char (*)[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1]>(ADDR_PROFILENAME_PRINT_CODE1);

	char (&getProfile2NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2]
		= *reinterpret_cast<char (*)[ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2]>(ADDR_PROFILENAME_PRINT_CODE2);

	// �e�N�X�`���}�l�[�W��
	// CHandleManager<IDirect3DTexture *>
	TextureManager &textureMgr = *reinterpret_cast<TextureManager *>(ADDR_TEXTURE_MANAGER);

	// Direct3D�f�o�C�X
	// IDirect3DDevice9*
	IDirect3DDevice9 *(&pd3dDev) = *reinterpret_cast<IDirect3DDevice9 **>(ADDR_D3D9_DEVICE);

	HWND &window = *reinterpret_cast<HWND *>(ADDR_WINDOW_HWND);

	int *TextureManager::loadTexture(int *ret, LPCSTR path, void *unk1, void *unk2)
	{
		return (this->*union_cast<int *(__thiscall TextureManager::*)(int *, LPCSTR, void *, void *)>(ADDR_TEXTURE_MANAGER_LOAD_TEXTURE))(ret, path, unk1, unk2);
	}

	int *TextureManager::createTextTexture(int *ret, LPCSTR str, void *pdesc, int width, int height, int *p1, int *p2)
	{
		return (this->*union_cast<int *(__thiscall TextureManager::*)(int *, LPCSTR, void *, int, int, int *, int *)>(ADDR_TEXTURE_MANAGER_CREATE_TEXT))(ret, str, pdesc, width, height, p1, p2);
	}

	void *TextureManager::remove(int id)
	{
		return (this->*union_cast<void *(__thiscall TextureManager::*)(int)>(ADDR_TEXTURE_MANAGER_REMOVE))(id);
	}

	void TextureManager::setTexture(int id, int stage)
	{
		(this->*union_cast<void (__thiscall TextureManager::*)(int, int)>(ADDR_TEXTURE_MANAGER_SET_TEXTURE))(id, stage);
	}

	void TextureManager::getSize(int *w, int *h)
	{
		(this->*union_cast<void (__thiscall TextureManager::*)(int *, int *)>(ADDR_TEXTURE_MANAGER_GET_SIZE))(w, h);
	}

	IDirect3DTexture9 *&TextureManager::toIDirect3DTexture9Array()
	{
		return *reinterpret_cast<IDirect3DTexture9 **>(this);
	}
}