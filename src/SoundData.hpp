#ifndef SOKULIB_SOUNDDATA_HPP
#define SOKULIB_SOUNDDATA_HPP

#include "SokuAddresses.hpp"
#include "IFileReader.hpp"
#include "String.hpp"

namespace SokuLib
{
	class BgmData {
	public:
		IFileReader* reader;
		int fileSize;
		int unknown0x8; // probably fileOffset
		int unknown0xc;
		char oggVorbisFile[0x2d0]; // unsure of size
		int pcmLength;
		char unknown[0x1004];

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

	class WaveData {
	public:
		// WAVEFORMATEX
		WORD wFormatTag = WAVE_FORMAT_PCM;
		WORD nChannels;
		DWORD nSamplesPerSec;
		DWORD nAvgBytesPerSec;
		WORD nBlockAlign;
		WORD wBitsPerSample;
		WORD cbSize;
		// align 0x2

		void* buffer;
		unsigned int bufferSize;
	};

	class DSBuffer {
	public:
		void** vtable; // for some reason the destructor is the second here
		void* dsHandle; // IDirectSoundBuffer*
		int bufferSize;
	};

	class BgmBuffer {
	public:
		String filename;
		int unknown; // maybe current time
		bool isPlaying;
		// align 0x3

		DSBuffer dsBuffer;
		BgmData data;
	};
}


#endif //SOKULIB_SOUNDDATA_HPP
