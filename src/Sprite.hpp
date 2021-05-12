//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_SPRITE_HPP
#define SOKULIB_SPRITE_HPP


#include "Vector2.hpp"

namespace SokuLib
{
	struct DxVertex {
		float x;
		float y;
		float z;
		float rhw;
		unsigned color;
		float u;
		float v;
	};

	struct Sprite {
		void *VTable;
		int dxHandle;
		DxVertex vertices[4];
		Vector2f size;
		Vector2f pos;
		Vector2f scale;
		float rotation;

		void init(int unknown1, int unknown2, int unknown3, int dat1, int dat2);
	};
}

#endif //SOKULIB_SPRITE_HPP
