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
		else if (newSize <= this->res) {
			auto buffer = SokuLib::New<char>(newSize);
			auto oldBuffer = this->body.ptr;

			strcpy(buffer, str.c_str());
			this->body.ptr = buffer;
			SokuLib::Delete(oldBuffer);
		} else
			strcpy(this->body.ptr, str.c_str());

		this->res = newSize;
		this->size = str.size();
		return *this;
	}

	String::operator std::string() const
	{
		const char *str = *this;

		return {str, str + this->size};
	}

	String::String()
	{
		memset(this, 0, sizeof(*this));
	}
}