#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>

#include "Employee.h"
#include "Utilities.h"
#include "Student.h"
#include "Professor.h"

namespace seneca {
	Person* buildInstance(std::istream& in) 
	{
		std::string str = "";
		char type = '\0';
		char comma = '\0';

		getline(in, str);
		str.erase(0, str.find_first_not_of(' '));

		std::stringstream strs;
		strs << str;
		strs >> type >> comma;

		if (strs)
		{
			if (type == 'e' || type == 'E')
			{
				return new Employee(strs);
			}
			else if (type == 's' || type == 'S')
			{
				return new Student(strs);
			}
			else if (type == 'p' || type == 'P')
			{
				return new Professor(strs);
			}
		}

		return nullptr;
	}

	bool isDigit(std::string& src) 
	{
		auto begin = src.begin();
		while (begin != src.end() && std::isdigit(*begin))
		{
			++begin;
		}
		return !src.empty() && begin == src.end();
	}

	std::string& trim(std::string& src)
	{
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

}

