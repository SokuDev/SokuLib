//
// Created by PinkySmile on 04/12/2020.
//

#ifndef SOKULIB_WEATHER_HPP
#define SOKULIB_WEATHER_HPP


namespace SokuLib
{
	enum Weather {
		WEATHER_SUNNY,
		WEATHER_DRIZZLE,
		WEATHER_CLOUDY,
		WEATHER_BLUE_SKY,
		WEATHER_HAIL,
		WEATHER_SPRING_HAZE,
		WEATHER_HEAVY_FOG,
		WEATHER_SNOW,
		WEATHER_SUN_SHOWER,
		WEATHER_SPRINKLE,
		WEATHER_TEMPEST,
		WEATHER_MOUNTAIN_VAPOR,
		WEATHER_RIVER_MIST,
		WEATHER_TYPHOON,
		WEATHER_CALM,
		WEATHER_DIAMOND_DUST,
		WEATHER_DUST_STORM,
		WEATHER_SCORCHING_SUN,
		WEATHER_MONSOON,
		WEATHER_AURORA,
		WEATHER_TWILIGHT,
		WEATHER_CLEAR,
	};

	extern Weather &activeWeather;
	extern Weather &displayedWeather;
	extern unsigned short &weatherCounter;
	extern void (__stdcall * const activateWeather)(int weather, char unknown);
}


#endif //SOKULIB_WEATHER_HPP
