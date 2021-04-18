//
// Created by PinkySmile on 02/12/2020.
//

#include "SokuAddresses.hpp"
#include "SoundManager.hpp"

namespace SokuLib
{
	void (* const playSEWaveBuffer)(int id) = reinterpret_cast<void (*)(int id)>(ADDR_PLAY_SE_WAVE_BUFFER);
	void (* const playNetBell)(int id) = reinterpret_cast<void (*)(int id)>(ADDR_PLAY_NET_BELL);
}