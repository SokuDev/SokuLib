//
// Created by PinkySmile on 04/06/2020.
//

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>
#include "Packet.hpp"

#ifndef SOKULIB_NO_MOD
#include "dlls/WS2_32.DLL.hpp"
#define htons(s) DLL::ws2_32.htons(s)
#endif


#ifdef _WIN32
#define s_b1 S_un.S_un_b.s_b1
#define s_b2 S_un.S_un_b.s_b2
#define s_b3 S_un.S_un_b.s_b3
#define s_b4 S_un.S_un_b.s_b4
#else
#define s_b1 s_addr >> 0 & 0xFF
#define s_b2 s_addr >> 8 & 0xFF
#define s_b3 s_addr >> 16 & 0xFF
#define s_b4 s_addr >> 24 & 0xFF
#endif

namespace SokuLib
{
	extern std::vector<std::string> charactersName;

	uint8_t Soku110acRollSWRAllChars[16] = {
		0x64, 0x73, 0x65, 0xD9,
		0xFF, 0xC4, 0x6E, 0x48,
		0x8D, 0x7C, 0xA1, 0x92,
		0x31, 0x34, 0x72, 0x95
	};
	uint8_t Soku110acNoRollSWRAllChars[16] = {
		0x6E, 0x73, 0x65, 0xD9,
		0xFF, 0xC4, 0x6E, 0x48,
		0x8D, 0x7C, 0xA1, 0x92,
		0x31, 0x34, 0x72, 0x95
	};
	uint8_t Soku110acNoSWRAllChars[16] = {
		0x46, 0xC9, 0x67, 0xC8,
		0xAC, 0xF2, 0x44, 0x4D,
		0xB8, 0xB1, 0xEC, 0xEE,
		0xD4, 0xD5, 0x40, 0x4A
	};

	void displayGameEvent(std::ostream &stream, const GameEvent &event)
	{
		stream << ", eventType: " << GameTypeToString(event.type);
		switch (event.type) {
		case GAME_LOADED:
		case GAME_LOADED_ACK:
			stream << ", sceneId: " << SceneIdToString(event.loaded.sceneId);
			break;
		case GAME_INPUT:
			stream << ", frameId: " << event.input.frameId;
			stream << ", sceneId: " << SceneIdToString(event.input.sceneId);
			stream << ", inputCount: " << static_cast<int>(event.input.inputCount);
			stream << ", inputs: [" << std::hex;
			for (int i = 0; i < event.input.inputCount; i++)
				stream << (i == 0 ? "" : ", ") << event.input.inputs[i].raw;
			stream << "]" << std::dec;
			break;
		case GAME_MATCH:
			stream << ", host: " << event.match.host;
			stream << ", client: " << event.match.client();
			stream << ", stageId: " << (int)event.match.stageId();
			stream << ", musicId: " << (int)event.match.musicId();
			stream << ", randomSeed: " << event.match.randomSeed();
			stream << ", matchId: " << (int)event.match.matchId();
			break;
		case GAME_REPLAY:
			stream << ", replaySize: " << (int)event.replay.replaySize;
			break;
		case GAME_REPLAY_REQUEST:
			stream << ", frameId: " << (int)event.replayRequest.frameId;
			stream << ", matchId: " << (int)event.replayRequest.matchId;
			break;
		case GAME_MATCH_ACK:
		case GAME_MATCH_REQUEST:
			break;
		}
	}

	std::ostream &operator<<(std::ostream &stream, const PlayerMatchData &data)
	{
		stream << "{character: " << (data.character < SokuLib::charactersName.size() ? SokuLib::charactersName.at(data.character) : "Character " + std::to_string(data.character));
		stream << ", skinId: " << std::dec << (int)data.skinId;
		stream << ", deckId: " << (int)data.deckId;
		stream << ", deckSize: " << (int)data.deckSize;
		stream << ", cards: [";
		for (int i = 0; i < data.deckSize; i++)
			stream << (i == 0 ? "" : ", ") << data.cards[i];
		stream << "]";
		stream << ", disabledSimultaneousButton: " << std::boolalpha << (int)data.disabledSimultaneousButton() << std::noboolalpha << "}" << std::dec;
		return stream;
	}

