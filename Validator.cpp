#include "Validator.h"

using namespace std;

void Validator::check_for_digits(std::string& tocheck)
{
	int i;
	for (i = 0;i < strlen(const_cast<char*>(tocheck.c_str()));i++)
		if (isalpha(tocheck[i]))
			throw ValidatorException("it must be a number");
}
