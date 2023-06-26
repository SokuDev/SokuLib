//
// Created by DPhoenix on 20/09/2022.
//

#include "GameObject.hpp"
#include "VTables.hpp"
#include <algorithm>

static void __declspec(naked) __lower_dtor() {
	__asm {
		sub ecx, 4;
		mov eax, ds:[ecx];
		mov eax, ds:[eax];
		jmp eax;
	}
}

template<class T, typename V>
static inline void _erase(T& container, V value) {
	auto it = container.begin();
	while(it != container.end()) {
		if (*it == value) it = container.erase(it);
		else ++it;
	}
}

namespace SokuLib {
	const int _vtable_info<v2::GameObjectReimu>::baseAddr       = 0x0085bebc;
	const int _vtable_info<v2::GameObjectMarisa>::baseAddr      = 0x0085c2ec;
	const int _vtable_info<v2::GameObjectSakuya>::baseAddr      = 0x0085c674;
	const int _vtable_info<v2::GameObjectAlice>::baseAddr       = 0x0085c964;
	const int _vtable_info<v2::GameObjectPatchouli>::baseAddr   = 0x0085cc9c;
	const int _vtable_info<v2::GameObjectYoumu>::baseAddr       = 0x0085cf4c;
	const int _vtable_info<v2::GameObjectRemilia>::baseAddr     = 0x0085d1f4;
	const int _vtable_info<v2::GameObjectYuyuko>::baseAddr      = 0x0085d494;
	const int _vtable_info<v2::GameObjectYukari>::baseAddr      = 0x0085d72c;
	const int _vtable_info<v2::GameObjectSuika>::baseAddr       = 0x0085d9f4;
	const int _vtable_info<v2::GameObjectUdonge>::baseAddr      = 0x0085dccc;
	const int _vtable_info<v2::GameObjectAya>::baseAddr         = 0x0085e1ac;
	const int _vtable_info<v2::GameObjectKomachi>::baseAddr     = 0x0085df1c;
	const int _vtable_info<v2::GameObjectIku>::baseAddr         = 0x0085e414;
	const int _vtable_info<v2::GameObjectTenshi>::baseAddr      = 0x0085e68c;
	const int _vtable_info<v2::GameObjectSanae>::baseAddr       = 0x0085ef5c;
	const int _vtable_info<v2::GameObjectChirno>::baseAddr      = 0x0085ea24;
	const int _vtable_info<v2::GameObjectMeirin>::baseAddr      = 0x0085ecac;
	const int _vtable_info<v2::GameObjectUtsuho>::baseAddr      = 0x0085f55c;
	const int _vtable_info<v2::GameObjectSuwako>::baseAddr      = 0x0085f22c;
	const int _vtable_info<v2::GameObjectNamazu>::baseAddr      = 0x0085f794;

namespace v2 {
	void* const __GameObjectList_lower_vtable[] = {__lower_dtor};

	GameObjectBase::~GameObjectBase() {
		if (unknown1B0) { SokuLib::DeleteFct((void*)unknown1B0); unknown1B0 = 0; }
		if (parentA) _erase(parentA->childrenA, this);
		for (auto it : childrenA) it->parentA = 0;
	}

	GameObject::~GameObject() {
		if (parentB) _erase(parentB->childrenB, this);
		for (auto it : childrenB) it->parentB = 0;

		if (customData) {
			SokuLib::DeleteFct(customData);
			customData = 0;
		}

		if (tail) {
			// unknown object destructor
			reinterpret_cast<void (__fastcall*)(void*)>(0x433c60)(tail);
			SokuLib::DeleteFct(tail);
			tail = 0;
		}
	}

	void GameObject::setTail(Action actionId, float paramA, int paramB, int paramC, int paramD) {
		return (this->*union_cast<void (GameObject::*)(Action, float, int, int, int)>(0x4b0f50))
			(actionId, paramA, paramB, paramC, paramD);
	}

	void TailObject::initialize(GameObjectBase* parent, FrameData* frameData, float paramA, int paramB, int paramC, int paramD) {
		return (this->*union_cast<void (TailObject::*)(GameObjectBase*, FrameData*, float, int, int, int)>(0x433f90))
			(parent, frameData, paramA, paramB, paramC, paramD);
	}

	void TailObject::update() { return (this->*union_cast<void (TailObject::*)()>(0x434230))(); }

	void TailObject::render() { return (this->*union_cast<void (TailObject::*)()>(0x433dc0))(); }

#define IMPL_GAMEOBJECT_VIRTUALS(CLS, VTB) \
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
	bool CLS::initSequence() \
		{ return (this->*union_cast<bool(CLS::*)()>(VTB[15]))(); } \
	void CLS::update2() \
		{ return (this->*union_cast<void(CLS::*)()>(VTB[16]))(); } \
	SokuLib::v2::GameObject* CLS::createObject(SokuLib::Action a0, float a1, int a2, SokuLib::Direction a3, char a4, void* a5, unsigned int a6) \
		{ return (this->*union_cast<SokuLib::v2::GameObject*(CLS::*)(SokuLib::Action, float, int, SokuLib::Direction, char, void*, unsigned int)>(VTB[17]))(a0, a1, a2, a3, a4, a5, a6); } \
	SokuLib::v2::GameObject* CLS::createChild(SokuLib::Action a0, float a1, int a2, SokuLib::Direction a3, char a4, void* a5, unsigned int a6) \
		{ return (this->*union_cast<SokuLib::v2::GameObject*(CLS::*)(SokuLib::Action, float, int, SokuLib::Direction, char, void*, unsigned int)>(VTB[18]))(a0, a1, a2, a3, a4, a5, a6); }

	IMPL_GAMEOBJECT_VIRTUALS(GameObjectReimu,     ((void** const)_vtable_info<GameObjectReimu>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectMarisa,    ((void** const)_vtable_info<GameObjectMarisa>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectSakuya,    ((void** const)_vtable_info<GameObjectSakuya>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectAlice,     ((void** const)_vtable_info<GameObjectAlice>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectPatchouli, ((void** const)_vtable_info<GameObjectPatchouli>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectYoumu,     ((void** const)_vtable_info<GameObjectYoumu>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectRemilia,   ((void** const)_vtable_info<GameObjectRemilia>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectYuyuko,    ((void** const)_vtable_info<GameObjectYuyuko>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectYukari,    ((void** const)_vtable_info<GameObjectYukari>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectSuika,     ((void** const)_vtable_info<GameObjectSuika>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectUdonge,    ((void** const)_vtable_info<GameObjectUdonge>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectAya,       ((void** const)_vtable_info<GameObjectAya>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectKomachi,   ((void** const)_vtable_info<GameObjectKomachi>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectIku,       ((void** const)_vtable_info<GameObjectIku>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectTenshi,    ((void** const)_vtable_info<GameObjectTenshi>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectSanae,     ((void** const)_vtable_info<GameObjectSanae>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectChirno,    ((void** const)_vtable_info<GameObjectChirno>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectMeirin,    ((void** const)_vtable_info<GameObjectMeirin>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectUtsuho,    ((void** const)_vtable_info<GameObjectUtsuho>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectSuwako,    ((void** const)_vtable_info<GameObjectSuwako>::baseAddr))
	IMPL_GAMEOBJECT_VIRTUALS(GameObjectNamazu,    ((void** const)_vtable_info<GameObjectNamazu>::baseAddr))
}}