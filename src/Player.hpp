//
// Created by DPhoenix on 20/09/2022.
//

#ifndef SOKULIB_PLAYER_HPP
#define SOKULIB_PLAYER_HPP

#include "GameObject.hpp"
#include "Deque.hpp"
#include "Character.hpp"

namespace SokuLib {
namespace v2 {
	class Player : public GameObjectBase {
	public:
		// offset 0x34C
		Character characterIndex;
		char teamId;
		char paletteId;
		char unknown352[0x2]; // align 0x2?
		int portraitTexId = 0;
		Sprite portrait;

		// offset 0x3EC
		struct StandInfo {
			int texId = 0;
			Sprite sprite;

			// offset 0x484
			int teamId;
			int standState; // 0x46eb80: = -1; -1: stand hide, 0: stand roll in, 1: stand keep, 2: stand fade out
			int standCounter;
			float standOffset;// x axis offset; y fixed 32.0f
			unsigned char standOpacity;
			// align 3
			//void FUN_46ec50(); //begin
			//void FUN_46ec90(); //update
		} stand;

		union ComboModifers {
			char value;
			struct {
				/* 0x01 */ bool liftAttack: 1;
				/* 0x02 */ bool smashAttack: 1;
				/* 0x04 */ bool borderResist: 1;
				/* 0x08 */ bool chainArt: 1;
				/* 0x10 */ bool chainSpell: 1;
				/* 0x20 */ bool counter: 1;
			};
		};

		// offset 0x498
		short redHP;
		char groundDashCount, airDashCount, unknown49C; // = 0
		bool guardSucceed; // = 0; indicates that guarding move has successfully blocked
		short currentSpirit, maxSpirit; // = 100
		short spiritRegenDelay, timeWithBrokenOrb, spellStopCounter, timeStop, blockDisabled; // = 0
		char unknown4AC;
		ComboModifers comboModifiers; // = 0
		char unknown4AE[2]; // align 2?
		float comboRate; // = 1.0
		short comboCount, comboDamage, comboLimit, untech;
		short poiseTimer, realLimit; // = 0
		short comboTimer, unknown4C2; // = 0
		char unknown4C4, unknown4C5; // 48b000: +0x4c4 = 0 align 1?
		short unknown4C6; // = 0; 
		int skillCancelCount; // = 0
		bool cardsShuffled, hasSpotlight; // = 0
		short spotlightStrength; // = 0
		float speedPower; // = 1.0
		short riverMistCounter, unknown4D6; // = 0
		char unknown4D8; // = 0
		char unknown4D9[3]; // align 3?
		int unknown4DC[16]; // = 0
		short meleeInvulTimer, grabInvulTimer, projectileInvulTimer, grazeTimer; // = 0
		short confusionDebuffTimer, SORDebuffTimer, healCharmTimer; // = 0
		char unknown52A, unknown52B; // 48b000: +0x52A = 0 align 1?
		int weatherId; // = 0;

		// 0x530: = {1,1,1,1, 0,1,1,1, 0,0,0,1};
		float attackPower;
		float defensePower;
		float poiseDmgMultiplier; // Affects poise damage taken from attack; 0 means super armor
		float limitMultiplier; // used by Sakuya's time stop
		float bonusProration;
		float spellDmgMultiplier;
		float specialDmgMultiplier;
		float meterGainMultiplier;
		float lifeStealMultiplier;
		float discardMultiplier;
		float reflectDamageMultiplier; // Normally at 0. Used for Suwako's blue curse
		float unknown55C;

		short grimoireCount; // = 0
		char unknown562[2]; // align 2?
		float speedXMultiplier, speedYMultiplier;

		// 0x56C: = {0,0,0,0, 0,1,1,0, 0,0,0,0, 0,?,?,?};
		bool canGrazeMelee, crushOnWB, skillsMax, unknown56F;
		bool cardsHidden, lockedInStageX, lockedInStageY;
		unsigned char score;
		unsigned char roundsWins, knockOutState, unknown576, kdAnimationFinished, unknown578;
		unsigned char unknown579[3]; // align 3?

