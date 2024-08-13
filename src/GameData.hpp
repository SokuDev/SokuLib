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
		// 0x00
		int unknown00;
		int bestScore;
		unsigned char scenarioScore[20];
		// 0x1C
		bool enabledScenarios[20];
		// 0x30
		bool enabledCharacters[20];
		// 0x44: std::set<int> // hashed filename
		void* enabledBgms[3];
		// 0x50: std::set<int>
		void* enabledStages[3];
		// 0x5C
		Vector<void*> unknown5C; // Scenario related
		Vector<void*> unknown6C; // Character related
		char unknown7C[0x20];
		// 0x9C
		Map<int, int> systemCards;
		// 0xa8
		Map<int, int> characterCards[20];
		// 0x198: std::set<int>
		void* unknown198[3];
		// 0x1a4:
		struct UnknownData {char unknown[0x18];};
		Vector<UnknownData> unknown1A4[20]; // some kind of counter

		// TODO (maybe) there's more data after this

		static SaveDataManager& instance;
		void enableStage(int stageId); // 0x430c60
		void enableCharacter(int characterId); // 0x42ee80
		void enableBgm(const char* filename); // 0x430ca0
		bool loadData(); // 0x433330
		void saveData(); // 0x42fa10
		void saveScenarioResult(int characterId, unsigned char score); // 0x431c20
	};

	extern float (&groundHeight)[1280];
}}

#endif