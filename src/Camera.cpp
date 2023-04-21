//
// Created by PinkySmile on 10/03/2021.
//

#include "SokuAddresses.hpp"
#include "Camera.hpp"

namespace SokuLib
{
	Camera &camera = *reinterpret_cast<Camera *>(ADDR_CAMERA_OBJ);

	void Camera::_update1()
	{
		reinterpret_cast<void (__thiscall *)(Camera *)>(0x428e20)(this);
	}

	void Camera::_update2()
	{
		reinterpret_cast<void (__thiscall *)(Camera *)>(0x429040)(this);
	}

	void Camera::update()
	{
		this->_update1();
		this->_update2();
	}
}