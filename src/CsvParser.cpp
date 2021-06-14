//
// Created by PinkySmile on 14/06/2021.
//

#include "CsvParser.hpp"
#include "String.hpp"

namespace SokuLib
{
	SokuLib::String buffer;

	auto FUN_0040f370 = reinterpret_cast<void (__thiscall *)(void *, const char *csvFile)>(0x0040f370);
	auto csvParseString = reinterpret_cast<void (__thiscall *)(void *, SokuLib::String &output)>(0x0040f7a0);
	auto FUN_0040f8a0 = reinterpret_cast<bool (__thiscall *)(void *)>(0x0040f8a0);

	CSVParser::CSVParser(const char *path)
	{
		memset(this, 0, sizeof(*this));
		FUN_0040f370(this, path);
	}

	std::string CSVParser::getNextCell()
	{
		csvParseString(this, buffer);
		return buffer;
	}

	bool CSVParser::goToNextLine()
	{
		return FUN_0040f8a0(this);
	}
}