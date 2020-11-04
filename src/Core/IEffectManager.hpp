//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_IEFFECTMANAGER_HPP
#define SOKULIB_IEFFECTMANAGER_HPP

//From swrs.h (SWRSToys)

#include <Windows.h>

namespace SokuLib
{
	#pragma pack(push, 4)
	struct __declspec(novtable) IEffectManager {
		virtual ~IEffectManager() {}
		virtual void LoadPattern(LPCSTR fileName, int) = 0;
		virtual void ClearPattern() = 0;
		virtual void AppendRegion(int arg_0, float arg_4, float arg_8, char arg_c, char arg_10, int arg_14) = 0;
		virtual void ClearRegion() = 0;
	};
	#pragma pack(pop)
}

#endif //SOKULIB_IEFFECTMANAGER_HPP
