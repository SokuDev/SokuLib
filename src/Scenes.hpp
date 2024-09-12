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
#include "Character.hpp"

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

	class IScene {
	public:
		virtual ~IScene() = default;
		virtual int onProcess() = 0;
		virtual bool onRender() = 0;
		virtual void unknown0C() {}
		virtual void onEnter(int prevSceneId) {}
		virtual void onLeave(int nextSceneId) {}
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
		int *axis;
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

	struct SelectCursor {
		int alwaysZero;
		int alwaysTwenty;
		KeyInput *keys;
		int cursorPos;
		int cursorPosUnused;
	};

	struct Select {
		SceneBase base;

		void *fadePtr;
		int chrsSelected;
		PlayerInfo *pinfo;

		//0x10 Left Keys
		KeymapManager *leftKeys;
		//0x14 Right Keys
		KeymapManager *rightKeys;

		char offset_0x018[0x110];

		// 0x128
		InputHandler leftCharInput;
		InputHandler rightCharInput;
		InputHandler leftDeckInput;
		InputHandler leftPalInput;
		InputHandler rightDeckInput;
		InputHandler rightPalInput;
		SokuLib::CDesign designBase3;
		char offset_0x1D4[0x2C4];

		// 0x498
		SokuLib::Sprite charNameSprites[21];

		// 0x10BC
		char offset_0x10BC[0xD8C];

		// 0x1E48
		float charPortraitSliceWidth;
		float charPortraitStartX;

		char offset_0x1E50[0x280];

		Sprite *p1ProfileTextSprite;
		Sprite *p2ProfileTextSprite;

		char offset_0x20D8[0x1E8];

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

		// 0x50C0 Total size
		char offset_0x2450[0x2C70];
	};
	static_assert(offsetof(Select, offset_0x1D4) == 0x1D4);
	static_assert(offsetof(Select, offset_0x2450) == 0x2450);
	static_assert(sizeof(Select) == 0x50C0);

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
		bool characterSelectEnded;
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
