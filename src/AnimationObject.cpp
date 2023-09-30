//
// Created by Dphoenix on 20/07/2022.
//

#include "AnimationObject.hpp"

namespace SokuLib {
namespace v2 {
	AnimationObject::~AnimationObject() { if (unknown154) delete unknown154; unknown154 = 0; }

	bool AnimationObject::advanceFrame() {
		return ((bool (__thiscall *)(AnimationObject *))0x438c60)(this);
	}
}
}