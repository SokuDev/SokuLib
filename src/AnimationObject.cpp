//
// Created by Dphoenix on 20/07/2022.
//

#include "AnimationObject.hpp"
#include "UnionCast.hpp"

namespace SokuLib {
namespace v2 {
	AnimationObject::~AnimationObject() { if (unknown154) delete unknown154; unknown154 = 0; }

	bool AnimationObject::advanceFrame() { return (this->*union_cast<bool (__thiscall AnimationObject::*)()>(0x438c60))(); }
}
}