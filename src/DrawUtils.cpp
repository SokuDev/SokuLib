//
// Created by PinkySmile on 03/03/2021.
//

#include <d3d9.h>
#include <d3dx9tex.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "DrawUtils.hpp"
#include "TextureManager.hpp"

#ifndef _DEBUG
#define puts(x)
#define printf(...)
#define fprintf(...)
#endif

namespace SokuLib {
namespace DrawUtils
{
	DxSokuColor::DxSokuColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept :
		r(r),
		g(g),
		b(b),
		a(a)
	{
	}

	DxSokuColor::DxSokuColor(unsigned int color) noexcept :
		color(color)
	{
	}

	DxSokuColor::operator unsigned() const
	{
		return this->color;
	}

	DxSokuColor &DxSokuColor::operator=(unsigned int color)
	{
		this->color = color;
		return *this;
	}

	DxSokuColor DxSokuColor::operator+(const DxSokuColor &other) const
	{
		DxSokuColor result = *this;

		result += other;
		return result;
	}

	DxSokuColor &DxSokuColor::operator+=(const DxSokuColor &other)
	{
		this->a = std::ceil((other.a + this->a) / 2.);
		this->r = std::ceil((other.r + this->r) / 2.);
		this->g = std::ceil((other.g + this->g) / 2.);
		this->b = std::ceil((other.b + this->b) / 2.);
		return *this;
	}

	DxSokuColor DxSokuColor::operator*(const DxSokuColor &other) const
	{
		DxSokuColor result = *this;

		result *= other;
		return result;
	}

	DxSokuColor &DxSokuColor::operator*=(const DxSokuColor &other)
	{
		this->a = std::ceil((other.a * this->a) / 255.f);
		this->r = std::ceil((other.r * this->r) / 255.f);
		this->g = std::ceil((other.g * this->g) / 255.f);
		this->b = std::ceil((other.b * this->b) / 255.f);
		return *this;
	}

	const DxSokuColor DxSokuColor::White      {0xFF, 0xFF, 0xFF, 0xFF};
	const DxSokuColor DxSokuColor::Red        {0xFF, 0x00, 0x00, 0xFF};
	const DxSokuColor DxSokuColor::Blue       {0x00, 0x00, 0xFF, 0xFF};
	const DxSokuColor DxSokuColor::Green      {0x00, 0xFF, 0x00, 0xFF};
	const DxSokuColor DxSokuColor::Yellow     {0xFF, 0xFF, 0x00, 0xFF};
	const DxSokuColor DxSokuColor::Magenta    {0xFF, 0x00, 0xFF, 0xFF};
	const DxSokuColor DxSokuColor::Cyan       {0x00, 0xFF, 0xFF, 0xFF};
	const DxSokuColor DxSokuColor::Black      {0x00, 0x00, 0x00, 0xFF};
	const DxSokuColor DxSokuColor::Transparent{0x00, 0x00, 0x00, 0x00};

	Texture::Texture(int handle, const Vector2<unsigned> &size) noexcept :
		_handle(handle),
		_loaded(true),
		_size(size)
	{
	}

	Texture::Texture(Texture &&o)
	{
		this->swap(o);
	}

	Texture &Texture::operator=(Texture &o)
	{
		this->swap(o);
		return *this;
	}

	Texture &Texture::operator=(Texture &&o)
	{
		this->swap(o);
		return *this;
	}

	Texture::~Texture() noexcept
	{
		this->destroy();
	}

	bool Texture::hasTexture() const noexcept
	{
		return this->_loaded;
	}

	void Texture::activate(int stage) const noexcept
	{
		if (this->hasTexture())
			SokuLib::textureMgr.setTexture(this->_handle, stage);
		else
			SokuLib::textureMgr.setTexture(0, stage);
	}

	void Texture::setHandle(int handle, const Vector2<unsigned> &size)
	{
		this->destroy();
		this->_loaded = true;
		this->_handle = handle;
		this->_size = size;
	}

