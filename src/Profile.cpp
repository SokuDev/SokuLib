//
// Created by PinkySmile on 11/05/2021.
//

#include "Profile.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	Profile &profile1 = *reinterpret_cast<Profile *>(ADDR_PLAYER1_PROFILE);
	Profile &profile2 = *reinterpret_cast<Profile *>(ADDR_PLAYER2_PROFILE);
}