		//offset 0x57c
		struct DeckInfo {
			Deque<int> textures;
			Map<int, SokuLib::CardInfo> cardById;
			Deque<unsigned short> original;
			Deque<unsigned short> queue;
			unsigned char availSkills[32]; // 435a50: for (cardById) if (type = skill) availSkills[CardData.costOrSlot] = id

			SokuLib::CardInfo *cardLookup(unsigned short id);
			void addTexture(int *t);
		} deckInfo;

		// offset 0x5e4
		struct HandInfo {
			short cardGauge;
			unsigned char cardCount;
			unsigned char cardSlots;

			Deque<SokuLib::Card> hand;
			Deque<unsigned short> usedCards;
		} handInfo;

		// offset 0x610
		Sprite unknown610;
		// offset 0x6A4
		char effectiveSkillLevel[32]; // this one starts as 0
		char skilledSkillLevel[32]; // this one starts as -1 (except the first four reset in: 48b000)
		int unknown6E4, unknown6E8; // 46b9a0: = 0
		int unknown6EC, unknown6F0; // 46b9a0: = -1
		char unknown6F4, unknown6F5; // 46b9a0: = 0
		char unknown6F6[2]; // align 2?

		// offset 0x6f8
		IGameObjectList* objectList;
		Deque<CharacterSequenceData> patternData;
		
		int trailTimer; // 46b9a0: = 0
		struct TrailImage {
			using SpriteTrail = struct {
				SpriteEx sprite;
				char mode;//blend mode 0: normal, 1: add, 2:sub
				char unknownf1[3];//align 3
			};
			List<SpriteTrail> trailSprites;
			char trailStep = 5;//skip n-1 sprites by n step when rendering
			char unknown721;//align 1?
			short trailLength = 15;
			unsigned int colorMask;//4631e9: masking trail sprites color (not for alpha)
			char unknown728; // 46b9a0: = 0
			char unknown729[3];// align 3?
			//void FUN_463440(); //append, has a bug that forgets to reset color after rendering shadow
			//void FUN_463330(); //clear
			//void FUN_463100(); //render
		} trailImage;

		Deque<int> spellBgTextures;
		short spellBgTimer; // = 0
		unsigned char spellBgId;
		char unknown743;
		Vector2f additionalSpeed; // 46b9a0: = .0
		float riverMistAdditionalSpeed; // 46b9a0: = .0

		// offset 0x750
		KeyManager* keyManager;
		struct InputInfo {
			// offset 0x754
			KeyInputLight keyInput; // sizeof = 0x20
			// offset 0x774
			KeyInputLight bufferedKeyInput;
			// offset 0x794
			int keyUpA, keyUpB, keyUpC, keyUpD, keyUpE, keyUpF; // 46cac0: = 0;
			char bufferTimer; // 46cac0: = 0;
			char unknown7AD[3]; // align 3?
			// offset 0x7B0
			Deque<unsigned short> commandInputBuffer;
			MovementCombination movementCombination; // 46b9a0: = 0
			CommandCombination commandCombination; // 46b9a0: = 0
			char inputType = 0; // type of input? (checks for 0, 1 or 2)
			// align 0x3
		} inputData;

