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

	class BitmapData {
	public:
		unsigned char bitsPerPixel = 0;
		// align 0x3
		int width;
		int height;
		int paddedWidth;
		int unknown0x14 = 0; // seems to be an alternative size to data, if zero then it is calculated from metadata
		void *palette = 0;
		void *data = 0;

		BitmapData() = default;
		virtual ~BitmapData();
		virtual bool loadFromBmp(const char* filename);
		virtual bool loadFromPng(const char* filename);
		virtual bool loadFromCv2(const char* filename);
		virtual void unknownV04(void*); // maybe argument is a array and it loads from memory (unknown format)

		void copyToBuffer(int bytesPerRow, void* buffer);
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
	public:
		virtual ~Sprite() = default;
		virtual void setColor(int c) override;
		virtual void setColor2(int c[4]) override;
		virtual void setColor3(int c) override;
		virtual void setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY);
		virtual void setTexture2(int texture, int texOffsetX, int texOffsetY, int width, int height);
		virtual void renderScreen(float left, float top, float right, float bottom);
		virtual void render(float x, float y);
		// The next one seems to use untransformed vertex, but the function is not used in game, and the derivatives don't implement it. Probably is better just to remove it.
		//virtual void render8(float x, float y) { return (this->*union_cast<void*(CSprite::*)(float, float)>(_vtable[8]))(x, y); }

		// it is a direct call to setTexture2 (kept for compatibility)
		void init(int texture, int texOffsetX, int texOffsetY, int width, int height);
	};

	class Palette {
	public:
		unsigned char bitsPerPixel;
		// align 0x3
		void* data; // &char[bitsPerPixel == 0x10 ? 512 : 1024];

		static Palette& currentPalette;
	};
}

#endif //SOKULIB_SPRITE_HPP
