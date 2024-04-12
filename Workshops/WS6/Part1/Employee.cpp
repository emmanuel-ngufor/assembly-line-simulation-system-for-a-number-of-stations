#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "Employee.h"
#include "Utilities.h"
namespace seneca
{
	Employee::Employee(std::istream& istr) {
		std::string tag, age, temp;
		getline(istr, tag, ',');
		getline(istr, m_name, ',');
		trim(m_name);
		// Store value to a temporary string "age", use a function to check if the string is a digit or else throws error.
		getline(istr, age, ',');
		if (isDigit(age)) m_age = age;
		else {
			std::string e = m_name + "++Invalid record!\n";
			throw(e);
		}
		getline(istr, m_id);
		trim(m_id);
		//std::cout << m_id[1];
		if (m_id[0] == 'e' || m_id[0] == 'E')
		{
			m_id = m_id.erase(m_id.find_last_not_of(" ") + 1);
		}
		else
		{
			std::string e = m_name + "++Invalid record!\n";
			throw(e);
		}
	}

	std::string Employee::status() const {	return std::string("Employee");	}
	std::string Employee::name() const { return m_name; }
	std::string Employee::id() const { 	return m_id; }
	std::string Employee::age() const { return m_age; }

	void Employee::display(std::ostream& out) const 
	{
		out << "| " << std::left << std::setw(10) << "Employee"
			<< "| " << std::setw(10) << m_id 
			<< "| " << std::setw(20) << m_name 
			<< " | " << std::setw(3) << m_age << " |";
	}
}