	void displayPacketContent(std::ostream &stream, const Packet &packet)
	{
		stream << "type: " << PacketTypeToString(packet.type);
		switch (packet.type) {
		case HELLO:
			stream << ", peer: ";
			stream << static_cast<int>(packet.hello.peer.sin_addr.s_b1) << ".";
			stream << static_cast<int>(packet.hello.peer.sin_addr.s_b2) << ".";
			stream << static_cast<int>(packet.hello.peer.sin_addr.s_b3) << ".";
			stream << static_cast<int>(packet.hello.peer.sin_addr.s_b4) << ":";
			stream << static_cast<int>(htons(packet.hello.peer.sin_port)) << ", target: ";
			stream << static_cast<int>(packet.hello.target.sin_addr.s_b1) << ".";
			stream << static_cast<int>(packet.hello.target.sin_addr.s_b2) << ".";
			stream << static_cast<int>(packet.hello.target.sin_addr.s_b3) << ".";
			stream << static_cast<int>(packet.hello.target.sin_addr.s_b4) << ":";
			stream << static_cast<int>(htons(packet.hello.target.sin_port)) << ", unknown: [";
			stream << std::hex;
			for (int i = 0; i < 4; i++)
				stream << (i == 0 ? "" : ", ") << "0x" << static_cast<int>(packet.punch.unknown[i]);
			stream << "]" << std::dec;
			break;
		case PUNCH:
			stream << ", addr: ";
			stream << static_cast<int>(packet.punch.addr.sin_addr.s_b1) << ".";
			stream << static_cast<int>(packet.punch.addr.sin_addr.s_b2) << ".";
			stream << static_cast<int>(packet.punch.addr.sin_addr.s_b3) << ".";
			stream << static_cast<int>(packet.punch.addr.sin_addr.s_b4) << ":";
			stream << static_cast<int>(htons(packet.punch.addr.sin_port)) << ", unknown: [";
			stream << std::hex;
			for (int i = 0; i < 4; i++)
				stream << (i == 0 ? "" : ", ") << "0x" << static_cast<int>(packet.punch.unknown[i]);
			stream << "]" << std::dec;
			break;
		case CHAIN:
			stream << ", spectatorCount: " << packet.chain.spectatorCount;
			break;
		case INIT_REQUEST:
			stream << ", gameId: [" << std::hex;
			for (int i = 0; i < 16; i++)
				stream << (i == 0 ? "" : ", ") << "0x" << static_cast<int>(packet.initRequest.gameId[i]);
			stream << "], unknown: [";
			for (int i = 0; i < 8; i++)
				stream << (i == 0 ? "" : ", ") << "0x" << static_cast<int>(packet.initRequest.unknown[i]);
			stream << "], reqType: " << RequestTypeToString(packet.initRequest.reqType) << std::dec;
			stream << ", nameLength: " << static_cast<int>(packet.initRequest.nameLength) << ", name: \"";
			stream << std::string(packet.initRequest.name, packet.initRequest.nameLength) << "\"";
			break;
		case INIT_SUCCESS:
			stream << ", unknown1: [";
			stream << std::hex;
			for (int i = 0; i < 8; i++)
				stream << (i == 0 ? "" : ", ") << "0x" << static_cast<int>(packet.initSuccess.unknown1[i]);
			stream << "], dataSize: " << std::dec << static_cast<int>(packet.initSuccess.dataSize);
			stream << ", unknown2: [" << std::hex;
			for (int i = 0; i < 2; i++)
				stream << (i == 0 ? "" : ", ") << "0x" << static_cast<int>(packet.initSuccess.unknown2[i]);
			stream << "]" << std::dec;
			if (packet.initSuccess.dataSize) {
				stream << ", hostProfileName: \"" << packet.initSuccess.hostProfileName << "\"";
				stream << ", clientProfileName: \"" << packet.initSuccess.clientProfileName << "\"";
				stream << ", swrDisabled: " << packet.initSuccess.swrDisabled;
			}
			break;
		case INIT_ERROR:
			stream << ", reason: " << packet.initError.reason;
			break;
		case REDIRECT:
			stream << ", childId: " << packet.redirect.childId;
			stream << ", target: ";
			stream << static_cast<int>(packet.redirect.target.sin_addr.s_b1) << ".";
			stream << static_cast<int>(packet.redirect.target.sin_addr.s_b2) << ".";
			stream << static_cast<int>(packet.redirect.target.sin_addr.s_b3) << ".";
			stream << static_cast<int>(packet.redirect.target.sin_addr.s_b4) << ":";
			stream << static_cast<int>(htons(packet.redirect.target.sin_port)) << ", unknown: [" << std::hex;
			for (int i = 0; i < 48; i++)
				stream << (i == 0 ? "" : ", ") << "0x" << static_cast<int>(packet.redirect.unknown[i]);
			stream << "]" << std::dec;
			break;
		case OLLEH:
		case QUIT:
		case SOKUROLL_SETTINGS_ACK:
		case APM_START_SESSION_REQUEST:
		case DESDET_MOD_ENABLE_REQUEST:
			break;
		case SOKU2_PLAY_REQU:
			stream << ", version: " << (int)packet.soku2PlayRequ.major << "." << (int)packet.soku2PlayRequ.minor << packet.soku2PlayRequ.letter;
			break;
		case DESDET_STATE:
			stream << ", lX: " << std::dec << packet.desDetState.lX;
			stream << ", lY: " << packet.desDetState.lY;
			stream << ", rX: " << packet.desDetState.rX;
			stream << ", rY: " << packet.desDetState.rY;
			stream << ", lHP: " << packet.desDetState.lHP;
			stream << ", rHP: " << packet.desDetState.rHP;
			stream << ", weatherCounter: " << packet.desDetState.weatherCounter;
			stream << ", displayedWeather: " << packet.desDetState.displayedWeather;
			break;
		case HOST_GAME:
		case CLIENT_GAME:
			displayGameEvent(stream, packet.game.event);
			break;
		case SOKUROLL_TIME:
		case SOKUROLL_TIME_ACK:
			stream << ", sequenceId: " << packet.rollTime.sequenceId;
			stream << ", timeStamp: " << packet.rollTime.timeStamp;
			break;
		case SOKUROLL_STATE:
			stream << ", frameId: " << packet.rollState.frameId;
			stream << ", hostX: " << packet.rollState.hostX;
			stream << ", hostY: " << packet.rollState.hostY;
			stream << ", clientX: " << packet.rollState.clientX;
			stream << ", clientY: " << packet.rollState.clientY;
			stream << ", stuff: [" << std::hex;
			for (int i = 0; i < 4; i++)
				stream << (i == 0 ? "" : ", ") << "0x" << static_cast<int>(packet.rollState.stuff[i]);
			stream << "]" << std::dec;
			break;
		case SOKUROLL_SETTINGS:
			stream << ", maxRollback: " << static_cast<int>(packet.rollSettings.maxRollback);
			stream << ", delay: " << static_cast<int>(packet.rollSettings.delay);
			break;
		case APM_START_SESSION_RESPONSE:
			stream << ", accepted: " << std::boolalpha << packet.apmResponse.accepted << std::noboolalpha;
			break;
		case APM_ELEM_UPDATED:
			break;
		}
	}

