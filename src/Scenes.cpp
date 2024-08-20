//
// Created by PinkySmile on 04/11/2020.
//

#include <windows.h>
#include <thread>
#include "Scenes.hpp"

namespace SokuLib
{
	std::vector<std::string> sceneNames{
		"Startup logo",                      //SCENE_LOGO         = 0,
		"Opening scene",                     //SCENE_OPENING      = 1,
		"Title screen",                      //SCENE_TITLE        = 2,
		"Local character select",            //SCENE_SELECT       = 3,
		"Scene 4",                           //???                = 4,
		"Local battle",                      //SCENE_BATTLE       = 5,
		"Loading local game",                //SCENE_LOADING      = 6,
		"Scene 7",                           //???                = 7,
		"Online character select",           //SCENE_SELECTSV     = 8,
		"Online character select",           //SCENE_SELECTCL     = 9,
		"Loading online match as host",      //SCENE_LOADINGSV    = 10,
		"Loading online match as client",    //SCENE_LOADINGCL    = 11,
		"Loading online battle as spectator",//SCENE_LOADINGWATCH = 12,
		"Online battle as host",             //SCENE_BATTLESV     = 13,
		"Online battle as client",           //SCENE_BATTLECL     = 14,
		"Online battle as spectator",        //SCENE_BATTLEWATCH  = 15,
		"Selecting scenario",                //SCENE_SELECTSCENARIO= 16,
		"Scene 17",                          //???                = 17,
		"Scene 18",                          //???                = 18,
		"Scene 19",                          //???                = 19,
		"Credits",                           //SCENE_ENDING       = 20,
	};

	Scene &newSceneId = *reinterpret_cast<Scene *>(ADDR_SCENE_ID_NEW);
	Scene &sceneId = *reinterpret_cast<Scene *>(ADDR_SCENE_ID);
	HANDLE &LGThread = *reinterpret_cast<HANDLE *>(ADDR_LOAD_GRAPHICS_THREAD);
	SceneBase *&currentScene = *reinterpret_cast<SceneBase **>(ADDR_CURRENT_SCENE);

	void changeScene(Scene newScene)
	{
		if (sceneId != newScene) {
			newSceneId = newScene;
			LGThread = CreateThread(
				nullptr,
				0,
				(LPTHREAD_START_ROUTINE)ADDR_LOAD_GRAPHICS_FUN,
				nullptr,
				0,
				(LPDWORD)ADDR_LOAD_GRAPHICS_THREAD_ID
			);
		}
	}

	void waitForSceneChange()
	{
		while (sceneId != newSceneId)
			std::this_thread::sleep_for(std::chrono::milliseconds (10));
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}