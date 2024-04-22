#define _CRT_SECURE_NO_WARNINGS 
#include "Child.h"

namespace seneca
{
    Child::Child(const Child& child) 
    {
        m_toy = nullptr;  
        *this = child;
    }

   
    Child& Child::operator=(const Child& child)
    {
        // Check for self assigment
        if (this != &child)
        {
            // Shallow copy non-resource instance data members
            m_numToys = child.m_numToys;
            m_childName = child.m_childName;
            m_age = child.m_age;

            // deallocate existing memory
            delete[] m_toy;

           
            // Deep copy resource instance data member
            m_toy = new Toy[m_numToys];              // Allocate new memory for deep copy

            for (size_t i = 0; i < m_numToys; i++) 
            {
                m_toy[i] = child.m_toy[i]; 
            }

        }

        return *this;
      
    }

    Child::Child(Child&& child) noexcept 
    {
        m_toy = nullptr;  
        *this = std::move(child);
    }

    Child& Child::operator=(Child&& child) noexcept
    {
        if (this != &child)
        {
            // Shallow move non-resource instance variables
            m_numToys = child.m_numToys;
            m_childName = child.m_childName;
            m_age = child.m_age;

            // Release existing memory
            delete[] m_toy; 
            m_toy = child.m_toy;  // move current resource

            // free other resources
            child.m_toy = nullptr; 
            child.m_numToys = 0;
            child.m_childName = "";
            child.m_age = 0;

        }

        return *this;
    }

    Child::~Child()
    {
        if (m_toy != nullptr)
        {
            delete[] m_toy; 
            m_toy = nullptr;
        }
    }

    Child::Child(std::string name, int age, const Toy* toys[], size_t count)
    {
        // Shallow copy non-resource instance variables
        m_childName = name;
        m_numToys = count; 
        m_age = age; 

        // Allocate memory for the array of pointers : resource instance variable
        m_toy = new Toy[count];
       
        // Deep copy resource instance variable
        for (size_t i = 0; i < count; i++) 
        {
            m_toy[i] = *toys[i];
        }

    }

    size_t Child::size() const { return m_numToys; }

    std::ostream& operator<<(std::ostream& ostr, const Child& child) 
    {
        static size_t CALL_CNT;  // function variable to count how many times this operator has been called 
        ++CALL_CNT;              // incremented each time the operator overload function is called

        ostr << "--------------------------\n"
            << "Child " << CALL_CNT << ": " << child.m_childName << " " << child.m_age << " years old:" << "\n";
        ostr << "--------------------------\n";

        if (child.m_numToys == 0) 
        {
            ostr << "This child has no toys!" << "\n";
        }
        else
        {
            for (size_t i = 0; i < child.m_numToys; i++) 
            {
                ostr << child.m_toy[i]; 
            }
        }
        ostr << "--------------------------\n";

        return ostr;
    }

}  // namespace seneca