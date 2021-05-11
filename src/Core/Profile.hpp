//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SWRSTOYS_PROFILE_HPP
#define SWRSTOYS_PROFILE_HPP


#include "Cards.hpp"
#include "../Data/String.hpp"

namespace SokuLib
{
	struct Profile {
		// 0x000
		void *vtable;

		// 0x004
		CSprite sprite;

		// 0x098
		char offset_0x098[0x20];

		// 0x0B8
		void *mProfile;

		// 0x0BC
		char offset_0x0BC[0x14];

		// 0x0D0
		void *InputManagerExObj;

		// 0x0D4
		void *offset_0x0D4[0x9C];

		// 0x180
		String name;

		// 0x19C
		void *offset_0x19C[0x10];

		// 0x1AC
		mVC9Dequeue<unsigned short> cards[20][4];
	};

	extern Profile &profile1;
	extern Profile &profile2;

	[[deprecated("Replaced by profile1.name")]]
	extern String &player1Profile;
	[[deprecated("Replaced by profile2.name")]]
	extern String &player2Profile;
}


#endif //SWRSTOYS_PROFILE_HPP
