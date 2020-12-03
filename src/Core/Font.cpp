//
// Created by PinkySmile on 02/12/2020.
//

#include "Font.hpp"
#include "SokuFct.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �f�t�H���g�t�H���g��
	const char * const defaultFontName = reinterpret_cast<const char *>(ADDR_DEFAULT_FONT_NAME);

	// �t�H���g�I�u�W�F�N�g���\�b�h
	void (__thiscall SWRFont::* const SWRFont_Create)()                 = union_cast<void (SWRFont::*)()>(static_cast<unsigned int>(ADDR_SWR_FONT_CREATE));
	void (__thiscall SWRFont::* const SWRFont_Destruct)()               = union_cast<void (SWRFont::*)()>(static_cast<unsigned int>(ADDR_SWR_FONT_DESTRUCT));
	void (__thiscall SWRFont::* const SWRFont_SetIndirect)(void *pdesc) = union_cast<void (SWRFont::*)(void *)>(static_cast<unsigned int>(ADDR_SWR_FONT_SET_INDIRECT));
}