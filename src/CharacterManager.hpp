//
// Created by PinkySmile on 14/02/2021.
//

#ifndef SOKULIB_CHARACTERMANAGER_HPP
#define SOKULIB_CHARACTERMANAGER_HPP


#include "Cards.hpp"
#include "LinkedList.hpp"
#include "Action.hpp"
#include "InputManager.hpp"
#include "FrameData.hpp"
#include "Boxes.hpp"
#include "KeyCombination.hpp"

#pragma pack(push,1)
namespace SokuLib
{
	enum Direction : char {
		LEFT = -1,
		RIGHT = 1
	};

	struct Skill {
		unsigned char level : 7;
		bool notUsed : 1;
	};

	struct Combo {
		float rate;
		unsigned short nbHits;
		unsigned short damages;
		unsigned short limit;
	};

	union Color {
		struct {
			unsigned char b;
			unsigned char g;
			unsigned char r;
			unsigned char a;
		};
		unsigned color;
	};

	struct RenderInfo {
		Color color;
		int shaderType;
		Color shaderColor;
		Vector2f scale;
		float xRotation;
		float yRotation;
		float zRotation;
	};

    //! @brief An Object is any entity that exists within a battle: characters, bullets, visual effects, etc.
    //! This struct is the base for such entities.
	struct ObjectManager {
		// 0x000
		void *vtable;

		// 0x004
		char offset_0x004[0xE8];

		//  ADDR_POINTXOFS          float             (4) 0x0EC
		//  ADDR_POINTYOFS          float             (4) 0x0F0
		Vector2f position;

		//  ADDR_SPEEDXOFS          float             (4) 0x0F4
		//  ADDR_SPEEDYOFS          float             (4) 0x0F8
		Vector2f speed;

		// 0x0FC
		char offset_0x0FC[0x4];

		// 0x100
		float gravity;

		//  ADDR_DIRECTIONOFS       enum Direction    (1) 0x104
		Direction direction;

		// 0x105
		char offset_0x105[0xB];

		// 0x110
		RenderInfo renderInfos;

		// 0x130
		char offset_0x130[0xC];

		//  ADDR_ACTIONIDOFS        enum Action       (2) 0x13C
		Action action;

		//  ADDR_ACTIONBLOCKIDOFS   unsigned short    (2) 0x13E
		unsigned short actionBlockId;

		//  unsigned short    (2) 0x140
		unsigned short animationCounter;

		//  unsigned short    (2) 0x142
		unsigned short animationSubFrame;

		//  ADDR_FRAMECOUNTOFS      unsigned int      (4) 0x144
		unsigned int frameCount;

		// 0x148
		unsigned short animationCounterMax;

		// 0x14A
		char offset_0x14A[0x2];

		// 0x14C
		unsigned short animationSubFrameMax;

		// 0x14E
		char offset_0x14E[0x2];

		//  ADDR_IMAGESTRUCTOFS     ImageStruct &     (4) 0x150
		FrameData *image;

		// 0x154
		char offset_0x154[0x4];

		// 0x158
		FrameData *frameData;

		// 0x15C
		FrameDataReader *frameDataReader;

		// 0x160
		void *offset_0x160;

		//  int *[256]         (4) 0x164
		void **soundTable;

		// 0x168
		char offset_0x168[0x1C];

		//  ADDR_HPOFS              short    (2) 0x184
		short hp;

		// 0x186
		char offset_0x186[0x2];

		// 0x188
		unsigned int superarmorDamageTaken;

		// 0x18C
		char offset_0x18C[0x8];

		//CF_HIT_COUNT 0x194 // char
		char hitCount;

		// 0x195
		char offset_0x195;

		//  ADDR_HITSTOPOFS         unsigned short    (2) 0x196
		unsigned short hitstop;

		// 0x198
		char offset_0x198[0x33];

		//  ADDR_ATTACKAREACOUNTOFS unsigned char     (1) 0x1CB
		unsigned char hitBoxCount;

		//  ADDR_HITAREACOUNTOFS    unsigned char     (1) 0x1CC
		unsigned char hurtBoxCount;

		// 0x1CD
		char offset_0x1CD[0x3];

		//  ADDR_HITAREA2OFS        Box[5]           (80) 0x1D0
		Box hurtBoxes[5];

		//  ADDR_ATTACKAREA2OFS     Box[5]           (80) 0x220
		Box hitBoxes[5];

		// 0x270
		char offset_0x270[0xB0];

		// CF_ATTACK_BOXES_ROT 0x320 // altbox[5]
		RotationBox *hitBoxesRotation[5];

		//  ADDR_HITAREAFLAGOFS     Box *[5]         (20) 0x334
		RotationBox *hurtBoxesRotation[5];

		void animate();
		void animate2();
		void doAnimation();
	};

    //! @brief Linked list of entities. An entity may hold such a list for projectiles and visual effects notably.
	struct ObjListManager {
		char offset_0x00[0x58];
		//  ADDR_OBJPROJOFS = 0x58
		LinkedList<ObjectManager> list;
	};

