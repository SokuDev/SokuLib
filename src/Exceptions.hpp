//
// Created by Andgel on 02/12/2020.
//

#ifndef SOKULIB_EXCEPTIONS_HPP
#define SOKULIB_EXCEPTIONS_HPP


#include <exception>
#include <string>

namespace SokuLib
{
	class Exception : public std::exception {
	private:
		std::string _msg;

	public:
		explicit Exception(const std::string &&what) : _msg(what) {};
		const char *what() const noexcept override { return this->_msg.c_str(); };
	};

	class NotInMenuException : Exception {
	public:
		NotInMenuException() : Exception("Expected to be in a menu") {};
	};

	class InvalidMenuException : Exception {
	public:
		InvalidMenuException(const std::string &&current, const std::string &&expected) : Exception("Expected to be in " + expected + " but is actualy in " + current) {};
	};
}


#endif //SOKULIB_EXCEPTIONS_HPP
