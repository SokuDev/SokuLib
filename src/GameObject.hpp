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
		enum CollisionType {
			COLLISION_TYPE_NONE,
			COLLISION_TYPE_HIT,
			COLLISION_TYPE_BLOCKED,
			COLLISION_TYPE_INVUL,
			COLLISION_TYPE_BULLET_COLLIDE_HIGH_DENSITY,
			COLLISION_TYPE_BULLET_ABSORBED,
			COLLISION_TYPE_GRAZED,
			COLLISION_TYPE_ARMORED,
			COLLISION_TYPE_BULLET_COLLIDE_SAME_DENSITY,
			COLLISION_TYPE_HIT_ENTITY
		};

		// offset 0x158
		struct GameInfo {
			CharacterFrameData* frameData;
			CharacterSequenceData* sequenceData;
			Map<int, CharacterSequenceData*>* patternMap;
			int* soundTable;
			Player* owner = nullptr;
			Player* ally = nullptr;
			Player* opponent = nullptr;
		} gameData;
		// offset 0x174
		GameObjectBase* parentA = nullptr; // composed boundingbox?
		List<GameObjectBase*> childrenA;

		// offset 0x184 (hp and state)
		short hp; // = 10000
		short maxHP; // = 10000
		int superArmorDamageTaken = 0;
		char skillIndex = -1;
		char unknown18d[3]; // align 0x3?
		CollisionType collisionType = COLLISION_TYPE_NONE;
		char collisionLimit = 0;
		char unknown195; // align 0x1?
		short hitStop = 0;
		float counterHitDmgMultiplier = 1;
		float unknown19C; // = .0
		char reflectCounter = 0; // used by youmu reflection shield
		char unknown1A1 = 0;
		short forcedCounterHits = 0; // = 0
		Vector2f hitLaunchSpeed; // = {0,0}, set by attack framedata, used by air hit action
		bool allowEntity = true; // entity collision will be ignored if 0
		char unknown1AD[3]; // align 0x3?// offset 0x1b0
		struct CustomHitBox {
			Box box;
			short rotation;
			Vector2<short> rotationAnchor;
		} *customHitBox = nullptr;

		// offset 0x1B4
		struct BoxInfo {
			short prevHP;
			// align 2
			int prevCollisionType;
			char prevCollisionLimit;
			// align 3

			// offset 0x1C0
			CharacterFrameData* frameData = nullptr;
			CharacterSequenceData* sequenceData;
			Action actionId; // (short)
			char direction; // (char) this may be set to 0 in some cases
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
			RotationBox* hitBoxesRotation[5] = {nullptr};
			RotationBox* hurtBoxesRotation[5] = {nullptr};
			Box* collisionBoxPtr = nullptr;
		} boxData;

		~GameObjectBase() override;
		void setActionSequence(short action, short sequence) override;
		bool setAction(short action) override;
		void setSequence(short sequence) override;
		void resetSequence() override;
		bool nextSequence() override;
		void prevSequence() override;
		void setPose(short pose) override;
		bool nextPose() override;
		void prevPose() override;
		virtual void initializeAction() = 0; // 0x3C
		virtual void updatePhysics(); // 0x40

		void reflectedBy(GameObjectBase *other); // 465100
		void initDefaultObject(); // 48d000
		void updateDefaultObject(); // 48db20
		void initWeatherDebuffEffect(); // 48cb50
		void updateWeatherDebuffEffect(); // 48c980
		void resetForces(); // 4636b0
		float getGroundHeight() const; // 4397f0
		bool isOnGround() const; //439850
		void setHitBoxData(int left, int top, int right, int bottom, short rotation, short rotAnchorX, short rotAnchorY); // 4b0e40;
		void setClipMask(short actionId); //0x466670; only support 1 bit alpha
		void damageOpponent(int damage, int rate, short hitCount, bool applyModifiers); // 0x4649b0: :Rate is *1000 (850 is 85% rate)
		void setParentA(GameObjectBase *player); // 0x50ced0
		GameObjectBase* createEffect(int action, float x, float y, int dir, char layer); // 438ce0
	}; // 0x34C

	struct TailObject {
		GameObjectBase* parent;
		int length, subdivide, unknown0C;
		float width; int mode;
		Vector2f texCoord;
		int texId = 0;
		char unknown24[4]; // bool[2]?

		// offset 0x28
		Deque<Vector2f> unknown28;
		Deque<Vector2f> unknown3C;

		// offset 0x50
		DxVertex* vertexBuffer = nullptr;

		void initialize(GameObjectBase* parent, FrameData* frameData, float width, int length, int subdivide, int mode);
		void update();
		void render();
		inline int vertexBufferSize() const { return length * subdivide * 2 + 2; }
		inline ~TailObject() { if (vertexBuffer) SokuLib::DeleteFct(vertexBuffer); vertexBuffer = 0; }
	};

	class GameObject : public GameObjectBase {
	public:
		// offset 0x34C
		int lifetime = 1;
		int handleId = 0;
		TailObject* tail = nullptr;
		char layer;
		char unknown359[3]; // align 3?
		// offset 0x35C: an object starts here?
		float* customData = nullptr;
		short ignoreOwnerTimestop = 0; // compared togheter with enemy->TimeStop; 1 means object won't be stopped by timestop from owner
		short unknown362 = 0;
		Player* parentPlayer;
		GameObject* parentObject;

		// General purpose counters (0x36C)
		short gpShort[5] = {0};
		char unknown376[2]; // align 2?
		float gpFloat[5] = {0};
		float transformedVelocityAngle, transformedVelocitySpeed; //result of FUN_48c650
		short grazeCounter = 0;
		short otherProjectileHit = 0;

		// offset 0x398
		Player* parentPlayerB;
		GameObject* parentB = nullptr;
		List<GameObject*> childrenB;

		inline GameObject() {
			this->hp = 0;
			this->maxHP = 0;
		}
		virtual ~GameObject();
		virtual GameObject* createObject(short actionId, float x, float y, char dir, char layer, float* customData, unsigned int customDataSize) = 0;
		virtual GameObject* createChild(short actionId, float x, float y, char dir, char layer, float* customData, unsigned int customDataSize) = 0;

		void setParentB(GameObject *parent); // 74C890
		void trackOpponent(float minTurn, float maxTurn, float yOffset); // 48CCA0
		void transformVelocity(float angle, float speed, float rotation, float xScale, float yScale); // 48C650
		bool checkGrazed(int density);
		bool checkProjectileHit(int density);
		bool checkTurnIntoCrystals(bool onlyAirHit, int bigCrystalCount, int smallCrystalCount, float offsetX = 0, float offsetY = 0); // 48CE90
		void setTail(short actionId, float width, int length, int subdivide, int mode); // subdivide unsure
		void removeTail(); //4B0F20
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
	void initializeAction() override; \
	void updatePhysics() override; \
	GameObject* createObject(short, float, float, char, char, float*, unsigned int) override; \
	GameObject* createChild(short, float, float, char, char, float*, unsigned int) override;

	class GameObjectReimu     : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectMarisa    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectSakuya    : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectAlice     : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS()
		short dollIndex;//0x3ac 0~3, used by C dolls
		char unknown3AE[2]; // align 2?
	};
	class GameObjectPatchouli : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS() };
	class GameObjectYoumu     : public GameObject { public: DECL_GAMEOBJECT_VIRTUALS()
		void updateClone(int index);//57d000
	};
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

	// this is used to simulate the double inheritance in GameObjectList
	extern void* const __GameObjectList_lower_vtable[];

	class IGameObjectList {
	private:
		// this is used to simulate the double inheritance in GameObjectList
		void** __lower_vtable = (void**)__GameObjectList_lower_vtable;

	public:
		virtual ~IGameObjectList() = default;
		virtual SokuLib::v2::GameObject* createObject(GameObject* a0, Player* a1, short a2, float a3, float a4, char a5, char a6, void* a7, unsigned int a8) = 0;
		virtual void clear() = 0;
		virtual void updatePhysics() = 0;
		virtual void update() = 0;
		virtual void render1(char layer) = 0;
		virtual void render2() = 0;
		virtual void updateCamera() = 0;
		virtual void replaceOpponent(Player* a0, Player* a1) = 0;
		virtual List<GameObject*>& getList() = 0;
	};

	template<class T>
	class GameObjectList : public IGameObjectList {
		static_assert(std::is_base_of<GameObject, T>::value);

	public:
		HandleManagerEx<T> handles;
		List<T*> objectList;
		Player* player;

		inline GameObjectList(Player* player) : player(player) {} // TODO i think it reserves 256 objects, but not sure
		virtual ~GameObjectList() = default;
		void clear() override { return (this->*union_cast<void(GameObjectList::*)()>(0x633E00))(); }
		void updatePhysics() override { return (this->*union_cast<void(GameObjectList::*)()>(0x783FE0))(); }
		void update() override { return (this->*union_cast<void(GameObjectList::*)()>(0x633CE0))(); }
		void render1(char a0) override { return (this->*union_cast<void(GameObjectList::*)(char)>(0x59BE00))(a0); }
		void render2() override { return (this->*union_cast<void(GameObjectList::*)()>(0x784000))(); }
		void updateCamera() override { return (this->*union_cast<void(GameObjectList::*)()>(0x7EC330))(); }
		void replaceOpponent(Player* a0, Player* a1) override { return (this->*union_cast<void(GameObjectList::*)(Player*, Player*)>(0x5DEC10))(a0, a1); }
		List<GameObject*>& getList() override { return (this->*union_cast<List<GameObject*>& (GameObjectList::*)()>(0x4D2600))(); }

		template<class T2>
		GameObjectList<T2> *to() { return reinterpret_cast<GameObjectList<T2> *>(this); }
	};

	template<class T, unsigned base_vtable>
	class VTableGameObjectList : public GameObjectList<T> {
	public:
		inline VTableGameObjectList(Player* player) : GameObjectList<T>(player) {} // TODO i think it reserves 256 objects, but not sure

		GameObject* createObject(GameObject* a0, Player* a1, short a2, float a3, float a4, char a5, char a6, void* a7, unsigned int a8) override
		{
			auto addr = ((void **)base_vtable)[1];
			auto fct = union_cast<GameObject*(VTableGameObjectList::*)(GameObject*, Player*, short, float, float, char, char, void*, unsigned int)>(addr);

			return (this->*fct)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
		}
	};

	using GameObjectList_Reimu      = VTableGameObjectList<GameObjectReimu,     0x85bf1c>;
	using GameObjectList_Marisa     = VTableGameObjectList<GameObjectMarisa,    0x85c34c>;
	using GameObjectList_Sakuya     = VTableGameObjectList<GameObjectSakuya,    0x85c6d4>;
	using GameObjectList_Alice      = VTableGameObjectList<GameObjectAlice,     0x85c9c4>;
	using GameObjectList_Patchouli  = VTableGameObjectList<GameObjectPatchouli, 0x85ccfc>;
	using GameObjectList_Youmu      = VTableGameObjectList<GameObjectYoumu,     0x85cfac>;
	using GameObjectList_Remilia    = VTableGameObjectList<GameObjectRemilia,   0x85d254>;
	using GameObjectList_Yuyuko     = VTableGameObjectList<GameObjectYuyuko,    0x85d4f4>;
	using GameObjectList_Yukari     = VTableGameObjectList<GameObjectYukari,    0x85d78c>;
	using GameObjectList_Suika      = VTableGameObjectList<GameObjectSuika,     0x85da54>;
	using GameObjectList_Udonge     = VTableGameObjectList<GameObjectUdonge,    0x85dd2c>;
	using GameObjectList_Aya        = VTableGameObjectList<GameObjectAya,       0x85e20c>;
	using GameObjectList_Komachi    = VTableGameObjectList<GameObjectKomachi,   0x85df7c>;
	using GameObjectList_Iku        = VTableGameObjectList<GameObjectIku,       0x85e474>;
	using GameObjectList_Tenshi     = VTableGameObjectList<GameObjectTenshi,    0x85e6ec>;
	using GameObjectList_Sanae      = VTableGameObjectList<GameObjectSanae,     0x85efbc>;
	using GameObjectList_Chirno     = VTableGameObjectList<GameObjectChirno,    0x85ea84>;
	using GameObjectList_Meirin     = VTableGameObjectList<GameObjectMeirin,    0x85ed0c>;
	using GameObjectList_Utsuho     = VTableGameObjectList<GameObjectUtsuho,    0x85f5bc>;
	using GameObjectList_Suwako     = VTableGameObjectList<GameObjectSuwako,    0x85f28c>;
	using GameObjectList_Namazu     = VTableGameObjectList<GameObjectNamazu,    0x85f7f4>;

}
}

#endif // SOKULIB_GAMEOBJECT_HPP