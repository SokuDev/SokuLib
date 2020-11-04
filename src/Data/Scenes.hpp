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
	//From swrs.h (SWRSToys)
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

	//From swrs.h (SWRSToys)
	// �V�[��ID
	// DWORD
	__forceinline Scene getSceneIdNew()
	{
		return *reinterpret_cast<Scene *>(ADDR_SCENE_ID_NEW);
	}

	//From swrs.h (SWRSToys)
	__forceinline Scene getSceneId()
	{
		return *reinterpret_cast<Scene *>(ADDR_SCENE_ID);
	}

	// From me
	extern std::vector<std::string> sceneNames;
}

#endif //SOKULIB_SCENES_HPP
