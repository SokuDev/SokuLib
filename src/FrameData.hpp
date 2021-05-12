//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_FRAMEDATA_HPP
#define SOKULIB_FRAMEDATA_HPP

#include "Boxes.hpp"

namespace SokuLib
{
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
}

#endif //SOKULIB_FRAMEDATA_HPP
