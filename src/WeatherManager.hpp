//
// Created by DPhoenix on 27/07/2023.
//

#ifndef SOKULIB_WEATHER_MANAGER_HPP
#define SOKULIB_WEATHER_MANAGER_HPP

#include "Map.hpp"
#include "IEffectManager.hpp"
#include "Stage.hpp"
#include "Weather.hpp"

namespace SokuLib {
namespace v2 {
	class WeatherManager {
	public:
		int currentWeatherId; // unsure
		char currentSkyId;  // unsure
		// align 3
		// 0x08
		Vector<unsigned int> skyTexIds;
		Vector<SpriteEx> skySprites;
		// 0x28
		Deque<std::pair<unsigned int, SpriteEx*>> activeSky; // pair<color, sprite>
		Map<BYTE, Vector<BYTE>> stageToSkyMap; // check `data_csv_background_sky.csv`

		// 0x48:
		EffectManager_Weather effects;
		// 0xDC:
		float unknownDC[4];

		static WeatherManager*& instance;

		void setCurrentStage(Stage stageId); // 478370
		void setCurrentWeather(Weather weatherId); // 478410
	};
}
}

#endif
