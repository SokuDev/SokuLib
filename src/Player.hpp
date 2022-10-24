//
// Created by DPhoenix on 20/09/2022.
//

#ifndef SOKULIB_PLAYER_HPP
#define SOKULIB_PLAYER_HPP

#include "GameObject.hpp"
#include "Deque.hpp"
#include "Character.hpp"

namespace SokuLib {
namespace v2 {
	class Player : public GameObjectBase {
	public:
		// offset 0x34C
		Character characterIndex;
		char playerIndex;
		char palette;
		char unknown352[0x2]; // align 0x2?
		int portraitTexId = 0;
		Sprite portrait; // sizeof = 0x94
		struct StandInfo {
			int texId = 0;
			Sprite sprite; // sizeof = 0x94
			int playerIndex;
			int unknown488; // 0x46eb80: = -1;
			Vector2f unknown48C; // some coord
			char unknown494;
			// align 3
		} stand;

		short unknown498; // 46b9a0: = 10000 (HP related)
		char unknown49A, unknown49B, unknown49C, unknown49D; // 46b9a0: = 0
		short unknown49E, unknown4A0;  // 46b9a0: = 100
		short unknown4A2, unknown4A4, unknown4A6, unknown4A8, unknown4AA; // 46b9a0: = 0
		char unknown4AC, unknown4AD; // 46b9a0: = 0
		char unknown4AE[2]; // align 2?
		float unknown4B0; // 46b9a0: = 1.0
		short unknown4B4, unknown4B6, unknown4B8, unknown4BA, unknown4BC, unknown4BE; // 46b9a0: = 0 (+4bc = armor related)
		short unknown4C0, unknown4C2; // 46b9a0: = 0
		char unknown4C4, unknown4C5; // 48b000: +4c4 = 0
		short unknown4C6; // 46b9a0: = 0
		int unknown4C8; // 48b000: = 0
		char unknown4CC, unknown4CD; // 46b9a0: = 0 (+4cd = healingLightActive)
		short unknown4CE; // 46b9a0: = 0 (healingLightFXDelay)
		float unknown4D0; // 48b000: = 1.0
		short unknown4D4, unknown4D6; // 46b9a0: = 0
		char unknown4D8; // 46b9a0: = 0
		char unknown4D9[3]; // align 3?
		int unknown4DC[16]; // 46b9a0: = 0
		short unknown51C[7]; // 46b9a0: = 0
		char unknown52A, unknown52B; // 48b000: +52A = 0
		int weatherId; // 46b9a0: = 0;
		float unknown530[12]; // 46b9a0: = {1,1,1,1, 0,1,1,1, 0,0,0,1}; // 0x538 = ArmorMultiplier/Mitigation
		short unknown560; // 46b9a0: = 0
		char unknown562[2]; // align 2?
		float unknown564, unknown568; // 46b9a0: = 1.0
		char unknown56C[16]; // 46b9a0: = {0,0,0,0, 0,1,1,0, 0,0,0,0, 0,?,?,?};

		//offset 0x57c
		struct DeckInfo {
			Deque<int> textures;
			Map<int, SokuLib::CardInfo> cardById;
			Deque<unsigned short> original;
			Deque<unsigned short> queue;
			unsigned char availSkills[32]; // 435a50: for (cardById) if (type = skill) availSkills[CardData.costOrSlot] = id

			SokuLib::CardInfo* cardLookup(unsigned short id);
		} deckData;

		// offset 0x5e4
		struct HandInfo {
			short cardGauge;
			unsigned char cardCount;
			unsigned char cardSlots;

			Deque<SokuLib::Card> hand;
			Deque<unsigned short> usedCards;
		} handData;

		// offset 0x610
		Sprite unknown610; // sizeof = 0x94
		// offset 0x6A4
		char skillLevelA[32]; // this one starts as 0
		char skillLevelB[32]; // this one starts as -1 (except the first four reset in: 48b000)
		int unknown6E4, unknown6E8; // 46b9a0: = 0
		int unknown6EC, unknown6F0; // 46b9a0: = -1
		char unknown6F4, unknown6F5; // 46b9a0: = 0
		char unknown6F6[2]; // align 2?

		// offset 0x6f8
		IGameObjectList* objectList;
		Deque<CharacterSequenceData> patternData;
		int unknown710; // 46b9a0: = 0

		struct {
			List<SpriteEx> unknown714; // unsure (maybe struct {SpriteEx,byte})
			char unknown720 = 5;
			char unknown721;
			short unknown722 = 15;
			char unknown724[4];
			char unknown728; // 46b9a0: = 0
			char unknown729[3];
		} unknown714;

