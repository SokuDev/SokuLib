//
// Created by PinkySmile on 10/03/2021.
//

#ifndef SOKULIB_CAMERA_HPP
#define SOKULIB_CAMERA_HPP


#include "Vector2.hpp"

namespace SokuLib
{
	struct Camera {
		char offset_0x00[0xC];
		Vector2f translate;
		float scale;
		Vector2f backgroundTranslate;

		void _update1();
		void _update2();
		void update();
	};

	extern Camera &camera;
}


#endif //SOKULIB_CAMERA_HPP
