//
// Created by Dphoenix on 16/05/2022.
//

#include "SokuAddresses.hpp"
#include "UnionCast.hpp"
#include "IEffectManager.hpp"
#include "AnimationObject.hpp"
#include "VTables.hpp"

static void __declspec(naked) __lower_dtor() {
	__asm {
		sub ecx, 4;
		mov eax, ds:[ecx];
		mov eax, ds:[eax];
		jmp eax;
	}
}

#define IMPL_EFFECTMANAGER_VIRTUALS(CLS, VTB) \
	void CLS::LoadPattern(const char* fileName, int reserve) \
		{ return (this->*union_cast<void(CLS::*)(const char*, int)>(VTB[1]))(fileName, reserve); } \
	void CLS::ClearPattern() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[2]))(); } \
	SokuLib::v2::EffectObjectBase* CLS::CreateEffect(int action, float x, float y, char dir, char layer, int unknown164) \
		{ return (this->*union_cast<SokuLib::v2::EffectObjectBase*(CLS::*)(int, float, float, char, char, int)>(VTB[3]))(action, x, y, dir, layer, unknown164); } \
	void CLS::ClearEffects() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[4]))(); } \
	void CLS::Update() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[5]))(); } \
	void CLS::Render(char arg_0) \
		{ return (this->*union_cast<void(CLS::*)(int)>(VTB[6]))(arg_0); } \
	void CLS::vfUnknown7() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[7]))(); } \
	void CLS::vfUnknown8(int arg_0) \
		{ return (this->*union_cast<void(CLS::*)(int)>(VTB[8]))(arg_0); }

namespace SokuLib {
	const int _vtable_info<v2::EffectManager_Effect>::baseAddr      = ADDR_VTBL_FXMANAGER_EFFECT;
	const int _vtable_info<v2::EffectManager_InfoEffect>::baseAddr  = ADDR_VTBL_FXMANAGER_INFOFX;
	const int _vtable_info<v2::EffectManager_Select>::baseAddr      = ADDR_VTBL_FXMANAGER_SELECT;
	const int _vtable_info<v2::EffectManager_Weather>::baseAddr     = ADDR_VTBL_FXMANAGER_WEATHER;

	void* const __EffectManager_lower_vtable[] = {__lower_dtor};

	IMPL_EFFECTMANAGER_VIRTUALS(v2::EffectManager_Effect, ((void** const)SokuLib::ADDR_VTBL_FXMANAGER_EFFECT))
	IMPL_EFFECTMANAGER_VIRTUALS(v2::EffectManager_InfoEffect, ((void** const)SokuLib::ADDR_VTBL_FXMANAGER_INFOFX))
	IMPL_EFFECTMANAGER_VIRTUALS(v2::EffectManager_Select, ((void** const)SokuLib::ADDR_VTBL_FXMANAGER_SELECT))
	IMPL_EFFECTMANAGER_VIRTUALS(v2::EffectManager_Weather, ((void** const)SokuLib::ADDR_VTBL_FXMANAGER_WEATHER))
}