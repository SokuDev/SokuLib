//
// Created by PinkySmile on 04/11/2020.
//

#include "Character.hpp"

namespace SokuLib
{
	std::vector<std::string> charactersName{
		"Reimu Hakurei",
		"Marisa Kirisame",
		"Sakuya Izayoi",
		"Alice Margatroid",
		"Patchouli Knowledge",
		"Youmu Konpaku",
		"Remilia Scarlet",
		"Yuyuko Saigyouji",
		"Yukari Yakumo",
		"Suika Ibuki",
		"Reisen Udongein Inaba",
		"Aya Shameimaru",
		"Komachi Onozuka",
		"Iku Nagae",
		"Tenshi Hinanawi",
		"Sanae Kochiya",
		"Cirno",
		"Hong Meiling",
		"Utsuho Reiuji",
		"Suwako Moriya",
		"Random Select",
		"Namazu",
		//Soku2 Characters
		"Momiji Inubashiri",
		"Clownpiece",
		"Flandre Scarlet",
		"Rin Kaenbyou",
		"Yuuka Kazami",
		"Kaguya Houraisan",
		"Fujiwara no Mokou",
		"Mima",
		"Shou Tormaru",
		"Minamitsu Murasa",
		"Sekibanki",
		"Satori Komeiji",
		"Ran Yakumo",
		"Tewi Inaba"
	};

	// �L�����N�^ID
	// int
	GameStartParams &gameParams = *reinterpret_cast<GameStartParams *>(ADDR_GAME_PARAMS);
	Character &leftChar  = *reinterpret_cast<Character *>(ADDR_LCHARID);
	Character &rightChar = *reinterpret_cast<Character *>(ADDR_RCHARID);
	PlayerInfo &leftPlayerInfo  = *reinterpret_cast<PlayerInfo *>(ADDR_LCHARID);
	PlayerInfo &rightPlayerInfo = *reinterpret_cast<PlayerInfo *>(ADDR_RCHARID);

	char *(* const getCharName)(unsigned) = *(char *(*)(unsigned))0x43F3F0;
}