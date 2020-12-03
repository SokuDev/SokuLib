//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_SCENES_HPP
#define SOKULIB_SCENES_HPP


#include <vector>
#include <string>
#include "../Core/SokuAddresses.hpp"

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
		SCENE_SELECTSENARIO,
		SCENE_ENDING = 20,
		SCENE_MAX,
	};
	#pragma pack(pop)

	// �V�[��ID
	// DWORD
	extern Scene &newSceneId;
	extern Scene &sceneId;
	extern HANDLE &LGThread;

	void changeScene(Scene newScene);
	void waitForSceneChange();

	extern std::vector<std::string> sceneNames;
}

#endif //SOKULIB_SCENES_HPP
