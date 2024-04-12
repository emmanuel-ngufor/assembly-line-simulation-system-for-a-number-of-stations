#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Professor.h"
#include "Employee.h"
#include "Utilities.h"

namespace seneca 
{
	Professor::Professor(std::istream& in) : Employee(in) 
	{
		std::string department = "";
		getline(in, department, ',');
		m_department = trim(department);
	}

	void Professor::display(std::ostream& out) const 
	{
		Employee::display(out);
		out << m_department << "| Professor";
	}

	std::string Professor::status() const { return "Professor"; }
	

	std::string Professor::department() const { return m_department; }  
	

}  // namespace seneca