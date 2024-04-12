 // NB*: This module should contain a single function that creates instances on the Person hierarchy:

#ifndef SENECA_UTILITES_H
#define SENECA_UTITLITIES_H
#include "Person.h"

namespace seneca 
{
	Person* buildInstance(std::istream& in);
	bool isDigit(std::string& src);
	std::string& trim(std::string& src);
}
#endif // !SENECA_UTILITES_H
