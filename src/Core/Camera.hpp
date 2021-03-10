//
// Created by PinkySmile on 10/03/2021.
//

#ifndef SWRSTOYS_CAMERA_HPP
#define SWRSTOYS_CAMERA_HPP


#include "CharacterManager.hpp"

namespace SokuLib
{
	struct Camera {
		char offset_0x00[0xC];
		Vector translate;
		float scale;
	};

	extern Camera &camera;
}


#endif //SWRSTOYS_CAMERA_HPP
