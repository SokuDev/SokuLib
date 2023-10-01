//
// Created by PinkySmile on 10/03/2021.
//

#ifndef SOKULIB_CAMERA_HPP
#define SOKULIB_CAMERA_HPP


#include "CharacterManager.hpp"

namespace SokuLib
{
    //! @brief The camera used during battle.
	struct Camera {
		char offset_0x00[0xC];
		Vector2f translate;
		float scale;
		Vector2f backgroundTranslate;
	};

	extern Camera &camera;
}


#endif //SOKULIB_CAMERA_HPP
