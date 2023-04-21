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

	//KEYMAPMGR
	//CInputManagerCluster
	struct KeymapManager {
		char unknown[0x4];
		// isPlayer is -1 when using keyboard, 0 when using first gamepad, 1 when using second gamepad.
		char isPlayer;

		// for keyboard, these are DirectX key codes (see dinput.h)
		// for controller, these are DIJOYPOD::rgbButton indices; for the directions they're -1.
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

		char unknown2[0x4];
		//  ADDR_KEYMAPOFS          int[8] (32) 0x38
		KeyInput input;
		int pause;
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
