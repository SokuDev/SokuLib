//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_SOUNDMANAGER_HPP
#define SOKULIB_SOUNDMANAGER_HPP
#include "HandleManager.hpp"
#include "dsound.h"

namespace SokuLib
{
	// SE�Đ�
	extern void (* const playSEWaveBuffer)(int id);
	extern void (* const playNetBell)(int id);

	static void playBGM(const char *path)
	{
		((void (*)(const char *))0x43ff10)(path);
	}

	class WaveBuffer{};
	class DSBuffer {
	public:
		IDirectSoundBuffer * pIDirectSoundBuffer = 0;
		uint32_t sizeToLock = 0;
		virtual void Initialize(LPWAVEFORMATEX waveformatex, DWORD bufSize);
		virtual void Delete(bool free);
	};
	class DS3DBuffer : public DSBuffer {
	public:
		IDirectSound3DBuffer * pIDirectSound3DBuffer;
		void Initialize(LPWAVEFORMATEX waveformatex, DWORD bufSize);
		void Delete(bool free);
	};
	class SoundManager : public HandleManager<class WaveBuffer *> {
	public:
		HandleManager<class DSBuffer *> DSBufferManager;
		DSBuffer DSBuffers[32];
		DS3DBuffer DS3DBuffer[32];
		char unknown[8];
		float SEVolume;
		float SEVolumeCoefficient;
		bool SetVolumeByDSBufferManagerID(unsigned int id);
	};
	extern int (__stdcall *const ConvertFloatVolumeToDSoundVolume)(float volume);
	extern SoundManager &soundMgr;
}



#endif //SOKULIB_SOUNDMANAGER_HPP
