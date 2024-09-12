//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_INPUTMANAGER_HPP
#define SOKULIB_INPUTMANAGER_HPP


namespace SokuLib
{
	struct KeyBindings {
		// index is -1 when using keyboard, 0 when using first gamepad, 1 when using second gamepad.
		int index;
		// for keyboard, these are DirectX key codes (see dinput.h)
		// for controller, these are DIJOYPOD::rgbButton indices; for the directions they're -1.
		int up;
		int down;
		int left;
		int right;
		int a;
		int b;
		int c;
		int d;
		int changeCard;
		int spellcard;
		int pause;
		int select;
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
		int pause;
		int select;
	};
	struct KeyInputLight {
		int horizontalAxis;
		int verticalAxis;
		int a;
		int b;
		int c;
		int d;
		int changeCard;
		int spellcard;
	};

	struct CharacterSelectKeys {
		bool up: 1;
		bool down: 1;
		bool left: 1;
		bool right: 1;
		bool Z: 1;
		bool X: 1;
		bool C: 1;
		bool A: 1;
		bool dash: 1;
		bool Q: 1;
		unsigned char padding: 6;
	};

	struct BattleKeys {
		bool up: 1;
		bool down: 1;
		bool left: 1;
		bool right: 1;
		bool A: 1;
		bool B: 1;
		bool C: 1;
		bool dash: 1;
		bool AandB: 1;
		bool BandC: 1;
		bool pause: 1;
		bool select: 1;
		unsigned char padding: 4;
	};

	union Inputs {
		CharacterSelectKeys charSelect;
		BattleKeys battle;
		unsigned short raw;
	};

	//KEYMAPMGR
	//CInputManagerCluster
	struct KeymapManager {
		void *vtable;
		KeyBindings bindings;
		//  ADDR_KEYMAPOFS          int[8] (32) 0x38
		KeyInput input;

		// copies to/from during replays and netplay:
		Inputs inKeys;
		Inputs outKeys;
		bool readInKeys;
	};

	//KEYMGR
	struct KeyManager {
		//  ADDR_KEYMAPMGR          KeymapManager & (4) 0x00
		KeymapManager *keymapManager;
	};


	//TODO: Find which of the real struct thoses are
	struct InputManager {
		bool readReplay(const char *path);
	};

	extern InputManager &inputMgr;
	extern KeymapManager &inputMgrs;
}


#endif //SOKULIB_INPUTMANAGER_HPP