	void Texture::swap(Texture &other)
	{
		int handle = this->_handle;
		bool loaded = this->_loaded;
		Vector2u size = this->_size;

		this->_handle = other._handle;
		this->_loaded = other._loaded;
		this->_size = other._size;
		other._handle = handle;
		other._loaded = loaded;
		other._size = size;
	}

	void Texture::destroy()
	{
		this->_mutex.lock();
		if (this->_loaded && SokuLib::pd3dDev)
			SokuLib::textureMgr.remove(this->_handle);
		this->_loaded = false;
		this->_mutex.unlock();
	}

	int Texture::releaseHandle()
	{
		this->_loaded = false;
		return this->_handle;
	}

	Vector2<unsigned> Texture::getSize() const
	{
		return this->_size;
	}

	bool Texture::loadFromFile(const char *path)
	{
		HRESULT result;
		int handle;
		D3DXIMAGE_INFO info;

		printf("Loading texture %s\n", path);
		if (FAILED(result = D3DXGetImageInfoFromFile(path, &info))) {
			fprintf(stderr, "D3DXGetImageInfoFromFile(\"%s\", %p) failed with code %li.\n", path, &info, result);
			return false;
		}

		LPDIRECT3DTEXTURE9 *pphandle = SokuLib::textureMgr.allocate(&handle);

		*pphandle = nullptr;
		EnterCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
		if (FAILED(result = D3DXCreateTextureFromFileExA(
			SokuLib::pd3dDev,
			path,
			info.Width,
			info.Height,
			info.MipLevels,
			0,
			info.Format,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			&info,
			nullptr,
			pphandle
		))) {
			LeaveCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
			fprintf(stderr, "D3DXCreateTextureFromFile(%p, \"%s\", %p) failed with code %li.\n", SokuLib::pd3dDev, path, pphandle, result);
			SokuLib::textureMgr.deallocate(handle);
			return false;
		}
		LeaveCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
		printf("Texture handle: %x, Size: %ux%u\n", handle, info.Width, info.Height);
		this->setHandle(handle, {info.Width, info.Height});
		return true;
	}

	bool Texture::loadFromGame(const char *path)
	{
		int text = 0;
		Vector2<unsigned> size;

		printf("Loading texture %s\n", path);
		if (!SokuLib::textureMgr.loadTexture(&text, path, &size.x, &size.y) || !text) {
			puts("Couldn't load texture...");
			return false;
		}
		this->setHandle(text, size);
		return true;
	}

	bool Texture::loadFromResource(HMODULE srcModule, LPCTSTR srcResource)
	{
		int id = 0;
		long int result;
		D3DXIMAGE_INFO info;

		printf("Loading resource %p from module %p\n", srcResource, srcModule);
		if (FAILED(result = D3DXGetImageInfoFromResource(srcModule, srcResource, &info))) {
			fprintf(stderr, "D3DXGetImageInfoFromResource(%p, %p, %p) failed with code %lx.\n", srcModule, srcResource, &info, result);
			return false;
		}

		LPDIRECT3DTEXTURE9 *pphandle = SokuLib::textureMgr.allocate(&id);

		*pphandle = nullptr;
		EnterCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
		if (SUCCEEDED(D3DXCreateTextureFromResourceEx(
			SokuLib::pd3dDev,
			srcModule,
			srcResource,
			info.Width,
			info.Height,
			info.MipLevels,
			0,
			info.Format,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			&info,
			nullptr,
			pphandle
		))) {
			LeaveCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
			this->setHandle(id, {info.Width, info.Height});
			return true;
		}
		LeaveCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
		SokuLib::textureMgr.deallocate(id);
		return false;
	}

