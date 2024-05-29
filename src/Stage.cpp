//
// Created by PinkySmile on 04/11/2020.
//

#include "Stage.hpp"
#include "StageManager.hpp"

namespace SokuLib
{
	std::vector<std::string> stagesName{
		"Hakurei Shrine",
		"Forest of Magic",
		"Creek of Genbu",
		"Youkai Mountain",
		"Mysterious Sea of Cloud",
		"Bhava-Agra",
		"Hakurei Shrine",
		"Kirisame Magic Shop",
		"Scarlet Devil Mansion Clock Tower",
		"Forest of Dolls",
		"Scarlet Devil Mansion Library",
		"Netherworld",
		"Scarlet Devil Mansion Foyer",
		"Hakugyokurou Snowy Garden",
		"Bamboo Forest of the Lost",
		"Shore of Misty Lake",
		"Moriya Shrine",
		"Mouth of Geyser",
		"Catwalk of Geyser",
		"Fusion Reactor Core",
	};

	unsigned char flattenStageId(Stage id)
	{
		unsigned char index = id;

		if (index >= 30)
			index -= 11;
		if (index >= 10)
			index -= 4;
		return index;
	}

	Stage &stageId = *reinterpret_cast<Stage *>(ADDR_LOADED_STAGE_ID);
	v2::StageManager*& v2::StageManager::instance = *reinterpret_cast<v2::StageManager**>(ADDR_STAGE_MANAGER);
	void v2::StageManager::loadStage(Stage stage, int divider, bool useThread)
		{ return (this->*union_cast<void (v2::StageManager::*)(int, int, bool)>(0x471500))((int)stage, divider, useThread); };
}