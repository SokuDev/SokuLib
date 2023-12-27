//
// Created by PinkySmile on 04/11/2020.
//

#ifndef SOKULIB_STAGE_HPP
#define SOKULIB_STAGE_HPP


#include <vector>
#include <string>
#include "SokuAddresses.hpp"

namespace SokuLib
{
	extern std::vector<std::string> stagesName;

	//! @brief All the selectable stages.
	enum Stage : unsigned char {
		STAGE_HAKUREI_SHRINE_BROKEN,
		STAGE_FOREST_OF_MAGIC,
		STAGE_CREEK_OF_GENBU,
		STAGE_YOUKAI_MOUNTAIN,
		STAGE_MYSTERIOUS_SEA_OF_CLOUD,
		STAGE_BHAVA_AGRA,
		STAGE_SPACE,
		STAGE_HAKUREI_SHRINE = 10,
		STAGE_KIRISAME_MAGIC_SHOP,
		STAGE_SCARLET_DEVIL_MANSION_CLOCK_TOWER,
		STAGE_FOREST_OF_DOLLS,
		STAGE_SCARLET_DEVIL_MANSION_LIBRARY,
		STAGE_NETHERWORLD,
		STAGE_SCARLET_DEVIL_MANSION_FOYER,
		STAGE_HAKUGYOKUROU_SNOWY_GARDEN,
		STAGE_BAMBOO_FOREST_OF_THE_LOST,
		STAGE_SHORE_OF_MISTY_LAKE = 30,
		STAGE_MORIYA_SHRINE,
		STAGE_MOUTH_OF_GEYSER,
		STAGE_CATWALK_OF_GEYSER,
		STAGE_FUSION_REACTOR_CORE,
		STAGE_SCARLET_DEVIL_MANSION_CLOCK_TOWER_SKETCH_BG = 36,
		STAGE_SCARLET_DEVIL_MANSION_CLOCK_TOWER_BLURRY,
		STAGE_SCARLET_DEVIL_MANSION_CLOCK_TOWER_SKETCH,
	};

	//! @brief Takes the raw stage id and restrict it in the range [0-19]
	//! @param id The stage id to convert
	//! @return The stage index between 0 and 19 (bounds included)
	unsigned char flattenStageId(Stage id);

	extern Stage &stageId;
}


#endif //SOKULIB_STAGE_HPP