		short gpShort[5]; // = { 0 }; 0x7D0 - 0x7D8
		char unknown7DA[2]; // align 2?
		float gpFloat[5]; // = { 0 }; 0x7DC - 0x7EC
		float decidedShotAngle; // result of decideShotAngle
		bool chargedAttack; // = false;
		bool blockObjectSpawned;
		char unknown7F6;
		bool damageLimited = false; // = 0;
		short noGainTimer = 0; // = 0; set to 120 during spell action
		char unknown7FA[2]; // align 2?
		float unknown7FC = 0; // = .0;
		bool skillCancelsUsed[5]; // = 0;
		char unknown805[3]; // align 3?
		float riverMistTimer; // = .0;
		bool forceBounce = false; // 48b000: (+80D, +80E) = .0; (+80D = isAuraActive)
		char unknown80D = 0; // 48b000: (+80D, +80E) = .0; (+80D = isAuraActive)
		bool isBELocked = false; // Automatically set to true when opponent is in a spell animation (between 600 and 688)
		char unknown80F = 0; // 48b000: (+80D, +80E) = .0; (+80D = isAuraActive)
		int unknown810 = 0, unknown814 = 0; // 48b000: = 0; (auraFXDelay, auraDuration)
		short unknown818[10]; // = 0;
		float unknown82C = 0, unknown830 = 0; // = .0;
		short tenguFans = 0; // = 0;
		bool lockCardUse; // +0x836 = 0; mainly for hakuroken
		char unknown837;
		float unknown838 = 0; // = .0;
		char unknown83C = 0; // = 0;
		char unknown83D[3]; // align 3?
		float sacrificialDolls, controlRod, magicPotionTimeLeft; // = .0;
		short stopwatchTimeLeft, dragonStarTimeLeft, drops, dropInvulTimeLeft; // = 0;
		float unknown854;
		float unknown858;
		float unknown85C;
		float unknown860;
		float unknown864 = 0; // = .0;
		char unknown868 = 0; // +0x868 = 0; align 1?
		char unknown869;
		short unknown86A = 0; // = 0;
		int unknown86C = 0; // = 0;
		int unknown870;
		int unknown874;
		int unknown878;
		int unknown87C;
		char unknown880;
		char unknown881 = 0; // +0x880 = 0; align 1?
		short unknown882;
		short unknown884;
		short unknown886;
		short unknown888;
		short unknown88A;
		Vector2<short> spinRotationCenter = {0, 0};
		// found shared data until size: 0x890 (0x48b088: short this[0x88e])

		Player(const PlayerInfo& playerInfo);
		~Player() override;

		void initializeAction() override;
		void applyTransform() override;
		void updatePhysics() override;
		virtual void initialize(); // character specific initialization
		virtual bool handleGroundMovement(); // handle landing, walking, jump, crouch input
		virtual bool setScenarioAction(int scenarioActionId); // remap story scenario action to real action stuff
		virtual void handleInputs() = 0; // seems to handle inputs (differs for each character)
		virtual void checkAllMotionInputs(); // compare input buffer for sequences
		virtual void computerInputs() = 0;// generate computer AI input
		virtual void updateStory() = 0; //
		virtual bool setCustomScenarioAction(int customScenarioActionId) = 0; //handle character specified scenario action, ret true means repeat instruction