    //! @brief Object for projectiles.
	struct ProjectileManager {
		// 0x000
		ObjectManager objectBase;

		// 0x348
		char offset_0x348[0x2];

		// 0x34A
		unsigned char characterIndex;

		// 0x34B
		unsigned char offset_0x34B;

		// PF_IS_ACTIVE 0x34C // int
		int isActive;
	};

    //! @brief Object for characters.
	struct CharacterManager {
		// 0x000
		ObjectManager objectBase;

		// 0x348
		char offset_0x348[0x2];

		// 0x34A
		unsigned char characterIndex;

		// 0x34B
		unsigned char offset_0x34B[3];

		// 0x34E
		unsigned char playerIndex;

		// 0x34F
		char offset_0x34F;

		// 0x350
		bool isRightPlayer;

		// 0x351
		char offset_0x351[0x14A];

		//  ADDR_AIRDASHCOUNTOFS    unsigned char     (1) 0x49B
		unsigned char airdashCount;

		char offset_0x49C[2];

		//  ADDR_REIPOWEROFS        unsigned short    (2) 0x49E
		unsigned short currentSpirit;

		//  ADDR_MAXREIPOWEROFS     unsigned short    (2) 0x4A0
		unsigned short maxSpirit;

		//  ADDR_REISTOPROFS        unsigned short    (2) 0x4A2
		unsigned short spiritRegenDelay;

		// 0x4A4
		unsigned short timeWithBrokenOrb;

		// 0x4A6
		char offset_0x4A6[0x2];

		//  ADDR_TIMESTOPOFS        short             (2) 0x4A8
		unsigned short timeStop;

		// 0x4AA
		char offset_0x4AA[0x3];

		//  ADDR_CORRECTIONOFS      char              (1) 0x4AD
		char correction;

		// 0x4AE
		char offset_0x4AE[0x2];

		//  ADDR_COMBORATEOFS       float             (4) 0x4B0
		//  ADDR_COMBOCOUNTOFS      unsigned short    (2) 0x4B4
		//  ADDR_COMBODAMAGEOFS     unsigned short    (2) 0x4B6
		//  ADDR_COMBOLIMITOFS      unsigned short    (2) 0x4B8
		Combo combo;

		// 0x4BA
		unsigned short untech;

		// 0x4BC
		char offset_0x4BC[0x2];

		// 0x4BE
		unsigned short realLimit;

		// 0x4C0
		char offset_0x4C0[0x10];

		//  ADDR_SPEEDPOWEROFS      float             (4) 0x4D0
		float speedPower;

		// 0x4D4
		char offset_0x4D4[0x48];

		// 0x51C
		unsigned short meleeInvulTimer;

		// 0x51E
		unsigned short grabInvulTimer;

		// 0x520
		unsigned short projectileInvulTimer;

		// 0x522
		char offset_0x522[0x4];

		//  ADDR_HIHISOUOFS         unsigned short    (2) 0x526
		unsigned short swordOfRaptureDebuffTimeLeft;

		//  ADDR_LIFERECOVERYOFS    unsigned short    (2) 0x528
		unsigned short healingCharmTimeLeft;

		// 0x52A
		char offset_0x52A[0x6];

		//  ADDR_ATTACKPOWEROFS     float             (4) 0x530
		float attackPower;

		//  ADDR_DEFENSEPOWEROFS    float             (4) 0x534
		float defensePower;

		// 0x538
		float noSuperArmor;

		// 0x53C
		char offset_0x53C[0x24];

		// 0x560
		unsigned short grimoires;

		// 0x562
		char offset_0x562[0x11];

		// 0x573
		char score;

		// 0x574
		char offset_0x574[8];

		// 0x57C
		DeckInfo deckInfo;

		// 0x5C4
		char offset_0x5C4[0x20];

		// 0x5E4
		unsigned short cardGauge;

		// 0x5E6
		unsigned char cardCount;

		// 0x5E7
		unsigned char cardSlotCount;

		// 0x5E8 (40, 0x28)
		HandContainer hand;

		// 0x610
		char offset_0x610[0x94];

		// 0x6A4
		unsigned char skillLevels[16];

		// 0x6B4
		char offset_0x6B4[0x10];

		// 0x6C4
		Skill skillMap[16];

		// 0x6D4
		char offset_0x6D4[0x24];

		//  ADDR_OBJLISTMGR = 0x6F8
		ObjListManager &objects;

		// 0x6FC
		char offset_0x6FC[0x54];

		//  ADDR_KEYMGROFS          KeyManager &      (4) 0x750
		KeyManager *keyManager;

		// 0x754
		KeyInput keyMap;

		// 0x774
		char offset_0x774[0x54];

		// CF_PRESSED_COMBINATION 0x7C8 // KeyCombination
		KeyCombination keyCombination;

		// 0x7CC
		bool nameHidden;

		// 0x7CD
		char offset_0x7CD[0x27];

		// CF_CHARGE_ATTACK 0x7F4 // char
		char chargedAttack;

