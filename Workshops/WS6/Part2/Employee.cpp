#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "Utilities.h"
namespace seneca {
    Employee::Employee(std::istream& istr)
    {
        std::string name = "";
        getline(istr, name, ',');
        m_name = trim(name);
        std::string age = "";
        getline(istr, age, ',');
        trim(age);
        try
        {
            m_age = std::to_string(stoi(age));
        }
        catch (...)
        {
            throw m_name + "++Invalid record!\n";
        }

        std::string tempId = "";
        getline(istr, tempId, ',');
        tempId = trim(tempId);
        if (tempId[0] == 'E')
        {
            m_id = tempId;
        }
        else
        {
            throw m_name + "++Invalid record!\n";
        }
    }

   
    std::string Employee::status() const { return "Employee"; }

    std::string Employee::name() const { return m_name; }

    std::string Employee::id() const { return m_id; }

    std::string Employee::age() const { return m_age; }

    void Employee::display(std::ostream& out) const 
    {
        out << "| " << std::left << std::setw(10) << "Employee" 
            << "| " << std::setw(10) << m_id 
            << "| " << std::setw(20) << m_name 
           << " | " << std::setw(3) << m_age << " |";
    }

} // namespace seneca