//
// Created by PinkySmile on 26/02/2021.
//

#include "PracticeSettings.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	PracticeSettings * const &practiceSettings = *reinterpret_cast<PracticeSettings **>(ADDR_PRACTICE_SETTINGS_STRUCT);
}