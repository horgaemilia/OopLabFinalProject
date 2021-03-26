#pragma once
#include "Exceptions.h"
#include <string>

class Validator
{
public:
	Validator() {};
	void check_for_digits(std::string& tocheck);
};