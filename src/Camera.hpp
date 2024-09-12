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
		float forcedXCenter;
		// 0x24
		float forcedYCenter;
		// 0x28
		float forcedScale;
		// 0x2C
		bool forceXCenter;
		// 0x2D
		bool forceYCenter;
		// 0x2E
		bool forceScale;
		// Padding

		// 0x30
		float offset_0x30;
		// 0x34
		char offset_0x34[0xC];
		// 0x40
		float shake;
		// 0x44
		float *p1X;
		// 0x48
		float *p2X;
		// 0x4C
		float *p1Y;
		// 0x50
		float *p2Y;
		// 0x54
		float offset_0x54;
		// 0x58
		float offset_0x58;
		// 0x5C
		float leftEdge;
		// 0x60
		float topEdge;
		// 0x64
		float rightEdge;
		// 0x68
		float bottomEdge;

		void _update1();
		void _update2();
		void update();
	};

	extern Camera &camera;
}


#endif //SOKULIB_CAMERA_HPP
