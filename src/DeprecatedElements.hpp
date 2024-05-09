//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_DEPRECATEDELEMENTS_HPP
#define SOKULIB_DEPRECATEDELEMENTS_HPP

#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __PRAGMA_LOC__ __FILE__ "("__STR1__(__LINE__)") "
#define PRAGMA_WARNING(x) __pragma(message(__PRAGMA_LOC__ ": warning: " #x))

#ifndef __SOKULIB_NO_DEPR_WARN
PRAGMA_WARNING(These will be removed in later versions. Use at your own risks !)
#endif

#include "SokuLib.hpp"

#define KeyCombination CommandCombination
#define SCENE_SELECTSENARIO SCENE_SELECTSCENARIO
#define mVC9Dequeue Dequeue
#define deckInfos deckInfo

namespace SokuLib
{
	[[deprecated("Replaced by Sprite")]]
	typedef Sprite CSprite;

	[[deprecated("Replaced with DeckInfo")]]
	typedef DeckInfo deckInfo;
	enum [[deprecated("Replaced with struct Scene_VTABLE")]] VTableScenesOffsets {
		OFFSET_ON_PROCESS = 0x4,
		OFFSET_ON_RENDER  = 0x8,
	};

	enum [[deprecated("Replaced with struct BattleManager_VTABLE")]] VTableBattleManagerOffsets {
		BATTLE_MGR_OFFSET_ON_DESTRUCT              = 0x00, // Destructor
		BATTLE_MGR_OFFSET_ON_ARENA_START           = 0x04, // After select arena start, best place for initializing girls
		// void *(void *, int, int)
		BATTLE_MGR_OFFSET_ON_EXIT                  = 0x08, // After exit on selection screen menu
		BATTLE_MGR_OFFSET_ON_PROCESS               = 0x0C, // Progress??
		BATTLE_MGR_OFFSET_ON_SAY_START             = 0x10, // Announcement say start round
		BATTLE_MGR_OFFSET_AFTER_BLACK_SCREEN       = 0x14, // After load black screen
		BATTLE_MGR_OFFSET_MAYBE_ON_PROGRESS        = 0x18, // Progress???
		BATTLE_MGR_OFFSET_ON_ROUND_END             = 0x1C, // After round
		BATTLE_MGR_OFFSET_ON_KO                    = 0x20, // After battle (KO)
		BATTLE_MGR_OFFSET_ON_GIRL_TALK             = 0x24, // After girls talk
		BATTLE_MGR_OFFSET_UNKNOWN                  = 0x28, // ??????????
		BATTLE_MGR_OFFSET_ON_LAST_ROUND_HIT        = 0x2C, // Before last hit in round
		BATTLE_MGR_OFFSET_ON_ROUND_START           = 0x30, // After stat round and before end pure battle()
		BATTLE_MGR_OFFSET_ON_SHOW_LOGO             = 0x34, // at the start before "start round" logo int is 1
		// becomes 2 after logo
		// becomes 3 the end of round
		// becomes 5 after final round before logo
		// becomes 6 after final
		// becomes 7 after girls talk
		// void *(void *, int, int)
		BATTLE_MGR_OFFSET_ON_RENDER                = 0x38, // After select arena render or draw()
		BATTLE_MGR_OFFSET_MAYBE_ON_RENDER          = 0x3C, // After select arena render????
		BATTLE_MGR_OFFSET_MAYBE_ON_RENDER2         = 0x40, // After select arena render???? Last function???
	};

	// ���z�֐��e�[�u��
	enum [[deprecated("Replaced with globals")]] VTable {
		vtbl_CSelect              = ADDR_VTBL_SELECT,
		vtbl_CLogo                = ADDR_VTBL_LOGO,
		vtbl_CTitle               = ADDR_VTBL_TITLE,
		vtbl_CBattle              = ADDR_VTBL_BATTLE,
		vtbl_CBattleCL            = ADDR_VTBL_BATTLE_CL,
		vtbl_CBattleSV            = ADDR_VTBL_BATTLE_SV,
		vtbl_CBattleWatch         = ADDR_VTBL_BATTLE_WATCH,
		vtbl_CSelectSV            = ADDR_VTBL_SELECT_SV,
		vtbl_CSelectCL            = ADDR_VTBL_SELECT_CL,
		vtbl_CLoading             = ADDR_VTBL_LOADING,
		vtbl_CLoadingSV           = ADDR_VTBL_LOADINGSV,
		vtbl_CLoadingCL           = ADDR_VTBL_LOADINGCL,
		vtbl_CLoadingWatch        = ADDR_VTBL_LOADING_WATCH,
		vtbl_CBattleManager       = ADDR_VTBL_BATTLE_MANAGER,
	};

	[[deprecated("Replaced by profile1.name")]]
	extern String &player1Profile;
	[[deprecated("Replaced by profile2.name")]]
	extern String &player2Profile;
}

#endif //SOKULIB_DEPRECATEDELEMENTS_HPP
