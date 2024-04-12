#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>

#include "College.h"

namespace seneca {
    College::~College()
    {
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
        {
            delete (*it);
        }
    }

    College& College::operator+=(Person* thePerson)
    {
        m_persons.push_back(thePerson);
        return *this;
    }

    void College::display(std::ostream& out) const
    {
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
        {
            (*it)->display(out);
            std::cout << std::endl;
        }

        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "|                                        Test #2 Persons in the college!                                               |" << std::endl;
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
        {
            std::cout.setf(std::ios::left);
            std::cout << "| ";
            std::cout.width(10);
            std::cout << (*it)->status();
            std::cout << "| ";
            std::cout.width(10);
            std::cout << (*it)->id();
            std::cout << "| ";
            std::cout.width(20);
            std::cout << (*it)->name();
            std::cout << " | ";
            std::cout.width(3);
            std::cout << (*it)->age();
            std::cout << " |" << std::endl;
        }
        std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    }

}  // namespace seneca