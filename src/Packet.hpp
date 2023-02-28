//
// Created by PinkySmile on 04/06/2020.
//

#ifndef SOKULIB_PACKET_HPP
#define SOKULIB_PACKET_HPP


#include <cstdint>
#include <vector>
#include <winsock.h>
#include "Character.hpp"
#include "Weather.hpp"

#pragma pack(push, 1)

namespace SokuLib
{
	extern uint8_t Soku110acRollSWRAllChars[16];
	extern uint8_t Soku110acNoRollSWRAllChars[16];
	extern uint8_t Soku110acNoSWRAllChars[16];

	enum PacketType : unsigned char {
		//Base game opcodes
		HELLO = 0x01,
		PUNCH,
		OLLEH,
		CHAIN,
		INIT_REQUEST,
		INIT_SUCCESS,
		INIT_ERROR,
		REDIRECT,
		QUIT = 0x0B,
		HOST_GAME = 0x0D,
		CLIENT_GAME,

		//SokuRoll opcodes
		SOKUROLL_TIME = 0x10,
		SOKUROLL_TIME_ACK,
		SOKUROLL_STATE,
		SOKUROLL_SETTINGS,
		SOKUROLL_SETTINGS_ACK,

		//AdvancedPracticeMode opcodes
		APM_START_SESSION_REQUEST,
		APM_START_SESSION_RESPONSE,
		APM_ELEM_UPDATED,

		//DesyncDetector
		DESDET_MOD_ENABLE_REQUEST = 0x20,
		DESDET_STATE,

		//Soku2
		SOKU2_PLAY_REQU = 0xD3,
	};

	enum RequestType : unsigned char {
		SPECTATE_REQU,
		PLAY_REQU
	};

	enum SceneId : unsigned char {
		SCENEID_CHARACTER_SELECT = 0x03,
		SCENEID_BATTLE = 0x05,
	};

	enum InitErrors {
		ERROR_SPECTATE_DISABLED,
		ERROR_GAME_STATE_INVALID
	};

	enum GameType : unsigned char {
		GAME_LOADED = 0x01,
		GAME_LOADED_ACK,
		GAME_INPUT,
		GAME_MATCH,
		GAME_MATCH_ACK,
		GAME_MATCH_REQUEST = 0x08,
		GAME_REPLAY,
		GAME_REPLAY_REQUEST = 0x0B
	};

	enum CharacterPacked : unsigned char {
		PACKED_CHARACTER_REIMU     = CHARACTER_REIMU,
		PACKED_CHARACTER_MARISA    = CHARACTER_MARISA,
		PACKED_CHARACTER_SAKUYA    = CHARACTER_SAKUYA,
		PACKED_CHARACTER_ALICE     = CHARACTER_ALICE,
		PACKED_CHARACTER_PATCHOULI = CHARACTER_PATCHOULI,
		PACKED_CHARACTER_YOUMU     = CHARACTER_YOUMU,
		PACKED_CHARACTER_REMILIA   = CHARACTER_REMILIA,
		PACKED_CHARACTER_YUYUKO    = CHARACTER_YUYUKO,
		PACKED_CHARACTER_YUKARI    = CHARACTER_YUKARI,
		PACKED_CHARACTER_SUIKA     = CHARACTER_SUIKA,
		PACKED_CHARACTER_REISEN    = CHARACTER_REISEN,
		PACKED_CHARACTER_AYA       = CHARACTER_AYA,
		PACKED_CHARACTER_KOMACHI   = CHARACTER_KOMACHI,
		PACKED_CHARACTER_IKU       = CHARACTER_IKU,
		PACKED_CHARACTER_TENSHI    = CHARACTER_TENSHI,
		PACKED_CHARACTER_SANAE     = CHARACTER_SANAE,
		PACKED_CHARACTER_CIRNO     = CHARACTER_CIRNO,
		PACKED_CHARACTER_MEILING   = CHARACTER_MEILING,
		PACKED_CHARACTER_UTSUHO    = CHARACTER_UTSUHO,
		PACKED_CHARACTER_SUWAKO    = CHARACTER_SUWAKO,
	};

	typedef struct sockaddr_in SockAddrIn;

	struct PacketHello {
		PacketType type;
		SockAddrIn peer;
		SockAddrIn target;
		uint8_t unknown[4];
	};

	struct PacketPunch {
		PacketType type;
		SockAddrIn addr;
		uint8_t unknown[4];
	};

	struct PacketChain {
		PacketType type;
		uint32_t spectatorCount;
	};

	struct PacketInitRequ {
		PacketType type;
		uint8_t gameId[16];
		uint8_t unknown[8];
		RequestType reqType;
		uint8_t nameLength;
		char name[1];
	};

	union Inputs {
		CharacterSelectKeys charSelect;
		BattleKeys battle;
	};

	struct PacketInitSuccAdd {
		PacketType type;
		uint8_t unknown1[8];
		uint8_t dataSize;
		uint8_t unknown2[3];
	};

	struct PacketInitSucc {
		PacketType type;
		uint8_t unknown1[8];
		uint8_t dataSize;
		uint8_t unknown2[3];
		char hostProfileName[32];
		char clientProfileName[32];
		uint32_t swrDisabled;
	};

	struct PacketInitError {
		PacketType type;
		InitErrors reason : 32;
	};

	struct PacketRedirect {
		PacketType type;
		uint32_t childId;
		SockAddrIn target;
		uint8_t unknown[48];
	};

	struct GameLoadedEvent {
		GameType type;
		SceneId sceneId;
	};

