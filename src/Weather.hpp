//
// Created by PinkySmile on 04/12/2020.
//

#ifndef SOKULIB_WEATHER_HPP
#define SOKULIB_WEATHER_HPP


namespace SokuLib
{
	enum Weather {
		/* 0  (0x00) */ WEATHER_SUNNY,
		/* 1  (0x01) */ WEATHER_DRIZZLE,
		/* 2  (0x02) */ WEATHER_CLOUDY,
		/* 3  (0x03) */ WEATHER_BLUE_SKY,
		/* 4  (0x04) */ WEATHER_HAIL,
		/* 5  (0x05) */ WEATHER_SPRING_HAZE,
		/* 6  (0x06) */ WEATHER_HEAVY_FOG,
		/* 7  (0x07) */ WEATHER_SNOW,
		/* 8  (0x08) */ WEATHER_SUN_SHOWER,
		/* 9  (0x09) */ WEATHER_SPRINKLE,
		/* 10 (0x0A) */ WEATHER_TEMPEST,
		/* 11 (0x0B) */ WEATHER_MOUNTAIN_VAPOR,
		/* 12 (0x0C) */ WEATHER_RIVER_MIST,
		/* 13 (0x0D) */ WEATHER_TYPHOON,
		/* 14 (0x0E) */ WEATHER_CALM,
		/* 15 (0x0F) */ WEATHER_DIAMOND_DUST,
		/* 16 (0x10) */ WEATHER_DUST_STORM,
		/* 17 (0x11) */ WEATHER_SCORCHING_SUN,
		/* 18 (0x12) */ WEATHER_MONSOON,
		/* 19 (0x13) */ WEATHER_AURORA,
		/* 20 (0x14) */ WEATHER_TWILIGHT,
		/* 21 (0x15) */ WEATHER_CLEAR,
	};

#ifndef SOKULIB_NO_MOD
	extern Weather &activeWeather;
	extern Weather &displayedWeather;
	extern Weather &displayedWeatherOrb;
	extern unsigned short &weatherCounter;
	extern void (__stdcall * const activateWeather)(int weather, char unknown);
#endif
}


#endif //SOKULIB_WEATHER_HPP
