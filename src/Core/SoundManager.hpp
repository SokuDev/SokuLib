//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_SOUNDMANAGER_HPP
#define SOKULIB_SOUNDMANAGER_HPP


//From swrs.h (SWRSToys)

#include "SokuAddresses.hpp"
#include "SokuFct.hpp"

namespace SokuLib
{
	// SE�Đ�
	__forceinline void PlaySEWaveBuffer(int id)
	{
		reinterpret_cast<void (*)(int id)>(ADDR_PLAY_SE_WAVE_BUFFER)(id);
	}

	__forceinline void PlayNetBell(int id)
	{
		reinterpret_cast<void (*)(int id)>(ADDR_PLAY_NET_BELL)(id);
	}

	// BGM�֘A�t�@�C���ǂݍ��݊֐��Ăяo���A�h���X
	enum {
		GetPackagedBGMCallerAddr = 0x00418BE1,
		GetPackagedSFLCallerAddr = 0x00418F41
	}
}



#endif //SOKULIB_SOUNDMANAGER_HPP
