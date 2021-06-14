//
// Created by PinkySmile on 14/06/2021.
//

#ifndef SWRSTOYS_CSVPARSER_HPP
#define SWRSTOYS_CSVPARSER_HPP


#include <string>

namespace SokuLib
{
	class CSVParser {
	private:
		char data[0x1000];

	public:
		CSVParser(const char *path);
		std::string getNextCell();
		bool goToNextLine();
	};
}


#endif //SWRSTOYS_CSVPARSER_HPP
