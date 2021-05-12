//
// Created by PinkySmile on 12/05/2021.
//

#ifndef SOKULIB_DEPRECATEDELEMENTS_HPP
#define SOKULIB_DEPRECATEDELEMENTS_HPP


#warning These will be removed in later versions. Use at your own risks !

#include "SokuLib.hpp"

#define SCENE_SELECTSENARIO SCENE_SELECTSCENARIO

namespace SokuLib
{
	[[deprecated("Replaced by Sprite")]]
	typedef Sprite CSprite;

	[[deprecated("Replaced with DeckInfo")]]
	typedef DeckInfo deckInfo;
}

#endif //SOKULIB_DEPRECATEDELEMENTS_HPP
