#ifndef SOKULIB_SOUNDDATA_HPP
#define SOKULIB_SOUNDDATA_HPP

#include "SokuAddresses.hpp"
#include "IFileReader.hpp"
#include "String.hpp"

namespace SokuLib
{
	class SoundData {
	public:
		IFileReader* reader;
		int fileSize;
		char unknown[0x12e0];

		// 0x12e8
		double loopStart;
		double loopDuration;

		// WAVEFORMATEX
		WORD wFormatTag = WAVE_FORMAT_PCM;
		WORD nChannels;
		DWORD nSamplesPerSec;
		DWORD nAvgBytesPerSec;
		WORD nBlockAlign;
		WORD wBitsPerSample;
		WORD cbSize;
	};

	class DSBuffer {
	public:
		void** vtable; // for some reason the destructor is the second here
		// IDirectSoundBuffer8*
		void* dsHandle;
		int bufferSize;
		SoundData data;
	};

	class BgmBuffer {
	public:
		String filename;
		int unknown; // maybe current time
		bool isPlaying;
		// align 0x3
		DSBuffer dsBuffer;
	};
}


#endif //SOKULIB_SOUNDDATA_HPP
