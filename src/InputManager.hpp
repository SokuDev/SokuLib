//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_INPUTMANAGER_HPP
#define SOKULIB_INPUTMANAGER_HPP


namespace SokuLib
{
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

	//KEYMAPMGR
	//CInputManagerCluster
	struct KeymapManager {
		void *unknown;
		// isPlayer is -1 when using keyboard, 0 when using first gamepad, 1 when using second gamepad.
		char isPlayer;

		// for keyboard, these are DirectX key codes (see dinput.h / DIKEY.md)
		// for controller, these are DIJOYPAD::rgbButton indices (and -1 for up/down/left/right).
		int bindingUp;
		int bindingDown;
		int bindingLeft;
		int bindingRight;
		int bindingA;
		int bindingB;
		int bindingC;
		int bindingD;
		int bindingChangeCard;
		int bindingSpellCard;
		int bindingPause;
		int bindingSelect;
		
		//  ADDR_KEYMAPOFS          int[8] (32) 0x38
		KeyInput input;
		int pause;
		int select;
		
		// copies to/from during replays and netplay:
		BattleKeys inKeys;
		BattleKeys outKeys;
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
