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
		// offset 0x174
		GameObjectBase* parentA = 0; // composed boundingbox?
		List<GameObjectBase*> childrenA;

		// offset 0x184 (hp and state)
		short HP; // = 10000
		short MaxHP; // = 10000
		int unknown188 = 0;
		char unknown18c = -1;
		char unknown18d[3]; // align 0x3?
		int collisionType = 0;
		char collisionLimit = 0;
		char unknown195; // align 0x1?
		short hitStop = 0;
		float unknown198;
		float unknown19C; // = .0
		char unknown1A0 = 0;
		char unknown1A1 = 0;
		short unknown1A2; // = 0
		float unknown1A4; // = .0
		float unknown1A8; // = .0
		char unknown1AC = 1;
		char unknown1AD[3]; // align 0x3?
		void* unknown1B0 = 0;

		// offset 0x1B4
		struct BoxInfo {
			short prevHP;
			// align 2
			int prevCollisionType;
			char prevCollisionLimit;
			// align 3

			// offset 0x1C0
			CharacterFrameData* frameData = 0;
			CharacterSequenceData* sequenceData;
			Action actionId; // (short)
			Direction direction; // (char) this may be set to 0 in some cases
			char hitBoxCount = 0;
			char hurtBoxCount = 0;
			// align 0x3

			// offset 0x1D0
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
		virtual bool initializeAction() = 0;
		virtual void updatePhysics() = 0;
	}; // 0x34C

	struct TailObject {
		GameObjectBase* parent;
		int paramB, paramC, unknown0C;
		float paramA; int paramD;
		Vector2f texCoord;
		int texId = 0;
		char unknown24[4]; // bool[2]?

		// offset 0x28
		Deque<Vector2f> unknown28;
		Deque<Vector2f> unknown3C;

		// offset 0x50
		DxVertex* vertexBuffer = 0;

		void initialize(GameObjectBase* parent, FrameData* frameData, float paramA, int paramB, int paramC, int paramD);
		void update();
		void render();
		inline int vertexBufferSize() const { return paramB * paramC * 2 + 2; }
		inline ~TailObject() { if (vertexBuffer) SokuLib::DeleteFct(vertexBuffer); vertexBuffer = 0; }
	};

	class GameObject : public GameObjectBase {
	public:
		// offset 0x34C
		int lifetime = 1;
		int handleId = 0;
		TailObject* tail = 0;
		char layer;
		char unknown359[3]; // align 3?
		// offset 0x35C: an object starts here?
		void* customData = 0;
		short unknown360 = 0; // compared togheter with enemy->TimeStop
		short unknown362 = 0;
		Player* parentPlayer;
		GameObject* parentObject;
		char unknown36C[0x2C]; // +0x378: float

		// offset 0x398
		Player* parentPlayerB;
		GameObject* parentB = 0;
		List<GameObject*> childrenB;

		inline GameObject() { HP = MaxHP = 0; }
		virtual ~GameObject();
		virtual GameObject* createObject(Action actionId, float x, int y, Direction dir, char layer, void* customData, unsigned int customDataSize) = 0;
		virtual GameObject* createChild(Action actionId, float x, int y, Direction dir, char layer, void* customData, unsigned int customDataSize) = 0;

		void setTail(Action actionId, float paramA, int paramB, int paramC, int paramD); // unsure
	}; // 0x3AC

