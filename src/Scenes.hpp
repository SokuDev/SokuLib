//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_SCENES_HPP
#define SOKULIB_SCENES_HPP


#include <Windows.h>
#include <vector>
#include <string>
#include "Design.hpp"
#include "CharacterManager.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	#pragma pack(push, 1)
	enum Scene {
		SCENE_LOGO,
		SCENE_OPENING,
		SCENE_TITLE,
		SCENE_SELECT,
		SCENE_BATTLE = 5,
		SCENE_LOADING,
		SCENE_SELECTSV = 8,
		SCENE_SELECTCL,
		SCENE_LOADINGSV,
		SCENE_LOADINGCL,
		SCENE_LOADINGWATCH,
		SCENE_BATTLESV,
		SCENE_BATTLECL,
		SCENE_BATTLEWATCH,
		SCENE_SELECTSCENARIO,
		SCENE_ENDING = 20,
		SCENE_MAX,
	};
	#pragma pack(pop)

	struct SceneBase {
		void *VTable;

		template<typename T>
		T &to()
		{
			return *reinterpret_cast<T *>(this);
		}
	};

	struct Logo {
		SceneBase base;
	};

	struct Opening {
		SceneBase base;
	};

	struct InputHandler {
		int maxValue;
		int offset_0x04;
		KeyInput *keys;
		int pos;
		int posCopy;
	};

	struct Title {
		SceneBase base;

		// 0x004
		void *fadePtr;

		// 0x008
		char offset_0x008[0xA4];

		// 0x0AC
		Sprite backgroundSprites[5];

		// 0x390
		char offset_0x390[4];

		// 0x394
		Sprite spriteObj6;

		// 0x428
		char offset_0x428[0x9C];

		// 0x4C4
		CTile menuItemTiles;

		// 0x568
		CTile menuSelectedItemTiles;

		// 0x60C
		float menuItemSpacing;

		// 0x610
		InputHandler menuInputHandler;

		// 0x624
		char offset_0x624[0x34];

		// 0x658
		CDesign *logoSprite;

		// 0x65C
		CDesign *copyrightSprite;

		// 0x660
		CDesign *menuBGSprite;

		// 0x664
		char offset_0x664[0x24];

		// 0x688
		int menuState;

		// 0x68C
		char offset_0x68C[0x8];
	};

	struct ObjectSelect {
		// 0x00 Always 5
		int alwaysFive;
		// 0x04 Always 0
		int alwaysZero;
		// 0x08 KeyInput
		KeyInput *keys;
		// 0x0C Deck index
		int deck;
		// 0x10 Deck index duplicate (unused by the game)
		int deckUnused;
		// 0x14 Always 8
		int alwaysEight;
		// 0x18 Always 0
		int alwaysZero2;
		int dunno;
		// 0x20 Selected palette
		// Warning: This is only used when changing palette.
		// The effective palette is the CharacterInfo.
		int palette;
		// 0x24 Selected palette (Unused by the game)
		int paletteUnused;
	};

	struct SelectCursor {
		int alwaysZero;
		int alwaysTwenty;
		KeyInput *keys;
		int cursorPos;
		int cursorPosUnused;
	};

	struct Select {
		SceneBase base;

		char offset_0x004[0xC];

		//0x10 Left Keys
		KeyManager *leftKeys;
		//0x14 Right Keys
		KeyManager *rightKeys;

		char offset_0x018[0x110];

		// 0x128 ??? (Value seems to always be 0)
		// 0x12C ??? (Value seems to always be 0x14 hex, 20 dec)
		// 0x130 Left keys duplicate
		// 0x134 Left cursor pos
		// 0x138 Left cursor pos duplicate (the game sets it but doesn't use it)
		SelectCursor leftCursor;
		// 0x13C ??? (Value seems to always be 0)
		// 0x140 ??? (Value seems to always be 0x14 hex, 20 dec)
		// 0x144 Right keys duplicate
		// 0x148 Right cursor pos
		// 0x14C Right cursor pos duplicate (the game sets it but doesn't use it)
		SelectCursor rightCursor;

		// 0x150 Left ObjectSelect
		ObjectSelect leftSelect;
		// 0x178 Right ObjectSelect
		ObjectSelect rightSelect;

		char offset_0x1A0[0x2120];

		// 0x22C0 Left selection stage
		char leftSelectionStage;
		// 0x22C1 Right selection stage
		char rightSelectionStage;
		// 0x22C2 Left selected deck from random screen
		bool leftRandomDeck;
		// 0x22C3 Right selected deck from random screen
		bool rightRandomDeck;

		char offset_0x23C4[0x174];

		// 0x2438 Selected stage index
		unsigned int selectedStage;
		// 0x243C Selected stage index (Unused by the game)
		unsigned int selectedStageUnused;

		char offset_0x2440[0xC];

		// 0x244C Selected music index
		unsigned int selectedMusic;
	};

	struct Battle {
		SceneBase base;
	};

	struct Loading {
		SceneBase base;
	};

	struct SelectServer {
		Select base;
	};

	struct SelectClient {
		Select base;
	};

	struct LoadingServer {
		Loading base;
	};

	struct LoadingClient {
		Loading base;
	};

	struct LoadingWatch {
		Loading base;
	};

	struct BattleServer {
		Battle base;
	};

	struct BattleClient {
		Battle base;
	};

	struct BattleWatch {
		Battle base;
	};

	struct SelectScenario {
		SceneBase base;
	};

	struct Ending {
		SceneBase base;
	};

	// �V�[��ID
	// DWORD
	extern Scene &newSceneId;
	extern Scene &sceneId;
	extern HANDLE &LGThread;
	extern SceneBase *&currentScene;

	void changeScene(Scene newScene);
	void waitForSceneChange();

	extern std::vector<std::string> sceneNames;
}

#endif //SOKULIB_SCENES_HPP
