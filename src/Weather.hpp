//
// Created by PinkySmile on 04/12/2020.
//

#ifndef SOKULIB_WEATHER_HPP
#define SOKULIB_WEATHER_HPP


namespace SokuLib
{
	enum Weather {
		/* 0  */ WEATHER_SUNNY,
		/* 1  */ WEATHER_DRIZZLE,
		/* 2  */ WEATHER_CLOUDY,
		/* 3  */ WEATHER_BLUE_SKY,
		/* 4  */ WEATHER_HAIL,
		/* 5  */ WEATHER_SPRING_HAZE,
		/* 6  */ WEATHER_HEAVY_FOG,
		/* 7  */ WEATHER_SNOW,
		/* 8  */ WEATHER_SUN_SHOWER,
		/* 9  */ WEATHER_SPRINKLE,
		/* 10 */ WEATHER_TEMPEST,
		/* 11 */ WEATHER_MOUNTAIN_VAPOR,
		/* 12 */ WEATHER_RIVER_MIST,
		/* 13 */ WEATHER_TYPHOON,
		/* 14 */ WEATHER_CALM,
		/* 15 */ WEATHER_DIAMOND_DUST,
		/* 16 */ WEATHER_DUST_STORM,
		/* 17 */ WEATHER_SCORCHING_SUN,
		/* 18 */ WEATHER_MONSOON,
		/* 19 */ WEATHER_AURORA,
		/* 20 */ WEATHER_TWILIGHT,
		/* 21 */ WEATHER_CLEAR,
	};

	extern Weather &activeWeather;
	extern Weather &displayedWeather;
	extern unsigned short &weatherCounter;
	extern void (__stdcall * const activateWeather)(int weather, char unknown);
}


#endif //SOKULIB_WEATHER_HPP
