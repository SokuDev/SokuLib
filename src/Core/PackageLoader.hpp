//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_PACKAGELOADER_HPP
#define SOKULIB_PACKAGELOADER_HPP


//From swrs.h (SWRSToys)

#include <windows.h>
#include "SokuFct.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �p���b�g���[�h
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline void LoadPackagePalette(void *pflag, LPCSTR name, void *pal, int bpp)
	{
		SokuLib_Ccall(pflag, ADDR_LOAD_PACKAGE_PALETTE, void, (LPCSTR, void *, int))(name, pal, bpp);
	}

	// �f�[�^���[�h
	#ifndef SOKU_VER_110
	template<typename T = void>
	#endif
	__forceinline bool LoadPackageFile(void *ppfile, LPCSTR name)
	{
		return SokuLib_Ccall(ppfile, ADDR_LOAD_PACKAGE_FILE, bool, (LPCSTR))(name);
	}
}


#endif //SOKULIB_PACKAGELOADER_HPP
