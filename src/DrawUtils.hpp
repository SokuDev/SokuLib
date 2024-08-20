//
// Created by PinkySmile on 03/03/2021.
//

#ifndef SOKULIB_DRAWUTILS_HPP
#define SOKULIB_DRAWUTILS_HPP


#include <windows.h>
#include <mutex>
#include "Vector2.hpp"
#include "Font.hpp"
#include "Camera.hpp"

namespace SokuLib {
namespace DrawUtils
{
	struct DxSokuColor {
		union {
			struct {
				unsigned char b;
				unsigned char g;
				unsigned char r;
				unsigned char a;
			};
			unsigned color;
		};

		DxSokuColor() = default;
		DxSokuColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xFF) noexcept;
		DxSokuColor(unsigned color) noexcept;

		DxSokuColor &operator=(unsigned color);
		DxSokuColor operator+(const DxSokuColor &other) const;
		DxSokuColor &operator+=(const DxSokuColor &other);
		DxSokuColor operator*(const DxSokuColor &other) const;
		DxSokuColor &operator*=(const DxSokuColor &other);

		template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
		DxSokuColor operator*(T alpha) const
		{
			DxSokuColor result = *this;

			result *= alpha;
			return result;
		}

		template<typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
		DxSokuColor &operator*=(T alpha)
		{
			this->a = std::min<unsigned char>(this->a * alpha, 255);
			return *this;
		}

		operator unsigned() const;

		static const DxSokuColor White;
		static const DxSokuColor Yellow;
		static const DxSokuColor Red;
		static const DxSokuColor Blue;
		static const DxSokuColor Green;
		static const DxSokuColor Magenta;
		static const DxSokuColor Cyan;
		static const DxSokuColor Black;
		static const DxSokuColor Transparent;
	};

	class Texture {
	private:
		int _handle;
		bool _loaded = false;
		Vector2u _size;
		std::mutex _mutex;

	public:
		Texture() noexcept = default;
		Texture(int handle, const Vector2u &size) noexcept;
		Texture(Texture &) = delete;
		Texture(Texture &&);
		Texture &operator=(Texture &);
		Texture &operator=(Texture &&);
		~Texture() noexcept;

		bool hasTexture() const noexcept;
		void activate(int stage = 0) const noexcept;
		Vector2u getSize() const;

		void setHandle(int handle, const Vector2u &size);
		void swap(Texture &other);
		void destroy();
		int releaseHandle();

		bool loadFromFile(const char *path);
		bool loadFromGame(const char *path);
		bool loadFromResource(HMODULE srcModule, LPCTSTR srcResource);
		bool createFromText(const char *str, SWRFont &font, Vector2u size, Vector2i *realSize = nullptr);
	};

	class RenderingElement {
	protected:
		Vector2i _position = {0, 0};

	public:
		Vector2i getPosition() const;

		virtual void setPosition(const Vector2i &);
		virtual void draw() const = 0;
	};

	struct Vertex {
		float x, y, z;
		float rhw; // RHW = reciprocal of the homogeneous (clip space) w coordinate of a vertex (the 4th dimension for computing the scaling and translating)
		D3DCOLOR color;
		float u, v;

		template<typename T>
		Vertex operator+(const Vector2<T> &vec) const
		{
			return {
				this->x + vec.x,
				this->y + vec.y,
				this->z,
				this->rhw,
				this->color,
				this->u,
				this->v
			};
		}

		template<typename T>
		Vertex &operator+=(const Vector2<T> &vec)
		{
			this->x += vec.x;
			this->y += vec.y;
			return *this;
		}
	};

	template<typename T>
	struct Rect {
		T x1;
		T y1;
		T x2;
		T y2;
	};
	typedef Rect<float> FloatRect;

	class RectangularRenderingElement : public RenderingElement {
	private:
		float _rotation = 0;
		Vector2u _size = {0, 0};
		const Camera *_camera = nullptr;
		Vector2<bool> _mirroring = {false, false};

	protected:
		Vertex _vertex[4] = {
			{0, 0, 0, 1, 0x00000000, 0.0f, 0.0f},
			{0, 0, 0, 1, 0x00000000, 1.0f, 0.0f},
			{0, 0, 0, 1, 0x00000000, 1.0f, 1.0f},
			{0, 0, 0, 1, 0x00000000, 0.0f, 1.0f},
		};

		virtual Vector2u _getRealSize();
	public:
		Vector2u getSize() const;
		float getRotation() const;

		RectangularRenderingElement() noexcept = default;
		RectangularRenderingElement(const Camera &camera) noexcept;
		void setSize(const Vector2u &);
		void setPosition(const Vector2i &) override;
		void setRect(const FloatRect &rect);
		void rawSetRect(const Rect<Vector2f> &rect);
		void setRotation(float angle);
		void setMirroring(bool x, bool y);
		void setCamera(const Camera *camera);
		Vector2<bool> getMirroring() const;
		const Vertex *getVertex() const;
	};

	struct TextureRect {
		int left;
		int top;
		int width;
		int height;
	};

	class Sprite : public RectangularRenderingElement {
	protected:
		Vector2u _getRealSize() override;

	public:
		TextureRect rect{0, 0, 0, 0};
		DxSokuColor tint = 0xFFFFFFFF;
		DxSokuColor fillColors[4] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		Texture texture;

		Sprite() = default;
		Sprite(const Camera &camera) noexcept;

		void draw() const override;
	};

	class GradiantRect : public RectangularRenderingElement {
	public:
		enum Corner {
			RECT_TOP_LEFT_CORNER,
			RECT_TOP_RIGHT_CORNER,
			RECT_BOTTOM_RIGHT_CORNER,
			RECT_BOTTOM_LEFT_CORNER,
		};

		DxSokuColor fillColors[4] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
		DxSokuColor borderColors[4] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};

		GradiantRect() noexcept = default;
		GradiantRect(const Camera &camera) noexcept;
		void draw() const override;
	};

	class RectangleShape : public GradiantRect {
	public:
		void setFillColor(const DxSokuColor &color);
		void setBorderColor(const DxSokuColor &color);

		DxSokuColor getFillColor() const;
		DxSokuColor getBorderColor() const;

		RectangleShape() noexcept = default;
		RectangleShape(const Camera &camera) noexcept;
		void draw() const override;
	};
}
}


#endif //SOKULIB_DRAWUTILS_HPP
