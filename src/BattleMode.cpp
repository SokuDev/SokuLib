//
// Created by PinkySmile on 04/11/2020.
//

#include "BattleMode.hpp"

namespace SokuLib
{
	std::vector<std::array<std::string, 3>> modeNames{
		//????                       Story mode                      Story mode replay
		{"0.0",                      "Playing story mode",            "Watching a story mode replay"},
		//Arcade mode                ?????                           ?????
		{"Playing in Arcade mode",   "1.1",                           "1.2"},
		//????                       VSCom                           ?????
		{"2.0",                      "Playing against computer",      "2.2"},
		//????                       VSPlayer                        Replay
		{"3.0",                      "Playing multiplayer (Offline)", "Watching a replay"},
		//????                       VSNetwork                       ?????
		{"4.0",                      "Playing multiplayer (Online)",  "4.2"},
		//????                       VSNetwork                       VSNetwork (Spectator)
		{"5.0",                      "Playing multiplayer (Online)",  "Spectating game"},
		//????                       ?????                           ?????
		{"6.0",                      "6.1",                           "Spectating game"},
		//????                       Result                          Result replay
		{"7.0",                      "Playing time trial",            "Watching a time trial replay"},
		//Practice                   ?????                           ?????
		{"Playing in practice mode", "8.1",                           "8.2"}
	};

	BattleMode &mainMode = *reinterpret_cast<BattleMode *>(ADDR_COMM_MODE);
	BattleSubMode &subMode = *reinterpret_cast<BattleSubMode *>(ADDR_SUB_MODE);
	int &menuMode = *reinterpret_cast<int *>(ADDR_MENU_MODE);
}