//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_INPUTMANAGER_HPP
#define SOKULIB_INPUTMANAGER_HPP


namespace SokuLib
{
    //! @brief Contains the time for which all buttons were pressed. 0 means not pressed.
    //! horizontalAxis and verticalAxis can be negative to represent the opposite direction.
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
    //! @brief Manages the bindings between the hardware input and the game input.
	struct KeymapManager {
		char unknown[0x4];
		char isPlayer;
		char unknown2[0x33];
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