	std::string PacketTypeToString(PacketType e)
	{
		switch (e) {
		case HELLO:
			return "HELLO";
		case PUNCH:
			return "PUNCH";
		case OLLEH:
			return "OLLEH";
		case CHAIN:
			return "CHAIN";
		case INIT_REQUEST:
			return "INIT_REQUEST";
		case INIT_SUCCESS:
			return "INIT_SUCCESS";
		case INIT_ERROR:
			return "INIT_ERROR";
		case REDIRECT:
			return "REDIRECT";
		case QUIT:
			return "QUIT";
		case HOST_GAME:
			return "HOST_GAME";
		case CLIENT_GAME:
			return "CLIENT_GAME";
		case SOKUROLL_TIME:
			return "SOKUROLL_TIME";
		case SOKUROLL_TIME_ACK:
			return "SOKUROLL_TIME_ACK";
		case SOKUROLL_STATE:
			return "SOKUROLL_STATE";
		case SOKUROLL_SETTINGS:
			return "SOKUROLL_SETTINGS";
		case SOKUROLL_SETTINGS_ACK:
			return "SOKUROLL_SETTINGS_ACK";
		case APM_START_SESSION_REQUEST:
			return "APM_START_SESSION_REQUEST";
		case APM_START_SESSION_RESPONSE:
			return "APM_START_SESSION_RESPONSE";
		case APM_ELEM_UPDATED:
			return "APM_ELEM_UPDATED";
		case DESDET_MOD_ENABLE_REQUEST:
			return "DESDET_MOD_ENABLE_REQUEST";
		case DESDET_STATE:
			return "DESDET_STATE";
		case SOKU2_PLAY_REQU:
			return "SOKU2_PLAY_REQU";
		default:
			return "Unknown PacketType " + std::to_string(e);
		}
	}

	std::string RequestTypeToString(RequestType e)
	{
		switch (e) {
		case SPECTATE_REQU:
			return "SPECTATE_REQU";
		case PLAY_REQU:
			return "PLAY_REQU";
		default:
			return "Unknown RequestType " + std::to_string(e);
		}
	}

	std::string SceneIdToString(SceneId e)
	{
		switch (e) {
		case SCENEID_CHARACTER_SELECT:
			return "SCENE_CHARACTER_SELECT";
		case SCENEID_BATTLE:
			return "SCENE_BATTLE";
		default:
			return "Unknown SceneId " + std::to_string(e);
		}
	}

	std::string InitErrorsToString(InitErrors e)
	{
		switch (e) {
		case ERROR_SPECTATE_DISABLED:
			return "ERROR_SPECTATE_DISABLED";
		case ERROR_GAME_STATE_INVALID:
			return "ERROR_GAME_STATE_INVALID";
		default:
			return "Unknown InitErrors " + std::to_string(e);
		}
	}

	std::string GameTypeToString(GameType e)
	{
		switch (e) {
		case GAME_LOADED:
			return "GAME_LOADED";
		case GAME_LOADED_ACK:
			return "GAME_LOADED_ACK";
		case GAME_INPUT:
			return "GAME_INPUT";
		case GAME_MATCH:
			return "GAME_MATCH";
		case GAME_MATCH_ACK:
			return "GAME_MATCH_ACK";
		case GAME_MATCH_REQUEST:
			return "GAME_MATCH_REQUEST";
		case GAME_REPLAY:
			return "GAME_REPLAY";
		case GAME_REPLAY_REQUEST:
			return "GAME_REPLAY_REQUEST";
		default:
			return "Unknown GameType " + std::to_string(e);
		}
	}
}