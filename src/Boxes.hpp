//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SWRSTOYS_BOXES_HPP
#define SWRSTOYS_BOXES_HPP

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

#endif //SWRSTOYS_BOXES_HPP
