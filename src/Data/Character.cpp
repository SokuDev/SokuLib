//
// Created by Gegel85 on 04/11/2020.
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
		"Reisen Undongein Inaba",
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
	};

	// �L�����N�^ID
	// int
	Character &leftChar = *reinterpret_cast<Character *>(ADDR_LCHARID);
	Character &rightChar =  *reinterpret_cast<Character *>(ADDR_RCHARID);
}