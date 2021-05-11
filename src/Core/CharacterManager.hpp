//
// Created by PinkySmile on 14/02/2021.
//

#ifndef SOKULIB_CHARACTERMANAGER_HPP
#define SOKULIB_CHARACTERMANAGER_HPP


#include "Cards.hpp"
#include "LinkedList.hpp"

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
		/*   0 */ ACTION_IDLE,
		/*   1 */ ACTION_CROUCHING,
		/*   2 */ ACTION_CROUCHED,
		/*   3 */ ACTION_STANDING_UP,
		/*   4 */ ACTION_WALK_FORWARD,
		/*   5 */ ACTION_WALK_BACKWARD,
		/*   6 */ ACTION_NEUTRAL_JUMP,
		/*   7 */ ACTION_FORWARD_JUMP,
		/*   8 */ ACTION_BACKWARD_JUMP,
		/*   9 */ ACTION_FALLING,
		/*  10 */ ACTION_LANDING,
		/*  50 */ ACTION_STAND_GROUND_HIT_SMALL_HITSTUN = 50,
		/*  51 */ ACTION_STAND_GROUND_HIT_MEDIUM_HITSTUN,
		/*  52 */ ACTION_STAND_GROUND_HIT_BIG_HITSTUN,
		/*  53 */ ACTION_STAND_GROUND_HIT_HUGE_HITSTUN,
		/*  56 */ ACTION_STAND_GROUND_HIT_SMALL_HITSTUN_2 = 56,
		/*  57 */ ACTION_STAND_GROUND_HIT_MEDIUM_HITSTUN_2,
		/*  58 */ ACTION_STAND_GROUND_HIT_BIG_HITSTUN_2,
		/*  62 */ ACTION_CROUCH_GROUND_HIT_SMALL_HITSTUN = 62,
		/*  63 */ ACTION_CROUCH_GROUND_HIT_MEDIUM_HITSTUN,
		/*  64 */ ACTION_CROUCH_GROUND_HIT_BIG_HITSTUN,
		/*  70 */ ACTION_AIR_HIT_SMALL_HITSTUN = 70,
		/*  71 */ ACTION_AIR_HIT_MEDIUM_HITSTUN,
		/*  72 */ ACTION_AIR_HIT_BIG_HITSTUN,
		/*  73 */ ACTION_AIR_HIT_DIRECT_KNOCKDOWN,
		/*  74 */ ACTION_AIR_HIT_CAN_WALL_SLAM,
		/*  75 */ ACTION_AIR_HIT_BIG_HITSTUN4,
		/*  76 */ ACTION_AIR_HIT_WALL_SLAMMED,
		/*  77 */ ACTION_AIR_HIT_HUGE_HITSTUN,
		/*  78 */ ACTION_AIR_HIT_WALL_SLAMMED2,
		/*  88 */ ACTION_AIR_HIT_WILL_GROUND_SLAM = 88,
		/*  89 */ ACTION_AIR_HIT_GROUND_SLAMMED,
		/*  97 */ ACTION_KNOCKED_DOWN = 97,
		/*  98 */ ACTION_KNOCKED_DOWN_STATIC, //At this point, the character is not bouncing or moving anymore

		/* 100 */ ACTION_GRABBED = 100,
		/* 143 */ ACTION_GROUND_CRUSHED = 143,
		/* 145 */ ACTION_AIR_CRUSHED = 145,
		/* 150 */ ACTION_RIGHTBLOCK_HIGH_SMALL_BLOCKSTUN = 150,
		/* 151 */ ACTION_RIGHTBLOCK_HIGH_MEDIUM_BLOCKSTUN,
		/* 152 */ ACTION_RIGHTBLOCK_HIGH_BIG_BLOCKSTUN,
		/* 153 */ ACTION_RIGHTBLOCK_HIGH_HUGE_BLOCKSTUN,
		/* 154 */ ACTION_RIGHTBLOCK_LOW_SMALL_BLOCKSTUN,
		/* 155 */ ACTION_RIGHTBLOCK_LOW_MEDIUM_BLOCKSTUN,
		/* 156 */ ACTION_RIGHTBLOCK_LOW_BIG_BLOCKSTUN,
		/* 157 */ ACTION_RIGHTBLOCK_LOW_HUGE_BLOCKSTUN,
		/* 158 */ ACTION_AIR_GUARD,
		/* 159 */ ACTION_WRONGBLOCK_HIGH_SMALL_BLOCKSTUN,
		/* 160 */ ACTION_WRONGBLOCK_HIGH_MEDIUM_BLOCKSTUN,
		/* 161 */ ACTION_WRONGBLOCK_HIGH_BIG_BLOCKSTUN,
		/* 162 */ ACTION_WRONGBLOCK_HIGH_HUGE_BLOCKSTUN,
		/* 163 */ ACTION_WRONGBLOCK_LOW_SMALL_BLOCKSTUN,
		/* 164 */ ACTION_WRONGBLOCK_LOW_MEDIUM_BLOCKSTUN,
		/* 165 */ ACTION_WRONGBLOCK_LOW_BIG_BLOCKSTUN,
		/* 166 */ ACTION_WRONGBLOCK_LOW_HUGE_BLOCKSTUN,
		/* 180 */ ACTION_FORWARD_AIRTECH = 180,
		/* 181 */ ACTION_BACKWARD_AIRTECH,
		/* 197 */ ACTION_FORWARD_TECH = 197,
		/* 198 */ ACTION_BACKWARD_TECH,
		/* 199 */ ACTION_NEUTRAL_TECH,

		/* 200 */ ACTION_FORWARD_DASH,
		/* 201 */ ACTION_BACKDASH,
		/* 202 */ ACTION_FORWARD_AIRDASH,
		/* 203 */ ACTION_BACKWARD_AIRDASH,
		/* 204 */ ACTION_GROUNDDASH_RECOVERY,
		/* 206 */ ACTION_LILIPAD_FORWARD_DASH = 206,
		/* 207 */ ACTION_LILIPAD_BACKDASH,
		/* 208 */ ACTION_NEUTRAL_HIGH_JUMP,
		/* 209 */ ACTION_FORWARD_HIGH_JUMP,
		/* 210 */ ACTION_BACKWARD_HIGH_JUMP,
		/* 214 */ ACTION_FLY = 214,
		/* 218 */ ACTION_SUWAKO_j2D = 218,
		/* 219 */ ACTION_SUWAKO_j1D_j3D,
		/* 220 */ ACTION_BE2,
		/* 222 */ ACTION_BE1 = 222,
		/* 223 */ ACTION_BE6,
		/* 224 */ ACTION_BE4,
		/* 225 */ ACTION_jBE4,
		/* 226 */ ACTION_jBE6,

		/* 300 */ ACTION_5A = 300,
		/* 301 */ ACTION_f5A,
		/* 302 */ ACTION_6A,
		/* 303 */ ACTION_2A,
		/* 304 */ ACTION_3A,
		/* 305 */ ACTION_66A,
		/* 306 */ ACTION_j5A,
		/* 307 */ ACTION_j6A,
		/* 308 */ ACTION_j2A,
		/* 309 */ ACTION_j8A,
		/* 311 */ ACTION_f2A = 311,
		/* 320 */ ACTION_5AA = 320,
		/* 321 */ ACTION_5AAA,
		/* 322 */ ACTION_5AAAA,
		/* 323 */ ACTION_5AAAAA,
		/* 324 */ ACTION_5AAA3A,
		/* 325 */ ACTION_j5AA,
		/* 330 */ ACTION_4A = 330,
		/* 331 */ ACTION_SUWAKO_3A,
		/* 332 */ ACTION_SUWAKO_LILIPAD_6A,

		/* 400 */ ACTION_5B = 400,
		/* 401 */ ACTION_6B,
		/* 402 */ ACTION_2B,
		/* 403 */ ACTION_3B,
		/* 404 */ ACTION_j5B,
		/* 405 */ ACTION_j6B,
		/* 406 */ ACTION_j2B,
		/* 407 */ ACTION_4B,
		/* 408 */ ACTION_66B,
		/* 409 */ ACTION_j4B,
		/* 410 */ ACTION_5C,
		/* 411 */ ACTION_6C,
		/* 412 */ ACTION_2C,
		/* 414 */ ACTION_j5C = 414,
		/* 415 */ ACTION_j6C,
		/* 416 */ ACTION_j2C,
		/* 417 */ ACTION_j1C,
		/* 418 */ ACTION_66C,
		/* 420 */ ACTION_ORRERIES_B = 420,
		/* 422 */ ACTION_AIR_ORRERIES_B = 422,
		/* 430 */ ACTION_ORRERIES_C = 430,
		/* 432 */ ACTION_AIR_ORRERIES_C = 432,

		/* 500 */ ACTION_DEFAULT_SKILL1_B = 500,
		/* 501 */ ACTION_DEFAULT_SKILL1_C,
		/* 502 */ ACTION_DEFAULT_SKILL1_AIR_B,
		/* 503 */ ACTION_DEFAULT_SKILL1_AIR_C,
		/* 505 */ ACTION_ALT1_SKILL1_B = 505,
		/* 506 */ ACTION_ALT1_SKILL1_C,
		/* 507 */ ACTION_ALT1_SKILL1_AIR_B,
		/* 508 */ ACTION_ALT1_SKILL1_AIR_C,
		/* 510 */ ACTION_ALT2_SKILL1_B = 510,
		/* 511 */ ACTION_ALT2_SKILL1_C,
		/* 512 */ ACTION_ALT2_SKILL1_AIR_B,
		/* 513 */ ACTION_ALT2_SKILL1_AIR_C,
		/* 520 */ ACTION_DEFAULT_SKILL2_B = 520,
		/* 521 */ ACTION_DEFAULT_SKILL2_C,
		/* 522 */ ACTION_DEFAULT_SKILL2_AIR_B,
		/* 523 */ ACTION_DEFAULT_SKILL2_AIR_C,
		/* 525 */ ACTION_ALT1_SKILL2_B = 525,
		/* 526 */ ACTION_ALT1_SKILL2_C,
		/* 527 */ ACTION_ALT1_SKILL2_AIR_B,
		/* 528 */ ACTION_ALT1_SKILL2_AIR_C,
		/* 530 */ ACTION_ALT2_SKILL2_B = 530,
		/* 531 */ ACTION_ALT2_SKILL2_C,
		/* 532 */ ACTION_ALT2_SKILL2_AIR_B,
		/* 533 */ ACTION_ALT2_SKILL2_AIR_C,
		/* 540 */ ACTION_DEFAULT_SKILL3_B = 540,
		/* 541 */ ACTION_DEFAULT_SKILL3_C,
		/* 542 */ ACTION_DEFAULT_SKILL3_AIR_B,
		/* 543 */ ACTION_DEFAULT_SKILL3_AIR_C,
		/* 545 */ ACTION_ALT1_SKILL3_B = 545,
		/* 546 */ ACTION_ALT1_SKILL3_C,
		/* 547 */ ACTION_ALT1_SKILL3_AIR_B,
		/* 548 */ ACTION_ALT1_SKILL3_AIR_C,
		/* 550 */ ACTION_ALT2_SKILL3_B = 550,
		/* 551 */ ACTION_ALT2_SKILL3_C,
		/* 552 */ ACTION_ALT2_SKILL3_AIR_B,
		/* 553 */ ACTION_ALT2_SKILL3_AIR_C,
		/* 560 */ ACTION_DEFAULT_SKILL4_B = 560,
		/* 561 */ ACTION_DEFAULT_SKILL4_C,
		/* 562 */ ACTION_DEFAULT_SKILL4_AIR_B,
		/* 563 */ ACTION_DEFAULT_SKILL4_AIR_C,
		/* 565 */ ACTION_ALT1_SKILL4_B = 565,
		/* 566 */ ACTION_ALT1_SKILL4_C,
		/* 567 */ ACTION_ALT1_SKILL4_AIR_B,
		/* 568 */ ACTION_ALT1_SKILL4_AIR_C,
		/* 570 */ ACTION_ALT2_SKILL4_B = 570,
		/* 571 */ ACTION_ALT2_SKILL4_C,
		/* 572 */ ACTION_ALT2_SKILL4_AIR_B,
		/* 573 */ ACTION_ALT2_SKILL4_AIR_C,
		/* 580 */ ACTION_DEFAULT_SKILL5_B = 580,
		/* 581 */ ACTION_DEFAULT_SKILL5_C,
		/* 582 */ ACTION_DEFAULT_SKILL5_AIR_B,
		/* 583 */ ACTION_DEFAULT_SKILL5_AIR_C,
		/* 585 */ ACTION_ALT1_SKILL5_B = 585,
		/* 586 */ ACTION_ALT1_SKILL5_C,
		/* 587 */ ACTION_ALT1_SKILL5_AIR_B,
		/* 588 */ ACTION_ALT1_SKILL5_AIR_C,
		/* 590 */ ACTION_ALT2_SKILL5_B = 590,
		/* 591 */ ACTION_ALT2_SKILL5_C,
		/* 592 */ ACTION_ALT2_SKILL5_AIR_B,
		/* 593 */ ACTION_ALT2_SKILL5_AIR_C,

		/* 600 */ ACTION_USING_SC_ID_200 = 600,
		/* 601 */ ACTION_USING_SC_ID_201,
		/* 602 */ ACTION_USING_SC_ID_202,
		/* 603 */ ACTION_USING_SC_ID_203,
		/* 604 */ ACTION_USING_SC_ID_204,
		/* 605 */ ACTION_USING_SC_ID_205,
		/* 606 */ ACTION_USING_SC_ID_206,
		/* 607 */ ACTION_USING_SC_ID_207,
		/* 608 */ ACTION_USING_SC_ID_208,
		/* 609 */ ACTION_USING_SC_ID_209,
		/* 610 */ ACTION_USING_SC_ID_210,
		/* 611 */ ACTION_USING_SC_ID_211,
		/* 612 */ ACTION_USING_SC_ID_212,
		/* 613 */ ACTION_USING_SC_ID_213,
		/* 614 */ ACTION_USING_SC_ID_214,
		/* 615 */ ACTION_USING_SC_ID_215,
		/* 616 */ ACTION_USING_SC_ID_216,
		/* 617 */ ACTION_USING_SC_ID_217,
		/* 618 */ ACTION_USING_SC_ID_218,
		/* 619 */ ACTION_USING_SC_ID_219,

		/* 650 */ ACTION_SC_ID_200_ALT_EFFECT = 650,
		/* 651 */ ACTION_SC_ID_201_ALT_EFFECT,
		/* 652 */ ACTION_SC_ID_202_ALT_EFFECT,
		/* 653 */ ACTION_SC_ID_203_ALT_EFFECT,
		/* 654 */ ACTION_SC_ID_204_ALT_EFFECT,
		/* 655 */ ACTION_SC_ID_205_ALT_EFFECT,
		/* 656 */ ACTION_SC_ID_206_ALT_EFFECT,
		/* 657 */ ACTION_SC_ID_207_ALT_EFFECT,
		/* 658 */ ACTION_SC_ID_208_ALT_EFFECT,
		/* 659 */ ACTION_SC_ID_209_ALT_EFFECT,
		/* 660 */ ACTION_SC_ID_210_ALT_EFFECT,
		/* 661 */ ACTION_SC_ID_211_ALT_EFFECT,
		/* 662 */ ACTION_SC_ID_212_ALT_EFFECT,
		/* 663 */ ACTION_SC_ID_213_ALT_EFFECT,
		/* 664 */ ACTION_SC_ID_214_ALT_EFFECT,
		/* 665 */ ACTION_SC_ID_215_ALT_EFFECT,
		/* 666 */ ACTION_SC_ID_216_ALT_EFFECT,
		/* 667 */ ACTION_SC_ID_217_ALT_EFFECT,
		/* 668 */ ACTION_SC_ID_218_ALT_EFFECT,
		/* 669 */ ACTION_SC_ID_219_ALT_EFFECT,
		/* 669 */ ACTION_FANTASY_HEAVEN_ACTIVATE = ACTION_SC_ID_219_ALT_EFFECT,

		/* 690 */ ACTION_SKILL_CARD = 690,
		/* 691 */ ACTION_SYSTEM_CARD,
		/* 692 */ ACTION_IBUKI_GOURD,
		/* 693 */ ACTION_RECOVERY_CHARM,
		/* 694 */ ACTION_MAGIC_POTION,
		/* 695 */ ACTION_TALISMAN,
		/* 695 */ ACTION_BOMB = ACTION_TALISMAN,
		/* 696 */ ACTION_HANGEKI,
		/* 696 */ ACTION_DIVINE_RAIMENT_OF_THE_DRAGON_FISH = ACTION_HANGEKI,
		/* 697 */ ACTION_LEFT_HANDED_FOLDING_FAN,
		/* 698 */ ACTION_SPELL_BREAKING_DRUG,
	};

	struct Box {
		int left;
		int top;
		int right;
		int bottom;
	};

	struct RotationBox {
		VectorI pt1;
		VectorI pt2;
	};

	//IMAGESTRUCT
	struct Image {
		// 0x00
		char offset_0x000[0x0A];
		//  ADDR_IMAGENUMBEROFS     unsigned int (4) 0x0A
		unsigned int number;
	};

	struct KeyInput {
		int horizontalAxis;
		int verticalAxis;
		int a;
		int b;
		int c;
		int d;
		int changeCard;
		int spellcard;
	};

	//KEYMAPMGR
	//CInputManagerCluster
	struct KeymapManager {
		char unknown[0x4];
		char isPlayer;
		char unknown2[0x33];
		//  ADDR_KEYMAPOFS          int[8] (32) 0x38
		KeyInput input;
	};

	//KEYMGR
	struct KeyManager {
		//  ADDR_KEYMAPMGR          KeymapManager & (4) 0x00
		KeymapManager *keymapManager;
	};

	struct Combo {
		float rate;
		unsigned short nbHits;
		unsigned short damages;
		unsigned short limit;
	};

	union AttackFlags {
		struct {
			/* 00 00 00 01 */ bool unk1: 1;
			/* 00 00 00 02 */ bool midHit: 1;
			/* 00 00 00 04 */ bool lowHit: 1;
			/* 00 00 00 08 */ bool airBlockable: 1;
			/* 00 00 00 10 */ bool unblockable: 1;
			/* 00 00 00 20 */ bool unk20: 1;
			/* 00 00 00 40 */ bool unk40: 1;
			/* 00 00 00 80 */ bool grab: 1;
			/* 00 00 01 00 */ bool unk100: 1;
			/* 00 00 02 00 */ bool unk200: 1;
			/* 00 00 04 00 */ bool crashHit: 1;
			/* 00 00 08 00 */ bool unk800: 1;
			/* 00 00 10 00 */ bool unk1000: 1;
			/* 00 00 20 00 */ bool unk2000: 1;
			/* 00 00 40 00 */ bool unk4000: 1;
			/* 00 00 80 00 */ bool knockBack: 1;
			/* 00 01 00 00 */ bool unk10000: 1;
			/* 00 02 00 00 */ bool unk20000: 1;
			/* 00 04 00 00 */ bool unk40000: 1;
			/* 00 08 00 00 */ bool guardCrush: 1;
			/* 00 10 00 00 */ bool hitsAll: 1;
			/* 00 20 00 00 */ bool stagger: 1;
			/* 00 40 00 00 */ bool grazable: 1;
			/* 00 80 00 00 */ bool unk800000: 1;
			/* 01 00 00 00 */ bool unk1000000: 1;
		};
		unsigned int value;
	};

	union FrameFlags {
		struct {
			/* 00 00 00 01 */ bool stand: 1;
			/* 00 00 00 02 */ bool crouch: 1;
			/* 00 00 00 04 */ bool airborne: 1;
			/* 00 00 00 08 */ bool down: 1;
			/* 00 00 00 10 */ bool guardAvailable: 1;
			/* 00 00 00 20 */ bool cancellable: 1;
			/* 00 00 00 40 */ bool chOnHit: 1;
			/* 00 00 00 80 */ bool superArmor: 1;
			/* 00 00 01 00 */ bool extendedArmor: 1;
			/* 00 00 02 00 */ bool guardPoint: 1;
			/* 00 00 04 00 */ bool graze: 1;
			/* 00 00 08 00 */ bool guarding: 1;
			/* 00 00 10 00 */ bool grabInvincible: 1;
			/* 00 00 20 00 */ bool meleeInvincible: 1;
			/* 00 00 40 00 */ bool projectileInvincible: 1;
			/* 00 00 80 00 */ bool invAirborne: 1;
			/* 00 01 00 00 */ bool invMidBlow: 1;
			/* 00 02 00 00 */ bool invLowBlow: 1;
			/* 00 04 00 00 */ bool invShoot: 1;
			/* 00 08 00 00 */ bool reflectionProjectile: 1;
			/* 00 10 00 00 */ bool flipVelocity: 1;
			/* 00 20 00 00 */ bool highJumpCancellable: 1;
			/* 00 40 00 00 */ bool unk400000: 1;
			/* 00 80 00 00 */ bool unk800000: 1;
			/* 01 00 00 00 */ bool atkAsHit: 1;
		};
		unsigned int value;
	};

	struct FrameData {
		char offset_0x00[0x1C];
		// FF_DAMAGE 0x1C // short
		unsigned short damage;

		// 0x1E
		unsigned char offset_0x1E[4];

		// FF_SPIRIT_DAMAGE 0x22 // short
		unsigned short spiritDamage;

		// 0x24
		char offset_0x24[0x28];

		// FF_FFLAGS 0x4C // int, bitfield of frame flags
		FrameFlags frameFlags;

		// FF_AFLAGS 0x50 // int, bitfield of attack flags
		AttackFlags attackFlags;

		// FF_COLLISION_BOX 0x54 // *rect<int>
		Box *collisionBox;

		// why do hurt box and attack box have the same offsets? these could be wrong
		// FF_HURT_BOX_COUNT 0x5C // int
		// FF_HURT_BOXES 0x60 // rect<short>
		// FF_ATTACK_BOX_COUNT 0x5C // int
		// FF_ATTACK_BOXES 0x60 // rect<short>
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
		Vector scale;
		float zRotation;
	};

	struct ObjectManager {
		// 0x000
		char offset_0x000[0xEC];

		//  ADDR_POINTXOFS          float             (4) 0x0EC
		//  ADDR_POINTYOFS          float             (4) 0x0F0
		Vector position;

		//  ADDR_SPEEDXOFS          float             (4) 0x0F4
		//  ADDR_SPEEDYOFS          float             (4) 0x0F8
		Vector speed;

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

		// 0x128
		char offset_0x128[0x14];

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
		char offset_0x148[0x8];

		//  ADDR_IMAGESTRUCTOFS     ImageStruct &     (4) 0x150
		Image &image;

		// 0x154
		char offset_0x154[0x4];

		// 0x158
		FrameData &frameData;

		// 0x15C
		char offset_0x15C[0x8];

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
	};

	struct ObjListManager {
		char offset_0x00[0x58];
		//  ADDR_OBJPROJOFS = 0x58
		LinkedList<ObjectManager> list;
	};

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

	//CHARACTERMGR
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
		char offset_0x34F[0x14C];

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
		char offset_0x4BC[0x14];

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
		deckInfo deckInfos;

		// 0x5FC
		char offset_0x5FC[0xA8];

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
		char offset_0x774[0x80];

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
