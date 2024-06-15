//
// Created by PinkySmile on 11/05/2021.
//

#ifndef SOKULIB_PROFILE_HPP
#define SOKULIB_PROFILE_HPP


#include "Cards.hpp"
#include "String.hpp"
#include "InputManager.hpp"

namespace SokuLib
{
	struct Profile {
		// 0x000
		void *vtable;

		// 0x004
		Sprite sprite;

		// 0x098
		String file;

		// 0x0B4
		String name;

		// 0x0D0
		void *InputManagerExObj;

		// 0x0D4
		char offset_0x0D4[0x6C];

		// 0x140
		KeyBindings keyboardBindings;
		// 0x174
		KeyBindings controllerBindings;

		// 0x1A8
		int offset_0x1A8;

		// 0x1AC
		Dequeue<unsigned short> cards[20][4];
	};

	extern Profile &profile1;
	extern Profile &profile2;
}


#endif //SOKULIB_PROFILE_HPP
