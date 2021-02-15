//
// Created by PinkySmile on 14/02/2021.
//

#ifndef SWRSTOYS_CHARACTERMANAGER_HPP
#define SWRSTOYS_CHARACTERMANAGER_HPP


#include "Cards.hpp"

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

	enum Action : unsigned short {

	};

	struct Vector {
		float x;
		float y;
	};

	struct Box {
		int left;
		int top;
		int right;
		int bottom;
	};

	//IMAGESTRUCT
	struct Image {
		// 0x00
		char offset_0x000[0x0A];
		//  ADDR_IMAGENUMBEROFS     unsigned int (4) 0x0A
		unsigned int number;
		// 0x0E
		char offset_0x00E[0x36];
		//  ADDR_FRAMEFLAGSOFS      unsigned int (4) 0x4C
		unsigned int frameFlag;
		//  ADDR_ATTACKFLAGSOFS     unsigned int (4) 0x50
		unsigned int attackFlag;
	};

	//KEYMAPMGR
	struct KeymapManager {
		char unknown[0x38];
		//  ADDR_KEYMAPOFS          int[8] (32) 0x38
		int horizontalAxis;
		int verticalAxis;
		int a;
		int b;
		int c;
		int d;
		int changeCard;
		int spellcard;
	};

	//KEYMGR
	struct KeyMgr {
		//  ADDR_KEYMAPMGR          KeymapManager & (4) 0x00
		KeymapManager &keymapManager;
	};

	struct Combo {
		float rate;
		unsigned short nbHits;
		unsigned short damages;
		unsigned short limit;
	};

	//CHARACTERMGR
	struct CharacterManager {
		// 0x000
		char offset_0x000[0xEC];

		//  ADDR_POINTXOFS          float             (4) 0x0EC
		//  ADDR_POINTYOFS          float             (4) 0x0F0
		Vector position;

		//  ADDR_SPEEDXOFS          float             (4) 0x0F4
		//  ADDR_SPEEDYOFS          float             (4) 0x0F8
		Vector speed;

		// 0x0FC
		char offset_0x0FC[0x8];

		//  ADDR_DIRECTIONOFS       enum Direction    (1) 0x104
		Direction direction;

		// 0x105
		char offset_0x105[0x37];

		//  ADDR_ACTIONIDOFS        enum Action       (2) 0x13C
		Action action;

		//  ADDR_ACTIONBLOCKIDOFS   unsigned short    (2) 0x13E
		unsigned short actionBlockId;

		// 0x140
		char offset_0x140[0x4];

		//  ADDR_FRAMECOUNTOFS      unsigned int      (4) 0x144
		unsigned int frameCount;

		// 0x148
		char offset_0x148[0x8];

		//  ADDR_IMAGESTRUCTOFS     ImageStruct &     (4) 0x150
		Image &image;

		// 0x154
		char offset_0x154[0x30];

		//  ADDR_HPOFS              unsigned short    (2) 0x184
		unsigned short hp;

		// 0x186
		char offset_0x186[0x10];

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
		Box *hitBoxesRotation[5];

		//  ADDR_HITAREAFLAGOFS     Box *[5]         (20) 0x334
		Box *hurtBoxesRotation[5];

		// 0x348
		char offset_0x348[0x153];

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
		char offset_0x4A4[0x4];

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
		char offset_0x4BA[0x16];

		//  ADDR_SPEEDPOWEROFS      float             (4) 0x4D0
		float speedPower;

		// 0x4D4
		char offset_0x4D4[0x52];

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
		char offset_0x538[0x28];

		// 0x560
		unsigned short grimoires;

		// 0x562
		char offset_0x562[0x11];

		// 0x573
		char score;

		// 0x574
		char offset_0x574[8];

		// 0x57C
		deckInfo deckInfos;

		// 0x5FC
		char offset_0x5FC[0xC8];

		// 0x6C4
		Skill skillMap[16];

		// 0x6D4
		char offset_0x6D4[0x7C];

		//  ADDR_KEYMGROFS          KeyManager &      (4) 0x750
		KeymapManager &keymapManager;

		// 0x754
		char offset_0x754[0xE0];

		// 0x834
		unsigned short tenguFans;

		// 0x836
		char offset_0x836[0xA];

		// 0x840
		float sacrificialDolls;

		// 0x844
		float controlRod;

		// 0x848
		char offset_0x848[6];

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

			//  ADDR_DIAHARDOFS         unsigned short    (2) 0x8A0 (PATCHOULI Time left (in frame) in the effect of Diamond Hard 540 - 0)
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
	};
}
#pragma pack(pop)

#endif //SWRSTOYS_CHARACTERMANAGER_HPP
