//
// Created by PinkySmile on 02/12/2020.
//

#include <Windows.h>
#include <string>
#include "TextureManager.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	char (&getProfile1NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1]
		= *reinterpret_cast<char (*)[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1]>(ADDR_PROFILENAME_PRINT_CODE1);

	char (&getProfile2NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2]
		= *reinterpret_cast<char (*)[ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2]>(ADDR_PROFILENAME_PRINT_CODE2);

	// CHandleManager<IDirect3DTexture *>
	TextureManager &textureMgr = *reinterpret_cast<TextureManager *>(ADDR_TEXTURE_MANAGER);

	// IDirect3DDevice9*
	IDirect3DDevice9 *(&pd3dDev) = *reinterpret_cast<IDirect3DDevice9 **>(ADDR_D3D9_DEVICE);

	HWND &window = *reinterpret_cast<HWND *>(ADDR_WINDOW_HWND);

	bool (* const appendDatFile)(const char*) = reinterpret_cast<bool (*)(const char*)>(ADDR_LOAD_DAT);

	int *TextureManager::loadTexture(int *ret, LPCSTR path, void *unk1, void *unk2)
	{
		return (this->*union_cast<int *(__thiscall TextureManager::*)(int *, LPCSTR, void *, void *)>(ADDR_TEXTURE_MANAGER_LOAD_TEXTURE))(ret, path, unk1, unk2);
	}

	int *TextureManager::createTextTexture(int *ret, LPCSTR str, SWRFont &font, int width, int height, int *p1, int *p2)
	{
		if (!strstr(str, "<>"))
			return (this->*union_cast<int *(__thiscall TextureManager::*)(int *, LPCSTR, SokuLib::SWRFont &, int, int, int *, int *)>(ADDR_TEXTURE_MANAGER_CREATE_TEXT))(ret, str, font, width, height, p1, p2);

		std::string sanStr = str;
		auto pos = sanStr.find("<>");

		//We need to sanitize the string first
		while (pos != std::string::npos) {
			sanStr.replace(pos, 2, "<\\>");
			pos = sanStr.find("<>");
		}
		return (this->*union_cast<int *(__thiscall TextureManager::*)(int *, LPCSTR, SokuLib::SWRFont &, int, int, int *, int *)>(ADDR_TEXTURE_MANAGER_CREATE_TEXT))(ret, sanStr.c_str(), font, width, height, p1, p2);
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

	IDirect3DTexture9 **TextureManager::toIDirect3DTexture9Array()
	{
		return reinterpret_cast<IDirect3DTexture9 **>(this);
	}

	int *TextureManager::loadSound(int *ret, LPCSTR path)
	{
		return (this->*union_cast<int *(__thiscall TextureManager::*)(int *, LPCSTR)>(ADDR_LOAD_SOUND))(ret, path);
	}

	void TextureManager::playSound(int id)
	{
		(this->*union_cast<void (__thiscall TextureManager::*)(int)>(ADDR_PLAY_SOUND))(id);
	}

	void TextureManager::removeSound(int id)
	{
		(this->*union_cast<void (__thiscall TextureManager::*)(int)>(ADDR_REMOVE_SOUND))(id);
	}

	IDirect3DTexture9 **TextureManager::allocate(int *handle)
	{
		return reinterpret_cast<IDirect3DTexture9 **(*)(TextureManager *, int *)>(CHandleManager_Allocate)(this, handle);
	}

	void TextureManager::deallocate(int handle)
	{
		reinterpret_cast<void (*)(TextureManager *, int id)>(CHandleManager_Deallocate)(this, handle);
	}
}