//
// Created by Dphoenix on 20/07/2022.
//

#include "FrameData.hpp"

namespace SokuLib {
namespace v2 {
	FrameData::~FrameData() {
		if (blendOptionsPtr) delete blendOptionsPtr; blendOptionsPtr = 0;
	}

	CharacterFrameData::~CharacterFrameData() {
		for (auto box : extraBoxes) if(box) delete box;
		if (collisionBox) delete collisionBox; collisionBox = 0;
	}
}
}