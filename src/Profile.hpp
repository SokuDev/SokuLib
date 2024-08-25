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
		KeymapManager manager;

		// 0x138
		void *InputManagerExObj;

		// 0x13C
		bool hasSimulButtonsOff; // 3 bytes padded

		// 0x140
		KeyBindings keyboardBindings;
		// 0x174
		KeyBindings controllerBindings;

		// 0x1A8
		char controllerIndex; // 3 bytes padded

		// 0x1AC
		Dequeue<unsigned short> cards[20][4];
	};

	extern Profile &profile1;
	extern Profile &profile2;
}


#endif //SOKULIB_PROFILE_HPP
