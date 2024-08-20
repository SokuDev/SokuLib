//
// Created by PinkySmile on 04/11/2020.
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
		String(const String &str);
		~String();
		operator char *();
		operator const char *() const;
		operator std::string() const;
		char &operator[](int i);
		String &operator=(const std::string &str);
		String &operator=(const String &str);
		String &operator=(const char *str);
		bool operator<(const String &str) const;

		String &assign(const String &str, int offset = 0, int size = -1);
		String &assign(const char *str, int size = -1);
		void clear();
		String &erase(int offset = 0, int len = -1);
		void resize(int size);
		String &append(const char *str, int len = -1);
	};
	#pragma pack(pop)
}


#endif //SOKULIB_STRING_HPP
