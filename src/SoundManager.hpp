//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_SOUNDMANAGER_HPP
#define SOKULIB_SOUNDMANAGER_HPP


namespace SokuLib
{
	enum SystemSFX {
		SFX_SLAP_HIT = 1,            // 001 -> Reimu 4a hit
		SFX_PUNCH_HIT,               // 002 -> Reimu f5a hit
		SFX_MEDIUM_HIT,              // 003 -> Remi 6a hit
		SFX_BIG_HIT,                 // 004 -> Remi j6a hit
		SFX_BIG_PIERCE_HIT,          // 005 -> Remi j2a hit
		SFX_MEDIUM_PIERCE_HIT,       // 006 -> Remi 4a hit
		SFX_SMALL_PIERCE_HIT,        // 007 -> Remi fork hit
		SFX_CLAW_HIT,                // 008 -> Remi claw hit
		SFX_BIG_SPIRIT_HIT,          // 009 -> Reimu 5c hit
		SFX_ELECTRIC_HIT,            // 010 -> Exodia hit
		SFX_SMALL_SPIRIT_HIT,        // 011 -> Remi 5b hit
		SFX_SUWAKO_GRAB_SOUND,       // 012 -> Grabbing sound of Suwako 5SC unblockable
		SFX_RIGHT_BLOCK = 20,        // 020 -> Block
		SFX_WRONG_BLOCK,             // 021 -> Wrong block
		SFX_KNOCK_DOWN,              // 022 -> Knockdown
		SFX_SPELL_ACTIVATE,          // 023 -> Spell activate
		SFX_UNUSED1,                 // 024 -> ?????????? (Strange sound)
		SFX_COUNTER_HIT,             // 025 -> Counter hit
		SFX_WEATHER_CRYSTAL_COLLECT, // 026 -> Weather crystal collect
		SFX_LIGHT_ATTACK,            // 027 -> Short melee move sound
		SFX_MEDIUM_ATTACK,           // 028 -> Medium melee move sound
		SFX_HEAVY_ATTACK,            // 029 -> Long melee move sound
		SFX_LAND,                    // 030 -> Land
		SFX_DASH,                    // 031 -> Dash
		SFX_UNUSED2,                 // 032 -> ?????????? (Strange sound)
		SFX_UNUSED3,                 // 033 -> ?????????? (Strange sound)
		SFX_EARTH_SHAKE,             // 034 -> Earthquake sound something ?
		SFX_BORDER_ESCAPE,           // 035 -> Border Escape
		SFX_CARD_DRAWN,              // 036 -> New card drawn
		SFX_GRAZE,                   // 037 -> Bullet grazed
		SFX_ORB_BROKEN,              // 038 -> Orb broken
		SFX_MENU_MOVE,               // 039 -> Menu move
		SFX_MENU_CONFIRM,            // 040 -> Menu confirm
		SFX_MENU_CANCEL,             // 041 -> Menu cancel
		SFX_HIGH_JUMP,               // 043 -> High jump
		SFX_KNOCK_OUT,               // 044 -> Knock out
		SFX_CHARGE_ATTACK,           // 045 -> Charging
		SFX_WEATHER_CRYSTAL_COLLECT2,// 046 -> Weather crystal collect
		SFX_RECOVER_ORB,             // 047 -> Broken orb recover
		SFX_SWR_PAUSE,               // 048 -> TH11/12 pausing sound
		SFX_POP,                     // 049 -> Pop
		SFX_WEATHER_ACTIVATE = 53,   // 053 -> Weather activate
		SFX_USE_CARD,                // 054 -> Skill card use
		SFX_BOMB,                    // 055 -> Bomb use
		SFX_CARD_EFFECT,             // 056 -> Magic potion use
		SFX_NETBELL,                 // 057 -> Netbell
		SFX_CARD_DISCARDED,          // 058 -> Card discarded
		SFX_TITLESCREEN_MOVE,        // 059 -> Title screen move
		SFX_TITLESCREEN_CONFIRM = 61,// 061 -> Menu confirm
		SFX_CATFISH_FALL,            // 070 -> Catfish fall
		SFX_CATFISH_LAND,            // 071 -> Catfish land
		SFX_LHFF_CHARGE,             // 072 -> Left handed folding fan charge
		SFX_TIME_STOPPED,            // 073 -> Time stopped
		SFX_UNUSED4,                 // 074 -> bzzzzz
		SFX_QUIET_RAIN,              // 100 -> Quiet rain
		SFX_LOUD_RAIN,               // 101 -> Loud Rain
		SFX_WIND,                    // 102 -> Wind
		SFX_HEAVY_WIND,              // 103 -> More wind
		SFX_WIND2,                   // 104 -> Wind but different
		SFX_STORM,                   // 105 -> Storm
	};
	// SE�Đ�
	extern void (* const playSEWaveBuffer)(int id);
	extern void (* const playNetBell)(int id);

	static void playBGM(const char *path)
	{
		((void (*)(const char *))0x43ff10)(path);
	}
}



#endif //SOKULIB_SOUNDMANAGER_HPP