		// Gets the character from this->characterIndex
		void loadResources(); // 0x46c0b0
		bool updateGroundMovement(float value); // 0x487740
		float decideShotAngle(float, float); // 0x4877C0
		void addCardMeter(int); // 0x487870
		bool handleCardSwitch(); // 0x487890 input related
		bool useSystemCard(int moveLock); // 0x48a700
		bool canSpendSpirit(); // 0x4878c0 input related (canSpendSpirit???)
		unsigned short getMoveLock(unsigned short action); // 0x489610
		bool canActivateCard(int slot);// 0x468e80
		bool handleHJ(); // 0x487900 input related
		bool handleHJInput(int moveLock, int hjCancelable); // 0x489e90
		bool handleGroundDash(int moveLock, int hjCancelable); // 0x48a220
		bool handleGroundBE(); // 0x487990 input related
		bool handleAirBE(); // 0x487ab0 input related
		bool handleFwdAirDash(int moveLock, int hjCancelable, int allowedAirMoves, int airDashCancelSeq); // 0x48a380
		bool handleBackAirDash(int moveLock, int hjCancelable, int allowedAirMoves, int airDashCancelSeq); // 0x48a470
		bool handleNormalFlight(int moveLock, int hjCancelable, int allowedAirMoves); // 0x48a560
		void useSpellCard(int id, short action); // 0x487b60 (+0x4ad flag 0x10)
		void useSkill(int id, short action); // 0x487ba0 (+0x4ad flag 0x08)
		void onSkillUpgrade(); // 0x489660
		void checkTurnAround(); // swapDirection?
		void playSpellBackground(int id, int timer);
		bool applyGroundMechanics(); // 0x487ca0
		// 0x487e90 always returns zero
		bool applyAirMechanics(); // 0x487ea0
		void playSFX(int id); // 0x464980
		void consumeSpirit(int cost, int delay); // 0x47a9e0
		void consumeCard(int index = 0, int costOverride = 0, int cardNameTimer = 60); // 0x469c70
		void eventSkillUse(); // 0x483ce0
		void eventSpellUse(); // 0x483d60
		void eventWeatherCycle(); // 0x483db0
		void refreshInputCombination(); // 0x46d950
		void refreshInputBuffer(); // 0x46cac0
		bool isGrounded(); // 0x463530
		void updateDefaultBehavior();
		void setTrailImage(int timer, int step, unsigned int colorMask); //0x46a750
		SokuLib::v2::GameObject* createObject(short action, float x, float y, char direction, char layer, float *extraData, unsigned int extraDataSize); // 46eb30
		SokuLib::v2::GameObject *createObject(short action, float x, float y, char direction, char layer);
		template<size_t size>
		SokuLib::v2::GameObject *createObject(short action, float x, float y, char direction, char layer, float (&extraData)[size]) {
			// Mimics 0x46EB30
			return this->objectList->createObject(nullptr, this, action, x, y, direction, layer, extraData, size);
		}

		template<typename T, typename = std::enable_if_t<std::is_base_of_v<Player, T>>>
		T &to() {
			return *reinterpret_cast<T *>(this);
		}

		template<typename T, typename = std::enable_if_t<std::is_base_of_v<Player, T>>>
		T &to() const {
			return *reinterpret_cast<const T *>(this);
		}
	};
	static_assert(sizeof(Player) == 0x890);

#define DECL_PLAYER_VIRTUALS() \
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
	void initialize() override; \
	bool handleGroundMovement() override; \
	bool setScenarioAction(int scenarioActionId) override; \
	void handleInputs() override; \
	void checkAllMotionInputs() override; \
	void computerInputs() override; \
	void updateStory() override; \
	bool setCustomScenarioAction(int customScenarioActionId) override;

	class PlayerReimu : public Player {
	public:
		short rodSpawned;//the dropping gohei(purification rod) when Reimu got hit
		char unknown892[0x2];//align 2?
		int unknown894[8];//4ac600: = 0, maybe for replaced SWR cards

		unsigned short fantasyHeavenTimer;
		unsigned short fantasyHeavenStacks;//0~7
		unsigned short fantasyHeavenAlreadyHit;// 0~1 hit recorded
		bool dsRiftUsed;//block another Demon Sealing use before landed
		char unknown8BB;//align 1?

		PlayerReimu(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerReimu) == 0x8BC);

	class PlayerMarisa : public Player {
	public:
		unsigned short orreriesAttackType;//0: None, 1:B bullets, [2~5]: B emitter index, 8:C lasers, 50: thrown boomerang
		unsigned short orreriesTimer;//countdown 600f
		unsigned short orreriesActiveTimer;//countdown, B:40f, C:60f
		char unknown896[2];//align 2?

		float orreriesRotatePhase;// -=speed
		float orreriesRotateSpeed;//type0: 3, type1: 12, type8: 0.5, type50: 12
		Vector2f orreriesThrowPos;//record decided target pos when throwing out
		bool orreriesThrown;//reusing 2sc throws orreries out as boomerang
		char unknown8A9[3];//align 3?

		PlayerMarisa(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerMarisa) == 0x8AC);

	class PlayerSakuya : public Player {
	public:
		unsigned short worldTimer;//countdown | The World:300f, Luna Dial:210f
		unsigned short psTimer;//Private Square, countdown 300f
		unsigned short stopwatchTimer;//4SC Stopwatch
		unsigned short unknown896;//4fdf9b: = 0
		unsigned short noLimitTimer;//also lessen rate loss by 0.25
		unsigned short dsSwordCount;//Dancing Star Sword
		bool dsSwordTriggering;//signal one sword to shoot out
		char unknown89D[3];//align 3?

