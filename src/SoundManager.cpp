//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"
#include "SoundManager.hpp"

namespace SokuLib
{
	void (* const playSEWaveBuffer)(int id) = reinterpret_cast<void (*)(int id)>(ADDR_PLAY_SE_WAVE_BUFFER);
	void (* const playNetBell)(int id) = reinterpret_cast<void (*)(int id)>(ADDR_PLAY_NET_BELL);
	void DSBuffer::Initialize(LPWAVEFORMATEX waveformatex, DWORD bufSize) {
		(* ((void (__thiscall **)(DSBuffer* , LPWAVEFORMATEX, DWORD)) ADDR_VTBL_CDSBUFFER))(this, waveformatex, bufSize);
	}
	void DSBuffer::Delete(bool free) {
		(* ((void (__thiscall **)(DSBuffer* , bool free)) (ADDR_VTBL_CDSBUFFER + 4)))(this, free);
	}
	void DS3DBuffer::Initialize(LPWAVEFORMATEX waveformatex, DWORD bufSize) {
		(* ((void (__thiscall **)(DSBuffer* , LPWAVEFORMATEX, DWORD)) ADDR_VTBL_CDS3DBUFFER))(this, waveformatex, bufSize);
	}
	void DS3DBuffer::Delete(bool free) {
		(* ((void (__thiscall **)(DSBuffer* , bool free)) (ADDR_VTBL_CDS3DBUFFER + 4)))(this, free);
	}
	int (__stdcall *const ConvertFloatVolumeToDSoundVolume)(float volume) = (int (__stdcall *)(float)) ADDR_SWR_CONVERT_VOLUME_TO_DSOUND;
	bool SoundManager::SetVolumeByDSBufferManagerID(unsigned int id) {
		if (!id)
			return false;
		DSBuffer **buffer = this->DSBufferManager.Get(id);
		if (!buffer || !*buffer)
			return false;
		return (*buffer)->pIDirectSoundBuffer->SetVolume(ConvertFloatVolumeToDSoundVolume(this->SEVolume * this->SEVolumeCoefficient)) == DS_OK;
	}
	SoundManager &soundMgr = * (SoundManager *) ADDR_SOUND_MANAGER;
}