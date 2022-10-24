//
// Created by DPhoenix on 20/09/2022.
//

#include "GameObject.hpp"
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

		if (unknown35C) {
			SokuLib::DeleteFct(unknown35C);
			unknown35C = 0;
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

}}