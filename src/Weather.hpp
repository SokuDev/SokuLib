//
// Created by PinkySmile on 04/12/2020.
//

#ifndef SOKULIB_WEATHER_HPP
#define SOKULIB_WEATHER_HPP


namespace SokuLib
{
    //! @brief enum of all possible weathers in battle.
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

	extern Weather &activeWeather; // Note: Aurora is not an active weather.
	extern Weather &displayedWeather; // Note: Aurora is a displayed weather.
	extern unsigned short &weatherCounter;
}


#endif //SOKULIB_WEATHER_HPP
