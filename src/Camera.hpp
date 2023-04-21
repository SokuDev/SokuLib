//
// Created by PinkySmile on 10/03/2021.
//

#ifndef SOKULIB_CAMERA_HPP
#define SOKULIB_CAMERA_HPP


#include "Vector2.hpp"

namespace SokuLib
{
	struct Camera {
		char offset_0x00[0x4];
		// 0x04
		float offset_0x04;
		// 0x08
		float targetScale;
		// 0x0C
		Vector2f translate;
		// 0x14
		float scale;
		// 0x18
		Vector2f backgroundTranslate;
		// 0x20
		float offset_0x20;
		// 0x24
		float offset_0x24;
		// 0x28
		float forcedScaleValue;
		// 0x2C
		bool offset_0x2C;
		// 0x2D
		bool offset_0x2D;
		// 0x2E
		bool scaleForced;
		char padding2F;
		// 0x30
		float offset_0x30;
		// 0x34
		char offset_0x34[0x10];
		// 0x44
		float *offset_0x44;
		// 0x48
		float *offset_0x48;
		// 0x4C
		float *offset_0x4C;
		// 0x50
		float *offset_0x50;
		// 0x54
		float offset_0x54;
		// 0x58
		float offset_0x58;

		void _update1();
		void _update2();
		void update();
	};

	extern Camera &camera;
}


#endif //SOKULIB_CAMERA_HPP
