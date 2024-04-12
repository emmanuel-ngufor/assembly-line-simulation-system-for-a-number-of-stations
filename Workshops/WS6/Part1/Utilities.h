
// NB*: This module should contain a single function that creates instances on the Person hierarchy:

#ifndef SENECA_UTILITES_H
#define SENECA_UTITLITIES_H

#include "Person.h"

namespace seneca 
{

	/*
	This function should extract data from the parameter; if the first non-blank character is e or E,
	then this function should dynamically create an instance of type Employee passing the stream to the constructor,
	and return it to the client.
	If the first non-blank character is anything else (or there are no more characters to extract),
	this function should return nullptr.
	Because the input file contains two types of delimiters (\n for records, and , for the fields in a record),
	you can use the class std::stringstream (utilization of this class is not mandatory,
	the extraction can be achieved without using it).
	When implementing the buildInstance function, consider the following STL class: std::stringstream
	*/
	Person* buildInstance(std::istream& in);
	bool isDigit(std::string& src);
	std::string& trim(std::string& src);
}

#endif // !SENECA_UTILITES_H