	bool Texture::createFromText(const char *str, SokuLib::SWRFont &font, Vector2<unsigned> size, Vector2<int> *realSize)
	{
		int text = 0;

		printf("Creating texture for text %s (size %u,%u)\n", str, size.x, size.y);
		if (!SokuLib::textureMgr.createTextTexture(
			&text, str, font, size.x, size.y,
			realSize ? &realSize->x : nullptr,
			realSize ? &realSize->y : nullptr
		) || !text) {
			puts("Failed");
			return false;
		}
		printf("Texture handle: %x, Size: %ux%u\n", text, size.x, size.y);
		this->setHandle(text, size);
		return true;
	}

	Vector2<unsigned> RectangularRenderingElement::getSize() const
	{
		return this->_size;
	}

	Vector2<int> RenderingElement::getPosition() const
	{
		return this->_position;
	}

	void RenderingElement::setPosition(const Vector2<int> &newPos)
	{
		this->_position = newPos;
	}

	void RectangularRenderingElement::setSize(const Vector2<unsigned int> &newSize)
	{
		this->_size = newSize;
		this->setPosition(this->_position);
	}

	void RectangularRenderingElement::setPosition(const Vector2<int> &newPos)
	{
		RenderingElement::setPosition(newPos);

		auto size = this->_getRealSize();
		auto center = this->_position + size * 0.5;
		auto topLeft = this->_position.rotate(this->_rotation, center);
		auto topRight = (this->_position + Vector2<unsigned>{size.x, 0}).rotate(this->_rotation, center);
		auto bottomLeft = (this->_position + Vector2<unsigned>{0, size.y}).rotate(this->_rotation, center);
		auto bottomRight = (this->_position + size).rotate(this->_rotation, center);

		this->_vertex[ this->_mirroring.x + this->_mirroring.y *  2].x = topLeft.x;
		this->_vertex[ this->_mirroring.x + this->_mirroring.y *  2].y = topLeft.y;
		this->_vertex[!this->_mirroring.x + this->_mirroring.y *  2].x = topRight.x;
		this->_vertex[!this->_mirroring.x + this->_mirroring.y *  2].y = topRight.y;
		this->_vertex[ this->_mirroring.x + this->_mirroring.y * -2 + 2].x = bottomRight.x;
		this->_vertex[ this->_mirroring.x + this->_mirroring.y * -2 + 2].y = bottomRight.y;
		this->_vertex[!this->_mirroring.x + this->_mirroring.y * -2 + 2].x = bottomLeft.x;
		this->_vertex[!this->_mirroring.x + this->_mirroring.y * -2 + 2].y = bottomLeft.y;

		if (this->_camera)
			for (auto &vertex : this->_vertex) {
				vertex.x += this->_camera->translate.x;
				vertex.y += this->_camera->translate.y;
				vertex.x *= this->_camera->scale;
				vertex.y *= this->_camera->scale;
			}
	}

	RectangularRenderingElement::RectangularRenderingElement(const SokuLib::Camera &camera) noexcept :
		_camera(&camera)
	{
	}

	void RectangularRenderingElement::setRect(const FloatRect &rect)
	{
		Vector2<int> pos{
			static_cast<int>(min(rect.x1, rect.x2)),
			static_cast<int>(min(rect.y1, rect.y2))
		};
		Vector2<unsigned> size{
			static_cast<unsigned int>(std::abs(rect.x1 - rect.x2)),
			static_cast<unsigned int>(std::abs(rect.y1 - rect.y2))
		};

		this->setSize(size);
		this->setPosition(pos);
	}

	void RectangularRenderingElement::rawSetRect(const Rect<Vector2<float>> &rect)
	{
		const Vector2<float> (&array)[4] = *reinterpret_cast<const Vector2<float>(*)[4]>(&rect);

		for (int i = 0; i < 4; i++) {
			this->_vertex[i].x = array[i].x;
			this->_vertex[i].y = array[i].y;
		}
	}

	void RectangularRenderingElement::setRotation(float angle)
	{
		this->_rotation = angle;
		this->setPosition(this->_position);
	}

	void RectangularRenderingElement::setMirroring(bool x, bool y)
	{
		this->_mirroring = {x, y};
		this->setPosition(this->_position);
	}

