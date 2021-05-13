//
// Created by Gegel85 on 04/11/2020.
//

#include <algorithm>
#include "String.hpp"
#include "Memory.hpp"

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
}