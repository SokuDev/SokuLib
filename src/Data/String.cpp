//
// Created by Gegel85 on 04/11/2020.
//

#include "String.hpp"

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
}