		// 0x7F5
		char offset_0x7F5[2];

		// CF_DAMAGE_LIMITED 0x7F7 // bool
		bool damageLimited;

		// 0x7F8
		char offset_0x7F8[0x3C];

		// 0x834
		unsigned short tenguFans;

		// 0x836
		char offset_0x836[0xA];

		// 0x840
		float sacrificialDolls;

		// 0x844
		float controlRod;

		// 0x848
		float magicPotionTimeLeft;

		// 0x84C
		char offset_0x84C[2];

		//  ADDR_RYUUSEIOFS         unsigned short    (2) 0x84E
		unsigned short dragonStarTimeLeft;

		// 0x850
		unsigned short drops;

		//  ADDR_DROPWATERTIMEOFS   unsigned short    (2) 0x852
		unsigned short dropInvulTimeLeft;

		// 0x854
		char offset_0x854[0x3C];

		union {
			//  ADDR_MILLENIUMOFS       unsigned short    (2) 0x890 (REMILIA Millenium Vampire time left (in frame) 600 - 0)
			unsigned short milleniumVampireTime;
			//  ADDR_PHILOSOPHEROFS     unsigned short    (2) 0x890 (PATCHOULI Philosopher's Stone time left (in frame) 1200 - 0)
			unsigned short philosophersStoneTime;
			//  ADDR_SAKUYAWORLDOFS     unsigned short    (2) 0x890 (SAKUYA Sakuya's World time left (in frame) 300 - 0)
			unsigned short sakuyasWorldTime;
		};

		union {
			//  ADDR_PRIVATESQOFS       unsigned short    (2) 0x892 (SAKUYA Private Square time left (in frame) 300 - 0)
			unsigned short privateSquare;
			//  ADDR_ORRERYOFS          unsigned short    (2) 0x892 (MARISA Orreries time left (in frames) 600 - 0)
			unsigned short orreriesTimeLeft;
			//  ADDR_MPPOFS             unsigned short    (2) 0x892 (SUIKA Missing Purple Power time left (in frames) 480 - 0)
			unsigned short missingPurplePowerTimeLeft;
			unsigned short aliceDollCount;
		};

		// 0x894
		char offset_0x894[0x4];

		//  ADDR_FIELDREDOFS        unsigned short    (2) 0x898 (REISEN d623 ?)
		unsigned short reisenD632;

		//  ADDR_FIELDPURPLEOFS     unsigned short    (2) 0x89A (REISEN a623 3 when the opponent is in the circle)
		unsigned short reisenA632;

		//  ADDR_KANAKOOFS          int               (4) 0x89C (SANAE Time left (in frame) before getting Kanako back)
		int kanakoTimeLeft;

		union {
			//  ADDR_SUWAKOOFS          int               (4) 0x8A0 (SANAE Time left (in frame) before getting Suwako back)
			int suwakoTimeLeft;

			//  ADDR_KOKUSHIOFS         unsigned int      (4) 0x8A0 (REISEN Number of Elixir used 0 - 3)
			unsigned short elixirUsed;

			//  ADDR_DIAHARDOFS         unsigned short    (2) 0x8A0 (PATCHOULI Time left (in frame) in the effect of Diamond Hard 720 - 0)
			unsigned short diamondHardEffectLeft;

			//  ADDR_RESBUTTEROFS       unsigned short    (2) 0x8A0 (YUYUKO Number of Resurrection Butterflies used 0 - 4)
			unsigned short resurrectionButterfliesUsed;
		};

		// 0x8A4
		char offset_0x8A4[0xE];

		//  ADDR_FIELDRED2OFS       unsigned short    (2) 0x8B2 (REISEN Infrared Moon time left (in frame) 420 - 0)
		unsigned short infraredMoonTimeLeft;

		//  ADDR_TENSEITIMEOFS      unsigned short    (2) 0x8B4 (REIMU Time left (in frame) before the end of Fantasy Heaven 900 - 0)
		unsigned short fantasyHeavenTimeLeft;

		//  ADDR_TENSEINUMOFS       unsigned short    (2) 0x8B6 (REIMU Number of stacks completed for Fantasy Heaven 0 - 7)
		unsigned short fantasyHeavenStacks;

		// 0x8B8
		char offset_0x8B8[0x1E];

		//  ADDR_TEKETENOFS         unsigned short    (2) 0x8D6 (YOUMU Time left (in frame) before the clone disappear 600 - 0)
		unsigned short youmuCloneTimeLeft;

		// 0x8D8
		char offset_0x8D8[0x4C];

		//  ADDR_MUNENOFS           unsigned short    (2) 0x924 (TENSHI State of Enlightenment time left (in frame) 900 - 0)
		unsigned short stateOfEnlightenmentTimeLeft;

		// 0x926
		char offset_0x926[0];

		bool generateCard(unsigned short id, Card &buffer);
		Card *addCard(unsigned short id);
		void playSE(int id);
	};
}
#pragma pack(pop)

#endif //SOKULIB_CHARACTERMANAGER_HPP
