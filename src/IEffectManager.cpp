//
// Created by Dphoenix on 16/05/2022.
//

#include "SokuAddresses.hpp"
#include "UnionCast.hpp"
#include "IEffectManager.hpp"
#include "AnimationObject.hpp"

static void __declspec(naked) __lower_dtor() {
	__asm {
		sub ecx, 4;
		mov eax, ds:[ecx];
		mov eax, ds:[eax];
		jmp eax;
	}
}

namespace SokuLib {
	void* const __EffectManager_lower_vtable[] = {__lower_dtor};
}