#include "Exceptions.h"

const char* RepoException::what() const noexcept
{
	return this->message.c_str();
}

const char* ValidatorException::what() const noexcept
{
	return this->message.c_str();
}
