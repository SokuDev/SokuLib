//
// Created by DPhoenix on 27/07/2023.
//

#ifndef SOKULIB_WEATHER__MANAGER_HPP
#define SOKULIB_WEATHER__MANAGER_HPP

#include "Map.hpp"
#include "IEffectManager.hpp"

namespace SokuLib {
namespace v2 {
	class WeatherManager {
	public:
		int unknown00; // some weather id
		char unknown04;  // some weather id but can be -1 on practice/replay
		// align 3
		Vector<unsigned int> someTexIds;
		// 0x18
		Vector<SpriteEx> someSprites; // EffectSprite with 0xE8 size
		// 0x28
		Deque<std::pair<unsigned int, SpriteEx*>> unknown28;
		// 0x3C
		Map<BYTE, Vector<BYTE>> unknown3C; // unsure inner size

		// 0x48:
		EffectManager_Weather effects;
		// 0xDC:
		float unknownDC[4];

		static WeatherManager*& instance;
	};
}
}

#endif
