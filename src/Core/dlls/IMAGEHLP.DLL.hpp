//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SWRSTOYS_IMAGEHLP_DLL_HPP
#define SWRSTOYS_IMAGEHLP_DLL_HPP

#include <windows.h>

namespace SokuLib::DLL
{
	struct DLLIMAGEHLP {
		BOOL (__stdcall *MakeSureDirectoryPathExists)(PCSTR DirPath);
	};
	extern DLLIMAGEHLP &imagehlp;
}

#endif //SWRSTOYS_IMAGEHLP_DLL_HPP
