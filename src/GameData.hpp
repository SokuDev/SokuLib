//
// Created by DPhoenix on 20/06/2023.
//

#ifndef SOKULIB_GAME_DATA_HPP
#define SOKULIB_GAME_DATA_HPP

#include "Map.hpp"
#include "Player.hpp"

namespace SokuLib {
namespace v2 {
	struct GameDataManager {
		// 0x00
		List<std::pair<int, PlayerInfo*>> createQueue;
		// 0x0C
		bool isThreadsRunning; // align 3
		// 0x10
		uint32_t threadHandleA; // 0x46e6d0
		uint32_t threadIdA;
		uint32_t threadHandleB; // 0x46e6f0 THREAD_PRIORITY_IDLE
		uint32_t threadIdB;
		uint32_t eventHandleA;
		uint32_t eventHandleB;
		// 0x28
		Player* players[4];
		// 0x38
		bool enabledPlayers[4]; // 01 01 00 00
		// 0x3C
		Vector<Player*> activePlayers;
		// 0x4C
		List<Player*> destroyQueue;

		static GameDataManager*& instance;
	}; // 0x58

	struct SaveDataManager {
		int unknown00;
		// 0x00
		char unknown04[0x18];
		// 0x1C
		bool enabledScenarios[20];
		// 0x30
		bool enabledCharacters[20];
		// 0x44: std::set<int>
		void* unknown44[3];
		// 0x50: std::set<int>
		void* unknown50[3];
		// 0x5C
		char unknown5C[0x40];
		// 0x9C
		Map<int, int> systemCards;
		// 0xa8
		Map<int, int> characterCards[20];
		// 0x198: std::set<int>
		void* unknown198[3];

		// TODO there's more data after this

		static SaveDataManager& instance;
		void enableCharacter(int characterId); // 0x42ee80
		bool loadData(); // 0x433330
		void saveData(); // 0x42fa10
	};
}}

#endif