//
// Created by DPhoenix on 12/06/2022.
//

#ifndef SOKULIB_GAMEOBJECT_HPP
#define SOKULIB_GAMEOBJECT_HPP

#include "AnimationObject.hpp"
#include "HandleManager.hpp"

namespace SokuLib {
namespace v2 {
	class Player;

	class GameObjectBase : public AnimationObject {
	public:
		// offset 0x158
		struct GameInfo {
			CharacterFrameData* frameData;
			CharacterSequenceData* sequenceData;
			Map<int, CharacterSequenceData*>* patternMap;
			int* soundTable;
			void* owner = 0;
			void* owner2 = 0;
			void* opponent = 0;
		} gameData;
		GameObjectBase* parentA = 0; // composed boundingbox?
		List<GameObjectBase*> childrenA;

		// offset 0x184 (hp and state)
		short HP; // 46b9a0: = 10000
		short MaxHP; // 46b9a0: = 10000
		int unknown188 = 0;
		char unknown18c = 0xff;
		char unknown18d[3]; // align 0x3?
		int collisionType = 0;
		char collisionLimit = 0;
		char unknown195; // align 0x1?
		short unknown196 = 0; // hitStop?
		float unknown198;
		float unknown19C; // 46b9a0: = .0
		char unknown1A0 = 0;
		char unknown1A1 = 0;
		short unknown1A2; // 46b9a0: = 0
		float unknown1A4; // 46b9a0: = .0
		float unknown1A8; // 46b9a0: = .0
		char unknown1AC = 1;
		char unknown1AD[3]; // align 0x3?
		void* unknown1B0 = 0;

		// offset 0x1b4
		struct BoxInfo {
			short prevHP;
			// align 2
			int prevCollisionType;
			char prevCollisionLimit;
			// align 3

			CharacterFrameData* frameData = 0;
			CharacterSequenceData* sequenceData;
			Action actionId;
			Direction direction; // this may be set to 0 in some cases
			char hitBoxCount = 0;
			char hurtBoxCount = 0;
			// align 0x3

			// offset 0x1d0
			Box hurtBoxes[5];
			Box hitBoxes[5];

			// offset 0x270
			RotationBox rotationBuffer[10];
			Box collisionBoxBuffer;

			// offset 0x320
			RotationBox* hitBoxesRotation[5] = {0};
			RotationBox* hurtBoxesRotation[5] = {0};
			Box* collisionBoxPtr = 0;
		} boxData;

		virtual ~GameObjectBase();
		virtual bool initSequence() = 0;
		virtual void VUnknown40() = 0; // seems to update self state
	};

	struct TailObject {
		GameObjectBase* parent;
		int paramB, paramC, unknown0C;
		float paramA; int paramD;
		Vector2f texCoord;
		int texId = 0;
		char unknown24[4]; // bool[2]?
		Deque<Vector2f> unknown28;
		Deque<Vector2f> unknown3C;
		DxVertex* vertexBuffer = 0;

		void initialize(GameObjectBase* parent, FrameData* frameData, float paramA, int paramB, int paramC, int paramD);
		void update();
		void render();
		inline int vertexBufferSize() const { return paramB * paramC * 2 + 2; }
		inline ~TailObject() { if (vertexBuffer) SokuLib::DeleteFct(vertexBuffer); vertexBuffer = 0; }
	};

	class GameObject : public GameObjectBase {
	public:
		int lifetime = 1;
		int handleId = 0;
		TailObject* tail = 0;
		char unknown358[4]; // byte358 may be the layer
		// an object starts here?
		void* unknown35C = 0;
		short unknown360 = 0; // compared togheter with enemy->TimeStop
		short unknown362 = 0;
		void* unknown364;
		char unknown368[0x34]; // 0x364 and 0x398 = owner/parent
		// +378: float

		GameObject* parentB = 0;
		List<GameObject*> childrenB;

		inline GameObject() { HP = MaxHP = 0; }
		virtual ~GameObject();
		virtual void* createObject(Action actionId, float x, int y, Direction dir, char layerMaybe, void* base35C, unsigned int size35C) = 0;
		virtual void* createChild(Action actionId, float x, int y, Direction dir, char layerMaybe, void* base35C, unsigned int size35C) = 0;

		void setTail(Action actionId, float paramA, int paramB, int paramC, int paramD); // unsure
	};
	class GameObjectAlice : public GameObject { public: char unknown3AC[4]; };

	class IGameObjectList {
	public:
		virtual ~IGameObjectList();
		virtual GameObject* VUnknown04(void* parent, void* owner2, int actionId, float x, float y, Direction direction, int layerMaybe, void* base35C, int size35C) = 0;
			// create an object
		virtual void VUnknown08() = 0; // clear objects
		virtual void VUnknown0C() = 0; // call vtable+0x40 in all objects
		virtual void VUnknown10() = 0;
		virtual void VUnknown14(char) = 0; // render all
		virtual void VUnknown18() = 0; // render all
		virtual void VUnknown1C() = 0; // update camera from objects
		virtual void VUnknown20(Player*, Player*) = 0; // change opponent from 'a' to 'b' 
		virtual List<GameObject*>* VUnknown24() = 0; // get List
	};

	// this is used to simulate the double inheritance in GameObjectList
	extern void* const __GameObjectList_lower_vtable[];

	template<class T, void** base_vtable>
	class GameObjectList : public IGameObjectList {
	private:
		static_assert(std::is_base_of<GameObject, T>::value);
		// this is used to simulate the double inheritance in GameObjectList
		void** __lower_vtable = (void**)__GameObjectList_lower_vtable;

	public:
		HandleManagerEx<T> handles;
		List<T*> objectList;
		Player* player;

		inline GameObjectList(Player* player) : player(player) {} // TODO i think it reserves 256 objects, but not sure
		virtual ~GameObjectList() {}
		virtual GameObject* VUnknown04(void* parent, void* owner2, int actionId, float x, float y, Direction direction, int layerMaybe, void* base35C, int size35C)
			{ return (this->*union_cast<GameObject*(GameObjectList::*)(void*, void*, int, float, float, Direction, int, void*, int)>(base_vtable[1]))
				(parent, owner2, actionId, x, y, direction, layerMaybe, base35C, size35C); }
		virtual void VUnknown08()
			{ return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[2]))(); }
		virtual void VUnknown0C()
			{ return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[3]))(); }
		virtual void VUnknown10()
			{ return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[4]))(); }
		virtual void VUnknown14(char layer)
			{ return (this->*union_cast<void(GameObjectList::*)(char)>(base_vtable[5]))(layer); }
		virtual void VUnknown18()
			{ return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[6]))(); }
		virtual void VUnknown1C()
			{ return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[7]))(); }
		virtual void VUnknown20(Player* a, Player* b)
			{ return (this->*union_cast<void(GameObjectList::*)(Player*, Player*)>(base_vtable[8]))(a, b); }
		virtual List<GameObject*>* VUnknown24()
			{ return (this->*union_cast<List<GameObject*>* (GameObjectList::*)()>(base_vtable[9]))(); }
	};
}
}

#endif // SOKULIB_GAMEOBJECT_HPP