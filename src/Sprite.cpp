//
// Created by PinkySmile on 12/05/2021.
//

#include "Sprite.hpp"
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"
#include "Memory.hpp"
#include "TextureManager.hpp"
#include "VTables.hpp"

namespace {
	// private
	void** const _vtable_bitmap = (void** const)SokuLib::ADDR_VTBL_BITMAPDATA;
	void** const _vtable_sprite = (void** const)SokuLib::ADDR_VTBL_CSPRITE;
	void** const _vtable_sprite_ex = (void** const)SokuLib::ADDR_VTBL_CSPRITE_EX;
}

namespace SokuLib
{
	const int _vtable_info<BitmapData>::baseAddr         = ADDR_VTBL_BITMAPDATA;
	const int _vtable_info<Sprite>::baseAddr             = ADDR_VTBL_CSPRITE;
	const int _vtable_info<SpriteEx>::baseAddr           = ADDR_VTBL_CSPRITE_EX;

	BitmapData::~BitmapData() { if (data) SokuLib::DeleteFct(data); }
	bool BitmapData::loadFromBmp(const char* c) { return (this->*union_cast<bool(BitmapData::*)(const char*)>(_vtable_bitmap[1]))(c); }
	bool BitmapData::loadFromPng(const char* c) { return (this->*union_cast<bool(BitmapData::*)(const char*)>(_vtable_bitmap[2]))(c); }
	bool BitmapData::loadFromCv2(const char* c) { return (this->*union_cast<bool(BitmapData::*)(const char*)>(_vtable_bitmap[3]))(c); }
	void BitmapData::unknownV04(void* c) { (this->*union_cast<void(BitmapData::*)(void*)>(_vtable_bitmap[4]))(c); }

	void BitmapData::copyToBuffer(int bytesPerRow, void* buffer) {
		reinterpret_cast<void(__fastcall*)(int, unsigned char, void*, void*)>(ADDR_BITMAP_COPYTOBUFFER)(bytesPerRow, this->bitsPerPixel, this, buffer);
	}

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

	void SpriteEx::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_sprite_ex[1]))(c); }
	void SpriteEx::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable_sprite_ex[2]))(c); }
	void SpriteEx::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_sprite_ex[3]))(c); }

	void SpriteEx::setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY) {
		(this->*union_cast<void(SpriteEx::*)(int, int, int, int, int, int, int)>(0x406c60))(texture, texOffsetX, texOffsetY, width, height, anchorX, anchorY);
	}

	void SpriteEx::setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height) {
		(this->*union_cast<void(SpriteEx::*)(int, int, int, int, int)>(0x41f7f0))(texture, texOffsetX, texOffsetY, width, height);
	}

	void SpriteEx::loadTransform() { (this->*union_cast<void(SpriteEx::*)()>(0x406ea0))(); }
	void SpriteEx::saveTransform() { (this->*union_cast<void(SpriteEx::*)()>(0x406ec0))(); }
	void SpriteEx::translate(float x, float y, float z) { (this->*union_cast<void(SpriteEx::*)(float, float, float)>(0x406ee0))(x, y, z); }
	void SpriteEx::scaleX(float x) { (this->*union_cast<void(SpriteEx::*)(float)>(0x406fa0))(x); }
	void SpriteEx::scaleX(float x, float anchor) { (this->*union_cast<void(SpriteEx::*)(float, float)>(0x406fe0))(x, anchor); }
	void SpriteEx::scaleY(float y) { (this->*union_cast<void(SpriteEx::*)(float)>(0x407040))(y); }
	void SpriteEx::scaleY(float y, float anchor) { (this->*union_cast<void(SpriteEx::*)(float, float)>(0x407080))(y, anchor); }
	// scaleZ: (4070e0, 407120)
	void SpriteEx::rotate(float x, float y, float z, float ax, float ay, float az)
		{ (this->*union_cast<void(SpriteEx::*)(float, float, float, float, float, float)>(0x407180))(x, y, z, ax, ay, az); }

	void SpriteEx::render() { (this->*union_cast<void(SpriteEx::*)()>(0x4075d0))(); }
	void SpriteEx::renderAdd(float r, float g, float b) { (this->*union_cast<void(SpriteEx::*)(float, float, float)>(0x7fb080))(r, g, b); }
	void SpriteEx::renderFill(float a, float r, float g, float b) { (this->*union_cast<void(SpriteEx::*)(float, float, float, float)>(0x7fb150))(a, r, g, b); }
	void SpriteEx::renderGray(float a1, float a2, float a3) { (this->*union_cast<void(SpriteEx::*)(float, float, float)>(0x7fb200))(a1, a2, a3); }
	void SpriteEx::renderGray() { (this->*union_cast<void(SpriteEx::*)(float, float, float)>(0x7fb200))(.299f, .587, .114); }

	void SpriteEx::render(int texId, float x, float y, float w, float h) {
		SokuLib::textureMgr.setTexture(texId, 1);
		(this->*union_cast<void(SpriteEx::*)(float, float, float, float)>(0x7fb290))(x, y, w, h);
	}

	void SpriteEx::renderAdd(int texId, float x, float y, float w, float h, float r, float g, float b) {
		SokuLib::textureMgr.setTexture(texId, 1);
		(this->*union_cast<void(SpriteEx::*)(float, float, float, float, float, float, float)>(0x7fb340))(x, y, w, h, r, g, b);
	}

	void SpriteEx::renderGray(int texId, float x, float y, float w, float h, float a1, float a2, float a3) {
		SokuLib::textureMgr.setTexture(texId, 1);
		(this->*union_cast<void(SpriteEx::*)(float, float, float, float, float, float, float)>(0x7fb480))(x, y, w, h, a1, a2, a3);
	}

	void SpriteEx::renderGray(int texId, float x, float y, float w, float h) {
		SokuLib::textureMgr.setTexture(texId, 1);
		(this->*union_cast<void(SpriteEx::*)(float, float, float, float, float, float, float)>(0x7fb480))(x, y, w, h, .299f, .587, .114);
	}

	Palette &Palette::currentPalette = *reinterpret_cast<Palette *>(ADDR_CURRENT_PALETTE);
}