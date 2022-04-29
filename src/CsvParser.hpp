//
// Created by PinkySmile on 14/06/2021.
//

#ifndef SOKULIB_CSVPARSER_HPP
#define SOKULIB_CSVPARSER_HPP


#include <string>
#include "Map.hpp"
#include "String.hpp"

namespace SokuLib
{
	class CSVParser {
	private:
		struct DequeIterator {
			int debugData;
			void* containerPtr;
			int offset;
		};

		Deque<Deque<String>> data;
		DequeIterator upperIterator;
		DequeIterator lowerIterator;
		bool isInComment;
		bool isInQuotes;

	public:
		CSVParser(const char *path);
		~CSVParser();
		std::string getNextCell();
		long getNextValue();
		void goToStart();
		bool goToNextLine();
	};
}


#endif //SOKULIB_CSVPARSER_HPP