		PlayerSakuya(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerSakuya) == 0x8A0);

	class PlayerAlice : public Player {
	public:
		unsigned short SPdollCount;//0x890 max 3
		unsigned short dollCount;//0x892 max 4
		unsigned short unknown894, unknown896;//5235a4: =0
		unsigned short SPcirclePhase;//0x898 0~359 looping
		short DRTdollCount;//0x89A used by story SC: Knight "Doll of Round Table"
		float dollPosX[4], dollPosY[4];//0x89C~0x8B8 used by Seeker Wire tracing
		bool SPdollTriggering;//used by SP, signal one/all dolls to shoot laser
		bool dollTriggering[4];//used by Seeker Wire, signal the ready C doll to next seq
		char unknown8c1[3];//align 3?

		PlayerAlice(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerAlice) == 0x8C4);

	class PlayerPatchouli : public Player {
	public:
		unsigned short philStoneTimer;//countdown 1200f
		unsigned short unknown892;//56413c: =360, only set when jellyfish bubble is breached, but never reset or used
		short unknown894, unknown896, unknown898, unknown89A;//554c70: = 0, maybe for replaced SWR cards
		unsigned short atmEdgeActivationTime;//countdown 2f, if >0 and lv1+, triggers autumn edge to trace
		short sBubbleHitCount;//0~10
		unsigned short dHardnessTimer;//0x8A0
		unsigned short jfPrincessTimer;//countdown 360f
		float sprWindSpeed;//B:14.5, C:18.5

		PlayerPatchouli(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerPatchouli) == 0x8A8);

	class PlayerYoumu : public Player {
	public:
		struct CloneData {
			CharacterFrameData* frameData;
			Vector2f position, center, scale;
			float rotationX, rotationY, rotationZ;
			Direction direction;
			char hitCount;//set along with youmu's collisionLimit
			char unknown2A[2];//align 2?
		} cloneData;//size 0x2C
		Deque<CloneData> cloneBuffer;//ring history buffer, maximum 60 clones
		bool myonSpawned;//done in initAction...
		bool myonAttackActivated;
		short myonAttackType;//None:0, (j)5C:1, (j)6C:2, (j)2C:3, d22B:4, d22C:7, a122:5, a222B:6, a222C:8, eye slash:10
		unsigned short mediumBindTimer;// =(Lv+6)*30
		unsigned short cloneTimer;// 600f
		short cloneActivated;//block meter gain, but only set in 2sc clone
		char unknown8DA[2];//align 2?
		//implemente bullet-cutting in story spell: Closed-Eye Slash "The Bullet-Cutting Spirit Eye from Roukan"
		float eyeSlashPosX, eyeSlashPosY, eyeSlashRotZ;
		bool eyeSlashActivated;
		char unknown8E9[3];//align 3?

		PlayerYoumu(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerYoumu) == 0x8EC);

	class PlayerRemilia : public Player {
	public:
		unsigned short millVampireTimer;
		char unknown892[0x02];//align 2?

		PlayerRemilia(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerRemilia) == 0x894);

	class PlayerYuyuko : public Player {
	public:
		//story spell: Banquet "All Things Come Full Circle in Death"
		int banquetRestTimer;//rest 180f after rings reached max
		int banquetElapsedTime;//dec by frame
		int banquetRingCount;//max E/N/H/L: 1/3/4/6
		int unknown89C;//5b8170: = 0
		int resButterfliesUsed;
		int giftsCount;//Gifts to the Deceased, 0~8
		int giftsTimer;//countdown Lv*30+(count+1)*20 frames

		PlayerYuyuko(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerYuyuko) == 0x8AC);

