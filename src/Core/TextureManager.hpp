//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_TEXTUREMANAGER_HPP
#define SOKULIB_TEXTUREMANAGER_HPP


#include <Windows.h>
#include "SokuFct.hpp"
#include "SokuAddresses.hpp"
#include "HandleManager.hpp"

struct IDirect3DDevice9;
struct IDirect3DTexture9;

namespace SokuLib
{
	struct Renderer {};
	struct TextureManager {};

	extern int *(TextureManager::* const CTextureManager_LoadTexture)(int *ret, LPCSTR path, void *unk1, void *unk2);
	extern int *(TextureManager::* const CTextureManager_CreateTextTexture)(int *ret, LPCSTR str, void *pdesc, int width, int height, int *p1, int *p2);
	extern void *(TextureManager::* const CTextureManager_Remove)(int id);
	extern void (TextureManager::* const CTextureManager_SetTexture)(int id, int stage);
	extern void (TextureManager::* const CTextureManager_GetSize)(int *w, int *h);
	extern void (* const CTextureManager_Deallocate)(void *p, int id);

	// �e�N�X�`���}�l�[�W�����\�b�h(�n���h���}�l�[�W������̌p��)
	//TODO: Remove template when the address is found
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline IDirect3DTexture9 **CTextureManager_Get(void *p, int id)
	{
		return CHandleManager_Get<IDirect3DTexture9 *>(p, id);
	}

	// �v���t�@�C���f�[�^���\�b�h
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline void Profile_RefreshStringTexture(void *p, int r, int g, int b)
	{
		//TODO: Add this for version 1.10a
		SokuLib_Ccall(p, ADDR_PROFILE_REFRESH_STR_TEXTURE, void, (int, int, int))(r, g, b);
	}

	extern char (&getProfile1NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1];
	extern char (&getProfile2NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2];

	extern IDirect3DTexture9 &textureMgr;
	extern IDirect3DDevice9 *(&pd3dDev);
	extern Renderer &renderer;
}


#endif //SOKULIB_TEXTUREMANAGER_HPP
