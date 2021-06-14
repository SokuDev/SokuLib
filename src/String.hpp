//
// Created by Gegel85 on 04/11/2020.
//

#ifndef SOKULIB_STRING_HPP
#define SOKULIB_STRING_HPP


#include <string>

namespace SokuLib
{
	#pragma pack(push, 4)
	// std::string ?
	struct String {
		enum { BUF_SIZE = 16 };

		void *alloc;
		union {
			char  buf[16];
			char* ptr;
		} body;
		size_t size;
		size_t res;

		String();
		operator char *();
		operator const char *() const;
		operator std::string() const;
		String &operator=(const std::string &str);
	};
	#pragma pack(pop)
}


#endif //SOKULIB_STRING_HPP