	class PlayerYukari : public Player {
	public:
		short parasolSpawned;//the dropping parasol when Yukari got hit
		short gapAbsorbCount;//0~13
		bool unknown894;// =0, set 0 when ran is destroyed, but never used?
		char unknown895;// =0, unused?
		char unknown896[2];//align 2?
		//Universe of Matter and Antimatter
		float antimatterPosX[2], antimatterPosY[2];
		short antimatterCount;//0~2
		//story spell: Fantacy Nest "Flying Noctilucae's Nest"
		short fireflyFireTimer;//E/N/H/L:180/210/240/270
		short fireflyRestTimer;//120~179 random
		//story spell: Aerial Bait "Hyperactive High Speed Flying Object"
		short flyObjAimedCD;//EN/H/L:70/65/60, additional aimed bait when hp below 1/3
		short flyObjTimer;//E/N/H/L:45/80/115/150, gen new line per 10f
		short flyObjLines;//horizontal line index, inc from 0
		//Wings of Chimera
		short wingsCount;//0~3
		char unknown8B6[2];//align 2?
		float wingsPosX[3], wingsPosY[3];
		//story spell: "Yakumo's Nest"
		short yakumoNestElapsedTime;//inc by frame, fire per 300f
		char unknown8D2[2];//align 2?

		PlayerYukari(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerYukari) == 0x8D4);

	class PlayerSuika : public Player {
	public:
		unsigned short gakiBindTimer;//countdown 600f, dec opponent's spirit by 2 per frame (regen delay 30f)
		unsigned short mppTimer;//countdown 480f
		bool upMistUsed;//block another Unpleasant Mist before landed
		char unknown895[3];

		PlayerSuika(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerSuika) == 0x898);

	class PlayerUdonge : public Player {
	public:
		short unkown890;// =0
		short reisenOpacity;//0~255
		float reisenOpacityFactor;//normally 1.0, invisible 6D related; towards 0.5 with Infrared Moon

		unsigned short urFieldActive;
		unsigned short uvFieldActive;
		float scanAngle;//Eyesight Cleansing scan range angle
		int elixirUsed;
		int elixirElapsedTime;
		short uvCloneCount;//0~2
		char unknown8AA[2];//align 2?
		float uvCloneSpacing;//horizontal
		unsigned short xwaveTimeLeft;//countdown 360f
		unsigned short infraredMoonTimeLeft;
		bool ocularSpectralUsed;//block another Ocular Spectral before landed
		char unknown8B5[3];//align 3?

		PlayerUdonge(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerUdonge) == 0x8B8);

	class PlayerAya : public Player {
	public:
		short pebbleCount;//maximum 20
		short limitedSpecialTimeLeft;//2sc speed up, ground 360f/ air 450f countdown
		short routeForbiddenTimeLeft;//300f countdown
		bool unknown896;//block Graceful Dash if true, but never set?
		char unknown897;//align 1?

		PlayerAya(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerAya) == 0x898);

	class PlayerKomachi : public Player {
	public:
		short unknown890;//656d06: = 0
		char unknown892[2];//align 2?
		int wispActivationTime;//countdown 2f(a214)/10f(2C), spirits will be activated if > 0

		PlayerKomachi(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerKomachi) == 0x898);

	class PlayerIku : public Player {
	public:
		//story spell: Cloud Realm "The Thunder Court in the Sea of Abstruse Clouds"
		int realmTotalTimer;//harassing fire CD ENH/L:300/240f
		int realmLaserCount;//E/N/H/L: 4/6/7/8
		int realmTimer;// E/N/H/L: 150/140/130/120f per turn, gen new laser per 8 frames

		unsigned short veilsLikeSky;//0x89c, 900f countdown
		unsigned short veilsLikeTime;//0x89e, 600f countdown

		unsigned short cutsceneColor;//0x8a0 as story cutscene color (channel G/B) for iku's stage entrance, 0~255 increased by frame
		char unknown8A2[2];//align 2?
		float backgroundOffset;//change stage#4 background horizon for stage entrance cutscene

		PlayerIku(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerIku) == 0x8A8);