		Deque<int> unknown72C; // seems to hold textureIDs of spell backgrounds
		short unknown740; // 46b9a0: = 0
		char unknown742[2];
		float unknown744; // 46b9a0: = .0
		float unknown748; // 46b9a0: = .0
		float unknown74C; // 46b9a0: = .0

		// offset 0x750
		KeyManager& keyManager;
		struct InputInfo {
			KeyInput keyInput; // sizeof = 0x20
			// offset 0x774
			int unknown774[14]; // 46cac0: = 0;
			char unknown7AC; // 46cac0: = 0;
			char unknown7AD[3]; // align 3?
			// offset 0x7B0
			Deque<unsigned short> commandInputBuffer;
			int movimentCombination; // 46b9a0: = 0
			KeyCombination commandCombination; // 46b9a0: = 0
			char unknown7CC; // type of input? (checks for 0, 1 or 2)
			// align 0x3
		} inputData;

		short unknown7D0[5]; // 48b000: = 0;
		char unknown7DA[2]; // align 0x2?
		float unknown7DC[6]; // 48b000: = .0;
		char unknown7F4[4]; // 48b000: = 0;
		short unknown7F8; // 48b000: = 0;
		char unknown7FA[2]; // align 2?
		float unknown7FC; // 48b000: = .0;
		char unknown800[5]; // 48b000: = 0;
		char unknown805[3]; // align 3?
		float unknown808; // 48b000: = .0;
		char unknown80C[4]; // 48b000: (+80D, +80E) = .0; (+80D = isAuraActive)
		int unknown810, unknown814; // 48b000: = 0; (auraFXDelay, auraDuration)
		short unknown818[10]; // 48b000: = 0;
		float unknown82C, unknown830; // 48b000: = .0;
		short unknown834; // 48b000: = 0;
		char unknown836[2]; // 48b000: +836 = 0;
		float unknown838; // 48b000: = .0;
		char unknown83C; // 48b000: = 0;
		char unknown83D[3]; // align 3?
		float unknown840[3]; // 48b000: = .0;
		short unknown84C[4]; // 48b000: = 0; (timeStopDuration)
		float unknown854[5]; // 48b000: = .0;
		char unknown868[2]; // 48b000: +868 = 0;
		short unknown86A; // 48b000: = 0;
		int unknown86C[5]; // 48b000: = 0;
		char unknown880[2]; // 48b000: +880 = 0;
		short unknown882[7]; // 48b000: = 0;
		// found shared data until size: 0x890 (0x48b088: short this[0x88e])

		Player(const PlayerInfo& playerInfo);
		virtual ~Player();

		virtual void initialize() = 0; // character specific initialization
		virtual bool VUnknown48() = 0; // check for landing
		virtual bool VUnknown4C(int a) = 0; // something with actionId in [700,799]
		virtual void VUnknown50() = 0; // seems to handle inputs (differs for each character)
		virtual void VUnknown54() = 0; // compare input buffer for sequences
	};

	class PlayerReimu     : public Player { public: char unknown890[0x2C]; };
	class PlayerMarisa    : public Player { public: char unknown890[0x1C]; };
	class PlayerSakuya    : public Player { public: char unknown890[0x10]; };
	class PlayerAlice     : public Player { public: char unknown890[0x34]; };
	class PlayerPatchouli : public Player { public: char unknown890[0x18]; };
	class PlayerYoumu     : public Player { public: char unknown890[0x5C]; };
	class PlayerRemilia   : public Player { public: char unknown890[0x04]; };
	class PlayerYuyuko    : public Player { public: char unknown890[0x1C]; };
	class PlayerYukari    : public Player { public: char unknown890[0x44]; };
	class PlayerSuika     : public Player { public: char unknown890[0x08]; };
	class PlayerUdonge    : public Player { public: char unknown890[0x28]; };
	class PlayerAya       : public Player { public: char unknown890[0x08]; };
	class PlayerKomachi   : public Player { public: char unknown890[0x08]; };
	class PlayerIku       : public Player { public: char unknown890[0x18]; };
	class PlayerTenshi    : public Player { public: char unknown890[0xA0]; }; // TODO There's something wrong with tenshi
	class PlayerSanae     : public Player { public: char unknown890[0x20]; };
	class PlayerChirno    : public Player { public: char unknown890[0x04]; };
	class PlayerMeirin    : public Player { public: char unknown890[0x04]; };
	class PlayerUtsuho    : public Player { public: char unknown890[0x18]; };
	class PlayerSuwako    : public Player { public: char unknown890[0x18]; };
	class PlayerNamazu    : public Player { public: char unknown890[0x10]; };
}}

#endif