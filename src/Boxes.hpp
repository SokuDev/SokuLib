//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_BOXES_HPP
#define SOKULIB_BOXES_HPP

#include "Vector2.hpp"

namespace SokuLib
{
	struct Box {
		int left;
		int top;
		int right;
		int bottom;
	};

	struct RotationBox {
		Vector2i pt1;
		Vector2i pt2;
	};
}

#endif //SOKULIB_BOXES_HPP
