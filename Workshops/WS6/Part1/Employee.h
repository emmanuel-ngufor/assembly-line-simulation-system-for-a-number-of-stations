#ifndef SENECA_EMPLOYEE_H 
#define SENECA_EMPLOYEE_H
#include <iostream>
#include <string>

#include "Person.h"

namespace seneca
{
    class Employee : public Person
    {
    private:
        std::string m_name{};
        std::string m_age{};
        std::string m_id{};

    public:
        Employee() = default;

        /*  A custom constructor that receives an object of type std::istream& as parameter.
        This constructor should be able to read a single record from the stream,
        extract all the information about a single Employee and store it in the attributes.
        Each record has the following format: TAG,NAME,AGE,EMPLOYEE ID */
        Employee(std::istream& is);

        std::string status() const;               // a query that returns the string Employee
        std::string name() const;                 // a query that returns the name of the employee
        std::string id() const;                   // a query that returns the id of the employee
        std::string age() const;                  // a query that returns the age of the employee

        // a query that inserts in the first parameter the content of the employee object 
        // in the format | "EMPLOYEE" | id | name | age |
        void display(std::ostream& out) const;
    };

} // namespace seneca

#endif    // !SENECA_EMPLOYEE_H