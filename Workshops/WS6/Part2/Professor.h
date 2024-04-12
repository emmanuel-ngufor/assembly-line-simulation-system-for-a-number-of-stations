#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include <iostream>
#include <string>

#include "Employee.h"

namespace seneca 
{
	class Professor :public Employee 
	{
		std::string m_department{};
	public:
		Professor(std::istream& in);
		void display(std::ostream& out) const;
		std::string status() const;
		std::string department() const;
	};
}
#endif // !SENECA_PROFESSOR_H