#define DECL_GAMEOBJECT_VIRTUALS() \
	void setActionSequence(short, short) override; \
	bool setAction(short) override; \
	void setSequence(short) override; \
	void resetSequence() override; \
	bool nextSequence() override; \
	void prevSequence() override; \
	void setPose(short) override; \
	bool nextPose() override; \
	void prevPose() override; \
	void update() override; \
	void render() override; \
	void render2() override; \
	void applyTransform() override; \
	void onRenderEnd() override; \
	bool initializeAction() override; \
	void updatePhysics() override; \
	GameObject* createObject(Action, float, int, Direction, char, void*, unsigned int) override; \
	GameObject* createChild(Action, float, int, Direction, char, void*, unsigned int) override;

	class GameObjectReimu     : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectMarisa    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectSakuya    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectAlice     : public GameObject { public: char unknown3AC[4]; DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectPatchouli : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectYoumu     : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectRemilia   : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectYuyuko    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectYukari    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectSuika     : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectUdonge    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectAya       : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectKomachi   : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectIku       : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectTenshi    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectSanae     : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectChirno    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectMeirin    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectUtsuho    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectSuwako    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectNamazu    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };

	class IGameObjectList {
	public:
		virtual ~IGameObjectList() = default;
		virtual GameObject* CreateObject(GameObject* parent, Player* ally, Action actionId, float x, float y, Direction direction, char layer, void* customData, unsigned int customDataSize) = 0;
		virtual void Clear() = 0;
		virtual void UpdatePhysics() = 0;
		virtual void Update() = 0;
		virtual void Render1(char layer) = 0;
		virtual void Render2() = 0;
		virtual void UpdateCamera() = 0;
		virtual void ReplaceOpponent(Player* from, Player* to) = 0; // change opponent from 'a' to 'b' 
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
		void UpdatePhysics() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[3]))(); }
		void Update() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[4]))(); }
		void Render1(char a0) override { return (this->*union_cast<void(GameObjectList::*)(char)>(base_vtable[5]))(a0); }
		void Render2() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[6]))(); }
		void UpdateCamera() override { return (this->*union_cast<void(GameObjectList::*)()>(base_vtable[7]))(); }
		void ReplaceOpponent(Player* a0, Player* a1) override { return (this->*union_cast<void(GameObjectList::*)(Player*, Player*)>(base_vtable[8]))(a0, a1); }
		List<GameObject*>& GetList() override { return (this->*union_cast<List<GameObject*>& (GameObjectList::*)()>(base_vtable[9]))(); }
	};

	using GameObjectList_Reimu      = GameObjectList<GameObjectReimu,     (void**)0x85bf1c>;
	using GameObjectList_Marisa     = GameObjectList<GameObjectMarisa,    (void**)0x85c34c>;
	using GameObjectList_Sakuya     = GameObjectList<GameObjectSakuya,    (void**)0x85c6d4>;
	using GameObjectList_Alice      = GameObjectList<GameObjectAlice,     (void**)0x85c9c4>;
	using GameObjectList_Patchouli  = GameObjectList<GameObjectPatchouli, (void**)0x85ccfc>;
	using GameObjectList_Youmu      = GameObjectList<GameObjectYoumu,     (void**)0x85cfac>;
	using GameObjectList_Remilia    = GameObjectList<GameObjectRemilia,   (void**)0x85d254>;
	using GameObjectList_Yuyuko     = GameObjectList<GameObjectYuyuko,    (void**)0x85d4f4>;
	using GameObjectList_Yukari     = GameObjectList<GameObjectYukari,    (void**)0x85d78c>;
	using GameObjectList_Suika      = GameObjectList<GameObjectSuika,     (void**)0x85da54>;
	using GameObjectList_Udonge     = GameObjectList<GameObjectUdonge,    (void**)0x85dd2c>;
	using GameObjectList_Aya        = GameObjectList<GameObjectAya,       (void**)0x85e20c>;
	using GameObjectList_Komachi    = GameObjectList<GameObjectKomachi,   (void**)0x85df7c>;
	using GameObjectList_Iku        = GameObjectList<GameObjectIku,       (void**)0x85e474>;
	using GameObjectList_Tenshi     = GameObjectList<GameObjectTenshi,    (void**)0x85e6ec>;
	using GameObjectList_Sanae      = GameObjectList<GameObjectSanae,     (void**)0x85efbc>;
	using GameObjectList_Chirno     = GameObjectList<GameObjectChirno,    (void**)0x85ea84>;
	using GameObjectList_Meirin     = GameObjectList<GameObjectMeirin,    (void**)0x85ed0c>;
	using GameObjectList_Utsuho     = GameObjectList<GameObjectUtsuho,    (void**)0x85f5bc>;
	using GameObjectList_Suwako     = GameObjectList<GameObjectSuwako,    (void**)0x85f28c>;
	using GameObjectList_Namazu     = GameObjectList<GameObjectNamazu,    (void**)0x85f7f4>;

}
}

#endif // SOKULIB_GAMEOBJECT_HPP