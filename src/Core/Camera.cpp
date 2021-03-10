//
// Created by PinkySmile on 10/03/2021.
//

#include "SokuAddresses.hpp"
#include "Camera.hpp"

namespace SokuLib
{
	Camera &camera = *reinterpret_cast<Camera *>(ADDR_CAMERA_OBJ);
}