//
// Created by Dphoenix on 20/07/2022.
//

#include "AnimationObject.hpp"
#include "UnionCast.hpp"
#include "VTables.hpp"

#define IMPL_EFFECTOBJECT_VIRTUALS(CLS, VTB)  \
	void CLS::setActionSequence(short a0, short a1) \
		{ return (this->*union_cast<void(CLS::*)(short, short)>(VTB[1]))(a0, a1); } \
	bool CLS::setAction(short a0) \
		{ return (this->*union_cast<bool(CLS::*)(short)>(VTB[2]))(a0); } \
	void CLS::setSequence(short a0) \
		{ return (this->*union_cast<void(CLS::*)(short)>(VTB[3]))(a0); } \
	void CLS::resetSequence() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[4]))(); } \
	bool CLS::nextSequence() \
		{ return (this->*union_cast<bool(CLS::*)()>(VTB[5]))(); } \
	void CLS::prevSequence() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[6]))(); } \
	void CLS::setPose(short a0) \
		{ return (this->*union_cast<void(CLS::*)(short)>(VTB[7]))(a0); } \
	bool CLS::nextPose() \
		{ return (this->*union_cast<bool(CLS::*)()>(VTB[8]))(); } \
	void CLS::prevPose() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[9]))(); } \
	void CLS::update() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[10]))(); } \
	void CLS::render() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[11]))(); } \
	void CLS::render2() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[12]))(); } \
	void CLS::applyTransform() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[13]))(); } \
	void CLS::onRenderEnd() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[14]))(); } \
	bool CLS::initializeAction() \
		{ return (this->*union_cast<bool(CLS::*)()>(VTB[15]))(); }

namespace SokuLib {
	const int _vtable_info<v2::EffectObject>::baseAddr          = ADDR_VTBL_FX_EFFECT;
	const int _vtable_info<v2::InfoEffectObject>::baseAddr      = ADDR_VTBL_FX_INFOFX;
	const int _vtable_info<v2::SelectEffectObject>::baseAddr    = ADDR_VTBL_FX_SELECT;
	const int _vtable_info<v2::WeatherEffectObject>::baseAddr   = ADDR_VTBL_FX_WEATHER;

namespace v2 {
	AnimationObject::~AnimationObject() { if (unknown154) SokuLib::Delete(unknown154); unknown154 = 0; }

	bool AnimationObject::advanceFrame() { return (this->*union_cast<bool (AnimationObject::*)()>(0x438c60))(); }
	void AnimationObject::setActionSequence(short action, short sequence) { return (this->*union_cast<void (AnimationObject::*)(short, short)>(0x438cc0))(action, sequence); }
	bool AnimationObject::setAction(short action) { return (this->*union_cast<bool (AnimationObject::*)(short)>(0x438ca0))(action); }
	void AnimationObject::render() { return (this->*union_cast<void (AnimationObject::*)()>(0x438d20))(); }
	void AnimationObject::render2() { return (this->*union_cast<void (AnimationObject::*)()>(0x439190))(); }
	void AnimationObject::applyTransform() { return (this->*union_cast<void (AnimationObject::*)()>(0x438E00))(); }
	void AnimationObject::onRenderEnd() { return (this->*union_cast<void (AnimationObject::*)()>(0x439040))(); }
	void AnimationObject::resetRenderInfo() { return (reinterpret_cast<void (__thiscall *)(SpriteEx &)>(0x438BB0))(this->sprite); }
	void AnimationObject::updateSpeedAngled(float angle, float velocity) { return (reinterpret_cast<void (__thiscall *)(SpriteEx &, float, float)>(0x438C00))(this->sprite, angle, velocity); }

	IMPL_EFFECTOBJECT_VIRTUALS(EffectObject, ((void** const)SokuLib::ADDR_VTBL_FX_EFFECT))
	IMPL_EFFECTOBJECT_VIRTUALS(InfoEffectObject, ((void** const)SokuLib::ADDR_VTBL_FX_INFOFX))
	IMPL_EFFECTOBJECT_VIRTUALS(SelectEffectObject, ((void** const)SokuLib::ADDR_VTBL_FX_SELECT))
	IMPL_EFFECTOBJECT_VIRTUALS(WeatherEffectObject, ((void** const)SokuLib::ADDR_VTBL_FX_WEATHER))
}
}