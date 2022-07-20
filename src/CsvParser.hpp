//
// Created by PinkySmile on 14/06/2021.
//

#ifndef SOKULIB_CSVPARSER_HPP
#define SOKULIB_CSVPARSER_HPP


#include <string>
#include "Deque.hpp"
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

	public:
		Deque<Deque<String>> data;
		DequeIterator upperIterator;
		DequeIterator lowerIterator;
		bool isInComment;
		bool isInQuotes;

		CSVParser(const char *path);
		~CSVParser();
		std::string getNextCell();
		void getNextCell(SokuLib::String& output);
		long getNextValue();
		void goToStart();
		bool goToNextLine();
	};
}


#endif //SOKULIB_CSVPARSER_HPP
