//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_TEXTUREMANAGER_HPP
#define SOKULIB_TEXTUREMANAGER_HPP


#include <windows.h>
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"
#include "HandleManager.hpp"

struct IDirect3DDevice9;
struct IDirect3DTexture9;

namespace SokuLib
{
	struct TextureManager : public HandleManager<IDirect3DTexture9 *> {
		int *loadTexture(int *ret, LPCSTR path, void *width, void *height);
		int *createTextTexture(int *ret, LPCSTR str, struct SWRFont &font, int width, int height, int *realWidth, int *realHeight);
		void *remove(int id);
		void setTexture(int id, int stage);
		void getSize(int *w, int *h);
		IDirect3DTexture9 **toIDirect3DTexture9Array();
		IDirect3DTexture9 **allocate(int *handle);
		void deallocate(int handle);

		int *loadSound(int *ret, LPCSTR path);
		void playSound(int id);
		void removeSound(int id);
	};

	extern char (&getProfile1NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE1_END - ADDR_PROFILENAME_PRINT_CODE1];
	extern char (&getProfile2NamePrintCode)[ADDR_PROFILENAME_PRINT_CODE2_END - ADDR_PROFILENAME_PRINT_CODE2];

	extern TextureManager &textureMgr;
	extern IDirect3DDevice9 *(&pd3dDev);

	extern HWND &window;

	extern bool (* const appendDatFile)(const char*);
}


#endif //SOKULIB_TEXTUREMANAGER_HPP
