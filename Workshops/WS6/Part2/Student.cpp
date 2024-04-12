#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"
#include "Utilities.h"
namespace seneca {

    Student::Student(std::istream& istr) 
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
        if (tempId[0] == 'S')
        {
            m_id = tempId;
        }
        else
        {
            throw m_name + "++Invalid record!\n";
        }

        std::string tempNum = "";
        getline(istr, tempNum, ',');
        m_count = std::stoi(trim(tempNum));
        m_courses = new std::string[m_count];

        for (size_t i = 0; i < m_count; i++)
        {
            std::string tempCourse = "";
            getline(istr, tempCourse, ',');
            m_courses[i] = trim(tempCourse);
        }
    }
    std::string Student::status() const { return "Student";  }

    std::string Student::name() const {  return m_name; }

    std::string Student::age() const { return m_age;  }

    std::string Student::id() const {  return m_id; }

    void Student::display(std::ostream& out) const 
    {
        out << "| " << std::left << std::setw(10) << "Student";
        out << "| " << std::left << std::setw(10) << m_id;
        out << "| " << std::left << std::setw(20) << m_name;
        out << " | " << std::left << std::setw(3) << m_age;
        out << " |";

        for (size_t i = 0; i < m_count; i++)
        {
            if (i != m_count - 1)
            {
                out << m_courses[i] << ", ";
            }
            else
            {
                out << m_courses[i];
            }
        }
    }

    Student::~Student() 
    {
        delete[] m_courses;
    }

}  // namespace seneca