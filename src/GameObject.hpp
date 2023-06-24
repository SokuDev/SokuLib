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
			Player* owner = 0;
			Player* ally = 0;
			Player* opponent = 0;
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
		short hitStop = 0;
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
		virtual void update2() = 0; // seems to update self state
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
		char layer;
		char unknown358[3]; // align 3?
		// an object starts here?
		void* customData = 0;
		short unknown360 = 0; // compared togheter with enemy->TimeStop
		short unknown362 = 0;
		Player* parentPlayer;
		GameObject* parentObject;
		char unknown36C[0x2C]; // 0x364 and 0x398 = owner/parent
		// +378: float

		Player* parentPlayerB;
		GameObject* parentB = 0;
		List<GameObject*> childrenB;

		inline GameObject() { HP = MaxHP = 0; }
		virtual ~GameObject();
		virtual void* createObject(Action actionId, float x, int y, Direction dir, char layer, void* customData, unsigned int customDataSize) = 0;
		virtual void* createChild(Action actionId, float x, int y, Direction dir, char layer, void* customData, unsigned int customDataSize) = 0;

		void setTail(Action actionId, float paramA, int paramB, int paramC, int paramD); // unsure
	};
	class GameObjectAlice : public GameObject { public: char unknown3AC[4]; };

	class IGameObjectList {
	public:
		virtual ~IGameObjectList() = default;
		virtual GameObject* CreateObject(GameObject* parent, Player* ally, Action actionId, float x, float y, Direction direction, char layer, void* customData, unsigned int customDataSize) = 0;
		virtual void Clear() = 0;
		virtual void VUnknown0C() = 0; // call vtable+0x40 in all objects (update?)
		virtual void VUnknown10() = 0; // if(oponent+0x4a8 == 0) call vtable+0x28 in all objects (update?)
		virtual void Render1(char layer) = 0;
		virtual void Render2() = 0;
		virtual void VUnknown1C() = 0; // update camera from objects
		virtual void VUnknown20(Player* from, Player* to) = 0; // change opponent from 'a' to 'b' 
		virtual List<GameObject*>& GetList() = 0;
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
		virtual ~GameObjectList() = default;
		
		SokuLib::v2::GameObject* CreateObject(GameObject* a0, Player* a1, Action a2, float a3, float a4, Direction a5, char a6, void* a7, unsigned int a8) override
			{ return (this->*union_cast<SokuLib::v2::GameObject*(GameObjectList::*)(GameObject*, Player*, Action, float, float, Direction, char, void*, unsigned int)>(base_vtable[1]))(a0, a1, a2, a3, a4, a5, a6, a7, a8); }
		void Clear() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[2]))(); }
		void VUnknown0C() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[3]))(); }
		void VUnknown10() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[4]))(); }
		void Render1(char a0) override { return (this->*union_cast<void(GameObjectList::*)(char)>(base_vtable[5]))(a0); }
		void Render2() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[6]))(); }
		void VUnknown1C() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[7]))(); }
		void VUnknown20(Player* a0, Player* a1) override { return (this->*union_cast<void(GameObjectList::*)(Player*, Player*)>(base_vtable[8]))(a0, a1); }
		List<GameObject*>& GetList() override { return (this->*union_cast<List<GameObject*>& (GameObjectList::*)()>(base_vtable[9]))(); }
	};

	using GameObjectList_Reimu      = GameObjectList<GameObject, (void**)0x85bf1c>;
	using GameObjectList_Marisa     = GameObjectList<GameObject, (void**)0x85c34c>;
	using GameObjectList_Sakuya     = GameObjectList<GameObject, (void**)0x85c6d4>;
	using GameObjectList_Alice      = GameObjectList<GameObjectAlice, (void**)0x85c9c4>;
	using GameObjectList_Patchouli  = GameObjectList<GameObject, (void**)0x85ccfc>;
	using GameObjectList_Youmu      = GameObjectList<GameObject, (void**)0x85cfac>;
	using GameObjectList_Remilia    = GameObjectList<GameObject, (void**)0x85d254>;
	using GameObjectList_Yuyuko     = GameObjectList<GameObject, (void**)0x85d4f4>;
	using GameObjectList_Yukari     = GameObjectList<GameObject, (void**)0x85d78c>;
	using GameObjectList_Suika      = GameObjectList<GameObject, (void**)0x85da54>;
	using GameObjectList_Udonge     = GameObjectList<GameObject, (void**)0x85dd2c>;
	using GameObjectList_Aya        = GameObjectList<GameObject, (void**)0x85e20c>;
	using GameObjectList_Komachi    = GameObjectList<GameObject, (void**)0x85df7c>;
	using GameObjectList_Iku        = GameObjectList<GameObject, (void**)0x85e474>;
	using GameObjectList_Tenshi     = GameObjectList<GameObject, (void**)0x85e6ec>;
	using GameObjectList_Sanae      = GameObjectList<GameObject, (void**)0x85efbc>;
	using GameObjectList_Chirno     = GameObjectList<GameObject, (void**)0x85ea84>;
	using GameObjectList_Meirin     = GameObjectList<GameObject, (void**)0x85ed0c>;
	using GameObjectList_Utsuho     = GameObjectList<GameObject, (void**)0x85f5bc>;
	using GameObjectList_Suwako     = GameObjectList<GameObject, (void**)0x85f28c>;
	using GameObjectList_Namazu     = GameObjectList<GameObject, (void**)0x85f7f4>;

}
}

#endif // SOKULIB_GAMEOBJECT_HPP