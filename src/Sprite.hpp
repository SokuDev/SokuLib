//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_SPRITE_HPP
#define SOKULIB_SPRITE_HPP


#include "Vector2.hpp"

namespace SokuLib
{
	class IColor {
	public:
		virtual ~IColor() = default;
		virtual void setColor(int a1) = 0;
		virtual void setColor2(int a1[4]) = 0;
		virtual void setColor3(int a1) = 0;
	};

	struct DxVertex {
		float x;
		float y;
		float z;
		float rhw;
		unsigned color;
		float u;
		float v;
	};

	class SpriteBase : public IColor {
	public:
		int dxHandle = 0;
		DxVertex vertices[4];
		Vector2f size;
		Vector2f pos;
		Vector2f scale;
		float rotation;

		// Textures are NOT deleted by the destructor
		virtual ~SpriteBase() = default;
	};

	class Sprite : public SpriteBase {
		inline static void** const _vtable = (void**)0x8576ac;
	public:
		virtual ~Sprite() = default;
		virtual void setColor(int c) override;
		virtual void setColor2(int c[4]) override;
		virtual void setColor3(int c) override;
		virtual void setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY);
		virtual void setTexture2(int texture, int texOffsetX, int texOffsetY, int width, int height);
		virtual void renderScreen(float left, float top, float right, float bottom); // maybe its width/height instead of right/bottom
		virtual void render(float x, float y);
		// The next one seems to use untransformed vertex, but the function is not used in game, and the derivatives don't implement it. Probably is better just to remove it.
		//virtual void render8(float x, float y) { return (this->*union_cast<void*(CSprite::*)(float, float)>(_vtable[8]))(x, y); }

		// it is a direct call to setTexture2 (kept for compatibility)
		void init(int texture, int texOffsetX, int texOffsetY, int width, int height);
	};
}

#endif //SOKULIB_SPRITE_HPP
