//
// Created by PinkySmile on 04/11/2020.
//

#include <algorithm>
#include "String.hpp"
#include "Memory.hpp"
#include "UnionCast.hpp"
#include "SokuAddresses.hpp"

namespace SokuLib
{
	String::operator char *()
	{
		if (this->BUF_SIZE <= this->res)
			return this->body.ptr;
		return this->body.buf;
	}

	String::operator const char *() const
	{
		if (this->BUF_SIZE <= this->res)
			return this->body.ptr;
		return this->body.buf;
	}

	char& String::operator [](int i)
	{
		if (this->BUF_SIZE <= this->res)
			return this->body.ptr[i];
		return this->body.buf[i];
	}

	String &String::operator=(const std::string &str)
	{
		auto newSize = std::max(str.size() + 1, this->res);

		if (newSize <= this->BUF_SIZE)
			strcpy(this->body.buf, str.c_str());
		else if (newSize <= this->res)
			strcpy(this->body.ptr, str.c_str());
		else {
			auto buffer = SokuLib::New<char>(newSize);
			auto oldBuffer = this->body.ptr;

			strcpy(buffer, str.c_str());
			this->body.ptr = buffer;
			if (this->res > this->BUF_SIZE)
				SokuLib::Delete(oldBuffer);
		}

		this->res = newSize;
		this->size = str.size();
		return *this;
	}

	String &String::operator=(const String &str)
	{
		return this->assign(str, 0, -1);
	}

	String &String::operator=(const char *str)
	{
		return this->assign(str, -1);
	}

	bool String::operator<(const String &str) const {
		return strcmp(*this, str) < 0;
	}

	String::operator std::string() const
	{
		const char *str = *this;

		return {str, str + this->size};
	}

	String::String()
	{
		this->body.buf[0] = 0;
		this->size = 0;
		this->res = BUF_SIZE - 1;
	}

	String::String(const String &str)
	{
		this->size = 0;
		this->res = BUF_SIZE - 1;
		this->assign(str, 0, -1);
	}

	String::~String()
	{
		this->clear();
	}

	String &String::assign(const String &str, int offset, int len)
	{
		return (this->*union_cast<String&(String::*)(const String &, int, int)>(ADDR_STRING_ASSIGN_STRING))(str, offset, len);
	}

	String &String::assign(const char *str, int len)
	{
		return (this->*union_cast<String&(String::*)(const char *, int)>(ADDR_STRING_ASSIGN_CSTR))(str, len == -1 ? strlen(str) : len);
	}

	void String::clear()
	{
		if (this->BUF_SIZE <= this->res)
			SokuLib::Delete(this->body.ptr);
		this->body.buf[0] = 0;
		this->size = 0;
		this->res = BUF_SIZE - 1;
	}

	String &String::erase(int offset, int len)
	{
		return (this->*union_cast<String&(String::*)(int, int)>(ADDR_STRING_ERASE))(offset, len == -1 ? this->size - offset : len);
	}

	void String::resize(int size)
	{
		return (this->*union_cast<void(String::*)(int, int)>(ADDR_STRING_RESIZE))(size, this->size);
	}

	String &String::append(const char *str, int len)
	{
		return (this->*union_cast<String&(String::*)(const char *, int)>(ADDR_STRING_APPEND))(str, len == -1 ? strlen(str) : len);
	}
}