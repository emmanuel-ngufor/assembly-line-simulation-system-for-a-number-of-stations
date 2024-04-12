#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>

#include "Employee.h"
#include "Utilities.h"


namespace seneca 
{
	Person* buildInstance(std::istream& in) 
	{
		std::string line{};
		std::stringstream tempVar{};
		Person* personPtr{};
		getline(in, line, '\n');
		tempVar << line;
		if (line[0] == 'e' || line[0] == 'E')
		{
			personPtr = new Employee(tempVar);
		}
		else
		{
			personPtr = nullptr;
		}

		return personPtr;
	}

	bool isDigit(std::string& src) {
		auto begin = src.begin();
		while (begin != src.end() && std::isdigit(*begin)) {
			++begin;
		}
		return !src.empty() && begin == src.end();
	}

	std::string& trim(std::string& src) {
		bool valid = false;

		while (!valid)
		{
			if (src[0] == ' ')
			{
				src.erase(0, src.find_first_not_of(' '));
			}
			else if (src[src.length() - 1] == ' ')
			{
				src.erase(src.find_last_not_of(' ') + 1);
			}
			else
			{
				valid = true;
			}
		}
		return src;
	}

} // namespace seneca