	void RectangularRenderingElement::setCamera(const Camera *camera)
	{
		this->_camera = camera;
	}

	const Vertex *RectangularRenderingElement::getVertex() const
	{
		return this->_vertex;
	}

	float RectangularRenderingElement::getRotation() const
	{
		return this->_rotation;
	}

	Vector2u RectangularRenderingElement::_getRealSize()
	{
		return this->_size;
	}

	Vector2<bool> RectangularRenderingElement::getMirroring() const
	{
		return this->_mirroring;
	}

	void GradiantRect::draw() const
	{
		Vertex vertices[4];
		Vertex borders[5];

		for (int i = 0; i < 4; i++) {
			vertices[i] = borders[i] = this->_vertex[i];
			vertices[i].color = this->fillColors[i];
			borders[i].color = this->borderColors[i];
		}
		borders[4] = borders[0];
		SokuLib::textureMgr.setTexture(0, 0);
		SokuLib::pd3dDev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertices, sizeof(*vertices));
		SokuLib::pd3dDev->DrawPrimitiveUP(D3DPT_LINESTRIP, 4, borders, sizeof(*borders));
	}

	GradiantRect::GradiantRect(const SokuLib::Camera &camera) noexcept :
		RectangularRenderingElement(camera)
	{
	}

	void RectangleShape::draw() const
	{
		GradiantRect::draw();
	}

	void RectangleShape::setFillColor(const DxSokuColor &color)
	{
		for (auto &fillColor : this->fillColors)
			fillColor = color;
	}

	void RectangleShape::setBorderColor(const DxSokuColor &color)
	{
		for (auto &borderColor : this->borderColors)
			borderColor = color;
	}

	DxSokuColor RectangleShape::getFillColor() const
	{
		return *this->fillColors;
	}

	DxSokuColor RectangleShape::getBorderColor() const
	{
		return *this->borderColors;
	}

	RectangleShape::RectangleShape(const SokuLib::Camera &camera) noexcept :
		GradiantRect(camera)
	{
	}

	void Sprite::draw() const
	{
		Vertex vertices[4];

		for (int i = 0; i < 4; i++) {
			vertices[i] = this->_vertex[i];
			vertices[i].color = this->fillColors[i] * this->tint;
		}

		auto size = this->texture.getSize();

		if (size.x && size.y) {
			float left = static_cast<float>(this->rect.left) / size.x;
			float top = static_cast<float>(this->rect.top) / size.y;
			float right = static_cast<float>(this->rect.left + this->rect.width) / size.x;
			float bottom = static_cast<float>(this->rect.top + this->rect.height) / size.y;

			vertices[3].u = vertices[0].u = left;
			vertices[2].u = vertices[1].u = right;
			vertices[1].v = vertices[0].v = top;
			vertices[2].v = vertices[3].v = bottom;
			vertices[0].x -= 0.5;
			vertices[1].x -= 0.5;
			vertices[2].x -= 0.5;
			vertices[3].x -= 0.5;
			vertices[0].y -= 0.5;
			vertices[1].y -= 0.5;
			vertices[2].y -= 0.5;
			vertices[3].y -= 0.5;
			vertices[0].z += 0.5;
			vertices[1].z += 0.5;
			vertices[2].z += 0.5;
			vertices[3].z += 0.5;
		}
		this->texture.activate();
		SokuLib::pd3dDev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertices, sizeof(*vertices));
	}

	Sprite::Sprite(const Camera &camera) noexcept :
		RectangularRenderingElement(camera)
	{
	}

	Vector2u Sprite::_getRealSize()
	{
		auto size = RectangularRenderingElement::_getRealSize();

		if (std::abs(static_cast<int>(size.x)) >= 2)
			size.x -= (this->getMirroring().x ? -1 : 1);
		if (std::abs(static_cast<int>(size.y)) >= 2)
			size.y -= (this->getMirroring().y ? -1 : 1);
		return size;
	}
}
}