	class PlayerTenshi : public Player {
	public:
		float pillarHeights[8];
		float keystonePosX[12], keystonePosY[12]; // used by story spell: Spirit Thought "Stone that Calms the Lands"
		float keystoneIndex;//0x910 0~11 looping
		float backgroundOffset;//0x914 change stage#5 background horizon for the last 2 story spells
		bool pillarEnabled;//0x918
		char unknown919;//align 1?

		unsigned short guardingKeystonesTimer;//0x91a
		unsigned short guardingKeystonesType;//0x91c 0 for None, 1 for B ver, 2 for C ver
		char unknown91E[2];//align 2?
		int guardingKeystonesCount;//0x920

		int stateOfEnlightenmentTimeLeft;
		//story spell: Spirit Thought "Stone that Calms the Lands"
		int spiritThoughtTimer;//inc, drop CD E/N/H/L: 120/80/60/50f

		bool skyAttackUsed; //0x92c block movement cancel or another sky attack before landed
		char unknown92D;//align 1?

		short swordState;// for final spell ko cutscene, 0= not started, 1 = flying, 2 = landed

		PlayerTenshi(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerTenshi) == 0x930);

	class PlayerSanae : public Player {
	public:
		float windSpeed;//flight wind
		float windAngle;
		Direction windDirection;
		char unknown899[3];//align 3?

		int kanakoCdTimer;//countdown reference kanakoCD, dec by frame
		int suwakoCdTimer;//countdown reference suwakoCD, dec by frame
		int kanakoCooldown;//reference value, changed with skill level
		int suwakoCooldown;//reference value, changed with skill level

		bool bshotTriggering;//signal B bullet to emit
		bool star2cTrigerring;//signal (j)2C star to emit
		bool blackoutSpawned;//used by sanae story blackout narrative
		char unknown8AF;//align 1?
		
		PlayerSanae(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerSanae) == 0x8B0);

	class PlayerChirno : public Player {
	public:
		int freezeAtmosphereTimeLeft;//used by 3SC Freeze Atmosphere, 180f countdown

		PlayerChirno(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerChirno) == 0x894);

	class PlayerMeirin : public Player {
	public:
		int tigerEnergyReleaseTimeLeft;

		PlayerMeirin(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerMeirin) == 0x894);

	class PlayerUtsuho : public Player {
	public:
		bool capeDisabled;
		char unknown891[3];//align 3?
		int capeTexture;
		float capeOffset;//texture x+y axis moving, +0.25 per frame, 0~255 looping
		bool bshotTriggering;//signal 5B/J5B/J2B... to emit
		bool unknown89d;//7b5eba: = 0
		char unknown89e[0x2];//align 2?
		int unknown8a0;//timer for an unused sc #616 like iku's Stickleback, 600f countdown
		int abyssNovaGlow;//0~255; btw nova explosion timer is handled by a UtsuhoObject

		PlayerUtsuho(const PlayerInfo&);
		~PlayerUtsuho() override;
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerUtsuho) == 0x8A8);

	class PlayerSuwako : public Player {
	public:
		bool unknown890;//782982: = 0
		bool rock5cTriggering;//0x891 signal L5C/J5C rocks to emit
		char unknown892[2];//align 2?
		int curseType;//0x894, enum {None=0, Red, Green, Blue}
		int punishType;//0x898, enum {None=0, Crush, Block, Attack, Dash}
		bool orbsSpawned;//0x89C
		bool orbsFastSpin;//0x89D(unused)
		char unknown89E[2];//align 2
		int curseTimer;//0x8A0
		int punishTimer;//0x8A4

		PlayerSuwako(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerSuwako) == 0x8A8);

	class PlayerNamazu : public Player {
	public:
		char unknown890[0x10];

		PlayerNamazu(const PlayerInfo&);
		DECL_PLAYER_VIRTUALS()
	};
	static_assert(sizeof(PlayerNamazu) == 0x8A0);

	extern unsigned char &firstPlayerRendered;
}}

#endif