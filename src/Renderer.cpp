//
// Created by PinkySmile on 02/12/2020.
//


#include "Renderer.hpp"
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	// �����_��
	// CRenderer
	Renderer &renderer = *reinterpret_cast<Renderer *>(ADDR_RENDERER);

	bool Renderer::begin()
	{
		return (this->*union_cast<bool (Renderer::*)()>(ADDR_RENDERER_BEGIN))();
	}

	void Renderer::end()
	{
		(this->*union_cast<void (Renderer::*)()>(ADDR_RENDERER_END))();
	}
}