	struct GameInputEvent {
		GameType type;
		uint32_t frameId;
		SceneId sceneId;
		uint8_t inputCount;
		Inputs inputs[0];
	};

	struct PlayerData {
		CharacterPacked character;
		uint8_t skinId;
		uint8_t deckId;
		std::vector<uint16_t> cards;
		bool disabledSimultaneousButtons;
	};

	struct MatchData {
		PlayerData host;
		PlayerData client;
		uint8_t stage;
		uint8_t musicId;
		uint32_t seed;
		uint8_t matchId;
	};

	struct ReplayData {
		uint32_t frameId;
		uint32_t endFrameId;
		uint8_t matchId;
		uint8_t length;
		Inputs replayInputs[0];
	};

	struct PlayerMatchData {
		CharacterPacked character;
		uint8_t skinId;
		uint8_t deckId;
		uint8_t deckSize;
		uint16_t cards[1];

		uint8_t &disabledSimultaneousButton()
		{
			return *reinterpret_cast<uint8_t *>(&this->cards[this->deckSize]);
		}

		const uint8_t &disabledSimultaneousButton() const
		{
			return *reinterpret_cast<const uint8_t *>(&this->cards[this->deckSize]);
		}

		uint8_t *getEndPtr()
		{
			return reinterpret_cast<uint8_t *>(&this->cards[this->deckSize]) + 1;
		}

		const uint8_t *getEndPtr() const
		{
			return reinterpret_cast<const uint8_t *>(&this->cards[this->deckSize]) + 1;
		}
	};

	struct GameMatchEvent {
		GameType type;
		PlayerMatchData host;
		uint8_t data[sizeof(PlayerMatchData) + 256 * 2 + 7];

		PlayerMatchData &client()
		{
			return *reinterpret_cast<PlayerMatchData *>(this->host.getEndPtr());
		}

		uint8_t &stageId()
		{
			return *this->client().getEndPtr();
		}

		uint8_t &musicId()
		{
			return this->client().getEndPtr()[1];
		}

		uint32_t &randomSeed()
		{
			return *reinterpret_cast<uint32_t *>(&this->client().getEndPtr()[2]);
		}

		uint8_t &matchId()
		{
			return this->client().getEndPtr()[6];
		}

		const PlayerMatchData &client() const
		{
			return *reinterpret_cast<const PlayerMatchData *>(this->host.getEndPtr());
		}

		const uint8_t &stageId() const
		{
			return *this->client().getEndPtr();
		}

		const uint8_t &musicId() const
		{
			return this->client().getEndPtr()[1];
		}

		const uint32_t &randomSeed() const
		{
			return *reinterpret_cast<const uint32_t *>(&this->client().getEndPtr()[2]);
		}

		const uint8_t &matchId() const
		{
			return this->client().getEndPtr()[6];
		}
	};

	std::ostream &operator<<(std::ostream &stream, const PlayerMatchData &data);

	struct GameReplayEvent {
		GameType type;
		uint8_t replaySize;
		uint8_t compressedData[0];
	};

	struct GameReplayRequestEvent {
		GameType type;
		uint32_t frameId;
		uint8_t matchId;
	};

	union GameEvent {
		GameType type;
		GameLoadedEvent loaded;
		GameInputEvent input;
		GameMatchEvent match;
		GameReplayEvent replay;
		GameReplayRequestEvent replayRequest;
	};

	struct PacketGame {
		PacketType type;
		GameEvent event;
	};

	struct PacketRollTime {
		PacketType type;
		uint32_t sequenceId;
		uint32_t timeStamp;
	};

	struct PacketRollState {
		PacketType type;
		int32_t frameId;
		int32_t hostX;
		int32_t hostY;
		int32_t clientX;
		int32_t clientY;
		uint8_t stuff[4];
	};

	struct PacketRollSettings {
		PacketType type;
		uint8_t maxRollback;
		uint8_t delay;
	};

	struct PacketApmStartSessionResponse {
		PacketType type;
		bool accepted;
	};

	union ElemProperty {
		float value;
		int selected;
		bool checked;
		char text[4];
	};

	struct PacketApmElemUpdated {
		PacketType type;
		char name[64];
		ElemProperty property;
	};

	struct PacketDesDetState {
		PacketType type;
		unsigned short lX : 11;
		unsigned short lY : 11;
		unsigned short rX : 11;
		unsigned short rY : 11;
		unsigned short lHP : 10;
		unsigned short rHP : 10;
		unsigned short weatherCounter : 10;
		Weather displayedWeather : 5;
		bool _ : 1;
	};

	struct PacketSoku2PlayRequ {
		PacketType type;
		unsigned char major;
		unsigned char minor;
		char letter;
	};

	union Packet {
		PacketType type;
		PacketHello hello;
		PacketPunch punch;
		PacketChain chain;
		PacketInitRequ initRequest;
		PacketInitSucc initSuccess;
		PacketInitError initError;
		PacketRedirect redirect;
		PacketGame game;
		PacketRollTime rollTime;
		PacketRollState rollState;
		PacketRollSettings rollSettings;
		PacketApmStartSessionResponse apmResponse;
		PacketApmElemUpdated apmElemUpdated;
		PacketDesDetState desDetState;
		PacketSoku2PlayRequ soku2PlayRequ;
	};

	std::string PacketTypeToString(PacketType);
	std::string RequestTypeToString(RequestType);
	std::string SceneIdToString(SceneId);
	std::string InitErrorsToString(InitErrors);
	std::string GameTypeToString(GameType);
	void displayPacketContent(std::ostream &stream, const Packet &packet);
}

#pragma pack(pop)

#endif //SOKUTEST_PACKET_HPP
