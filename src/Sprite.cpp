//
// Created by PinkySmile on 12/05/2021.
//

#include "Sprite.hpp"
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"

namespace {
	// private
	void** const _vtable_sprite = (void** const)SokuLib::ADDR_VTBL_CSPRITE;
}

namespace SokuLib
{
	void Sprite::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_sprite[1]))(c); }
	void Sprite::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable_sprite[2]))(c); }
	void Sprite::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_sprite[3]))(c); }
	
	void Sprite::setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY) {
		(this->*union_cast<void(Sprite::*)(int, int, int, int, int, int, int)>(_vtable_sprite[4]))(texture, texOffsetX, texOffsetY, width, height, anchorX, anchorY);
	}

	void Sprite::setTexture2(int texture, int texOffsetX, int texOffsetY, int width, int height) {
		(this->*union_cast<void(Sprite::*)(int, int, int, int, int)>(_vtable_sprite[5]))(texture, texOffsetX, texOffsetY, width, height);
	}

	void Sprite::renderScreen(float left, float top, float right, float bottom) {
		(this->*union_cast<void(Sprite::*)(float, float, float, float)>(_vtable_sprite[6]))(left, top, right, bottom);
	}

	void Sprite::render(float x, float y) {
		(this->*union_cast<void(Sprite::*)(float, float)>(_vtable_sprite[7]))(x, y);
	}

	void Sprite::init(int texture, int texOffsetX, int texOffsetY, int width, int height) {
		Sprite::setTexture2(texture, texOffsetX, texOffsetY, width, height);
	}
}