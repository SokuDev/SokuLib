//
// Created by PinkySmile on 14/06/2021.
//

#ifndef SOKULIB_CSVPARSER_HPP
#define SOKULIB_CSVPARSER_HPP


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


#endif //SOKULIB_CSVPARSER_HPP
