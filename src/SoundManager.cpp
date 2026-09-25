//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"
#include "SoundManager.hpp"
#include "UnionCast.hpp"

namespace SokuLib
{
	void (* const playSEWaveBuffer)(int id) = reinterpret_cast<void (*)(int id)>(ADDR_PLAY_SE_WAVE_BUFFER);
	void (* const playNetBell)(int id) = reinterpret_cast<void (*)(int id)>(ADDR_PLAY_NET_BELL);

	SFXManager& SFXManager::instance = *reinterpret_cast<SFXManager *>(ADDR_SFX_MANAGER);
	BGMManager& BGMManager::instance = *reinterpret_cast<BGMManager *>(ADDR_BGM_MANAGER);

	unsigned int SFXManager::load(unsigned int& id, const char* soundPath) { return (this->*union_cast<unsigned int(SFXManager::*)(unsigned int&, const char*)>(0x401AF0))(id, soundPath); }
	bool SFXManager::unload(unsigned int id) { return (this->*union_cast<bool(SFXManager::*)(unsigned int)>(0x401BD0))(id); }
	void SFXManager::play(unsigned int id) { return (this->*union_cast<void(SFXManager::*)(unsigned int)>(0x401D50))(id); }

}