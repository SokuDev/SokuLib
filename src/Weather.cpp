//
// Created by PinkySmile on 04/12/2020.
//

#include "Weather.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	Weather &activeWeather = *reinterpret_cast<Weather *>(ADDR_ACTIVE_WEATHER);
	Weather &displayedWeather = *reinterpret_cast<Weather *>(ADDR_DISPLAYED_WEATHER);
	unsigned short &weatherCounter = *reinterpret_cast<unsigned short *>(ADDR_WEATHER_COUNTER);
	void (__stdcall * const activateWeather)(int weather, char unknown) = reinterpret_cast<void (__stdcall *)(int, char)>(0x439770);
}