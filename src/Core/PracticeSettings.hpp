//
// Created by PinkySmile on 26/02/2021.
//

#ifndef SOKULIB_PRACTICESETTINGS_HPP
#define SOKULIB_PRACTICESETTINGS_HPP


#include "Weather.hpp"

namespace SokuLib
{
#define SOKULIB_PRACTICE_POSITION_SETTING_DISABLED (16)

	enum DummyState : unsigned {
		DUMMY_STATE_STAND,
		DUMMY_STATE_SIT,
		DUMMY_STATE_JUMP,
		DUMMY_STATE_2P_CONTROL
	};

	enum AirTechDir : unsigned {
		AIRTECH_FRONT,
		AIRTECH_BACK,
		AIRTECH_RANDOM,
		AIRTECH_OFF
	};

	enum GuardSetting : unsigned {
		GUARD_ON,
		GUARD_OFF,
		GUARD_HIGH,
		GUARD_LOW,
		GUARD_AFTER_1HIT
	};

	enum CounterSetting : unsigned {
		COUNTER_ON,
		COUNTER_OFF
	};

	struct PracticeSettings {
		char offset0x00[0x2C];
		Weather weather;
		unsigned spirit;
		DummyState state;
		unsigned position;
		GuardSetting guard;
		CounterSetting counter;
		AirTechDir airtech;
	};

	extern PracticeSettings * const &practiceSettings;
}


#endif //SOKULIB_PRACTICESETTINGS_HPP
