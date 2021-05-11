//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_IMAGEHLP_DLL_HPP
#define SOKULIB_IMAGEHLP_DLL_HPP

#include <windows.h>

namespace SokuLib::DLL
{
	struct DLLIMAGEHLP {
		BOOL (__stdcall *MakeSureDirectoryPathExists)(PCSTR DirPath);
	};
	extern DLLIMAGEHLP &imagehlp;
}

#endif //SOKULIB_IMAGEHLP_DLL_HPP
