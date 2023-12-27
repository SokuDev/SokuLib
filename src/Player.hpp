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
	//! @brief Holds all the information tied to a player during battle.
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
			int playerId;
			int unknown488; // 0x46eb80: = -1;
			Vector2f unknown48C; // some coord
			char unknown494;
			// align 3

			//void FUN_46ec50();
		} stand;

		// offset 0x498
		short redHP;
		char groundDashCount, airDashCount, unknown49C, unknown49D; // = 0
		short currentSpirit, maxSpirit; // = 100
		short spiritRegenDelay, timeWithBrokenOrb, unknown4A6, timeStop, unknown4AA; // = 0
		char unknown4AC, unknown4AD; // = 0
		char unknown4AE[2]; // align 2?
		float comboRate; // = 1.0
		short comboCount, comboDamage, comboLimit, untech;
		short unknown4BC, realLimit; // = 0
		short unknown4C0, unknown4C2; // = 0
		char unknown4C4, unknown4C5; // 48b000: +0x4c4 = 0 align 1?
		short unknown4C6; // = 0
		int unknown4C8; // = 0
		char unknown4CC, hasSpotlight; // = 0
		short spotlightStrength; // = 0
		float speedPower; // = 1.0
		short riverMistCounter, unknown4D6; // = 0
		char unknown4D8; // = 0
		char unknown4D9[3]; // align 3?
		int unknown4DC[16]; // = 0
		short meleeInvulTimer, grabInvulTimer, projectileInvulTimer, unknown522; // = 0
		short unknown524, SORDebuffTimer, healCharmTimer; // = 0
		char unknown52A, unknown52B; // 48b000: +0x52A = 0 align 1?
		int weatherId; // = 0;

		// 0x530: = {1,1,1,1, 0,1,1,1, 0,0,0,1};
		float attackPower, defensePower;
		float unknown538, unknown53C, unknown540;
		float spellDmgMultiplier, specialDmgMultiplier, meterGainMultiplier, lifeStealMultiplier, discardMultiplier;
		float unknown558, unknown55C;

		short grimoireCount; // = 0
		char unknown562[2]; // align 2?
		float speedXMultiplier, speedYMultiplier;

		// 0x56C: = {0,0,0,0, 0,1,1,0, 0,0,0,0, 0,?,?,?};
		bool canGrazeMelee, crushOnWB, skillsMax, unknown56F;
		bool unknown570, lockedInStageX, lockedInStageY; unsigned char score;
		unsigned char roundsWins, unknown575, unknown576, unknown577, unknown578;
		unsigned char unknown579[3]; // align 3?

		//offset 0x57c
		struct DeckInfo {
			Deque<int> textures;
			Map<int, SokuLib::CardInfo> cardById;
			Deque<unsigned short> original;
			Deque<unsigned short> queue;
			unsigned char availSkills[32]; // 435a50: for (cardById) if (type = skill) availSkills[CardData.costOrSlot] = id

			SokuLib::CardInfo* cardLookup(unsigned short id);
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
		char skillLevelA[32]; // this one starts as 0
		char skillLevelB[32]; // this one starts as -1 (except the first four reset in: 48b000)
		int unknown6E4, unknown6E8; // 46b9a0: = 0
		int unknown6EC, unknown6F0; // 46b9a0: = -1
		char unknown6F4, unknown6F5; // 46b9a0: = 0
		char unknown6F6[2]; // align 2?

		// offset 0x6f8
		IGameObjectList* objectList;
		Deque<CharacterSequenceData> patternData;
		int unknown710; // 46b9a0: = 0

		struct {
			List<SpriteEx> unknown714; // unsure (maybe struct {SpriteEx,byte})
			char unknown720 = 5;
			char unknown721;
			short unknown722 = 15;
			char unknown724[4];
			char unknown728; // 46b9a0: = 0
			char unknown729[3];
		} unknown714;

		Deque<int> spellBgTextures;
		short spellBgTimer; // = 0
		unsigned char spellBgId;
		char unknown743;
		float additionalSpeedX; // 46b9a0: = .0
		float unknown748; // 46b9a0: = .0
		float riverMistAdditionalSpeed; // 46b9a0: = .0

		// offset 0x750
		KeyManager& keyManager;
		struct InputInfo {
			// offset 0x754
			KeyInput keyInput; // sizeof = 0x20
			// offset 0x774
			KeyInput buffererdKeyInput;
			// offset 0x794
			int keyUpA, keyUpB, keyUpC, keyUpD, keyUpE, keyUpF; // 46cac0: = 0;
			char bufferTimer; // 46cac0: = 0;
			char unknown7AD[3]; // align 3?
			// offset 0x7B0
			Deque<unsigned short> commandInputBuffer;
			int movimentCombination; // 46b9a0: = 0
			KeyCombination commandCombination; // 46b9a0: = 0
			char unknown7CC; // type of input? (checks for 0, 1 or 2)
			// align 0x3
		} inputData;

		short unknown7D0[5]; // = 0;
		char unknown7DA[2]; // align 0x2?
		float unknown7DC[6]; // = .0;
		bool chargedAttack; char unknown7F5[2]; bool damageLimited; // = 0;
		short unknown7F8; // = 0;
		char unknown7FA[2]; // align 2?
		float unknown7FC; // = .0;
		char unknown800[5]; // = 0;
		char unknown805[3]; // align 3?
		float riverMistTimer; // = .0;
		char unknown80C[4]; // 48b000: (+80D, +80E) = .0; (+80D = isAuraActive)
		int unknown810, unknown814; // 48b000: = 0; (auraFXDelay, auraDuration)
		short unknown818[10]; // = 0;
		float unknown82C, unknown830; // = .0;
		short tenguFans; // = 0;
		char unknown836[2]; // +0x836 = 0; align 1?
		float unknown838; // = .0;
		char unknown83C; // = 0;
		char unknown83D[3]; // align 3?
		float sacrificialDolls, controlRod, magicPotionTimeLeft; // = .0;
		short stopwatchTimeLeft, dragonStarTimeLeft, drops, dropInvulTimeLeft; // = 0;
		float unknown854[5]; // = .0;
		char unknown868[2]; // +0x868 = 0; align 1?
		short unknown86A; // = 0;
		int unknown86C[5]; // = 0;
		char unknown880[2]; // +0x880 = 0; align 1?
		short unknown882[7]; // = 0;
		// found shared data until size: 0x890 (0x48b088: short this[0x88e])

		Player(const PlayerInfo& playerInfo);
		virtual ~Player();

		virtual void initialize() = 0; // character specific initialization
		virtual bool VUnknown48() = 0; // check for landing
		virtual bool VUnknown4C(int a) = 0; // something with actionId in [700,799]
		virtual void VUnknown50() = 0; // seems to handle inputs (differs for each character)
		virtual void VUnknown54() = 0; // compare input buffer for sequences

		// Gets the character from this->characterIndex
		void loadResources(); // 0x46c0b0
		bool updateGroundMovement(float value); // 0x487740
		bool updateAirMovement(float, float); // 0x4877C0
		void addCardMeter(float); // 0x487870
		// 0x487890 input related
		// 0x4878c0 input related
		// 0x487900 input related
		// 0x487990 input related
		// 0x487ab0 input related
		// 0x487b60 (+0x4ad flag 0x10)
		// 0x487ba0 (+0x4ad flag 0x08)
		void Unknown487C20(); // swapDirection?
		void playSpellBackground(int id, int timer);
		bool applyGroundMechanics(); // 0x487ca0
		// 0x487e90 always returns zero
		bool applyAirMechanics(); // 0x487ea0
		void playSFX(int id); // 0x464980
		void consumeSpirit(int cost, int delay); // 0x47a9e0
		void consumeCard(int index, int costOverride = 0, int cardNameTimer = 60); // 0x469c70
		void eventSkillUse(); // 0x483ce0
		void eventSpellUse(); // 0x483d60
		void eventWeatherCycle(); // 0x483db0
	};

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
	bool initializeAction() override; \
	void updatePhysics() override; \
	void initialize() override; \
	bool VUnknown48() override; \
	bool VUnknown4C(int a) override; \
	void VUnknown50() override; \
	void VUnknown54() override;

	class PlayerReimu     : public Player { public: char unknown890[0x2C]; DECL_PLAYER_VIRTUALS() PlayerReimu(const PlayerInfo&); };
	class PlayerMarisa    : public Player { public: char unknown890[0x1C]; DECL_PLAYER_VIRTUALS() PlayerMarisa(const PlayerInfo&); };
	class PlayerSakuya    : public Player { public: char unknown890[0x10]; DECL_PLAYER_VIRTUALS() PlayerSakuya(const PlayerInfo&); };
	class PlayerAlice     : public Player { public: char unknown890[0x34]; DECL_PLAYER_VIRTUALS() PlayerAlice(const PlayerInfo&); };
	class PlayerPatchouli : public Player { public: char unknown890[0x18]; DECL_PLAYER_VIRTUALS() PlayerPatchouli(const PlayerInfo&); };
	class PlayerYoumu     : public Player { public: char unknown890[0x5C]; DECL_PLAYER_VIRTUALS() PlayerYoumu(const PlayerInfo&); ~PlayerYoumu(); };
	class PlayerRemilia   : public Player { public: char unknown890[0x04]; DECL_PLAYER_VIRTUALS() PlayerRemilia(const PlayerInfo&); };
	class PlayerYuyuko    : public Player { public: char unknown890[0x1C]; DECL_PLAYER_VIRTUALS() PlayerYuyuko(const PlayerInfo&); };
	class PlayerYukari    : public Player { public: char unknown890[0x44]; DECL_PLAYER_VIRTUALS() PlayerYukari(const PlayerInfo&); };
	class PlayerSuika     : public Player { public: char unknown890[0x08]; DECL_PLAYER_VIRTUALS() PlayerSuika(const PlayerInfo&); };
	class PlayerUdonge    : public Player { public: char unknown890[0x28]; DECL_PLAYER_VIRTUALS() PlayerUdonge(const PlayerInfo&); };
	class PlayerAya       : public Player { public: char unknown890[0x08]; DECL_PLAYER_VIRTUALS() PlayerAya(const PlayerInfo&); };
	class PlayerKomachi   : public Player { public: char unknown890[0x08]; DECL_PLAYER_VIRTUALS() PlayerKomachi(const PlayerInfo&); };
	class PlayerIku       : public Player { public: char unknown890[0x18]; DECL_PLAYER_VIRTUALS() PlayerIku(const PlayerInfo&); };
	class PlayerTenshi    : public Player { public: char unknown890[0xA0]; DECL_PLAYER_VIRTUALS() PlayerTenshi(const PlayerInfo&); }; // TODO There's something wrong with tenshi
	class PlayerSanae     : public Player { public: char unknown890[0x20]; DECL_PLAYER_VIRTUALS() PlayerSanae(const PlayerInfo&); };
	class PlayerChirno    : public Player { public: char unknown890[0x04]; DECL_PLAYER_VIRTUALS() PlayerChirno(const PlayerInfo&); };
	class PlayerMeirin    : public Player { public: char unknown890[0x04]; DECL_PLAYER_VIRTUALS() PlayerMeirin(const PlayerInfo&); };
	class PlayerUtsuho    : public Player { public: char unknown890[0x18]; DECL_PLAYER_VIRTUALS() PlayerUtsuho(const PlayerInfo&); ~PlayerUtsuho(); };
	class PlayerSuwako    : public Player { public: char unknown890[0x18]; DECL_PLAYER_VIRTUALS() PlayerSuwako(const PlayerInfo&); };
	class PlayerNamazu    : public Player { public: char unknown890[0x10]; DECL_PLAYER_VIRTUALS() PlayerNamazu(const PlayerInfo&); };
}}

#endif