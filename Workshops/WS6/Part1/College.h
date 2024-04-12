#ifndef SENECA_COLLEGE_H 
#define SENECA_COLLEGE_H
#include <vector>
#include <list>

#include "Person.h"

namespace seneca
{
    class College
    {
    private:
        // A vector that store all the persons present at this college. 
        // All these Person objects will be dynamically allocated; this class should manage them.
        std::vector<Person*> m_persons{};

    public:
        College() = default;

        ~College(); 

        // The College should have the copy operations disabled
        College(const College&) = delete; 
        College& operator=(const College&) = delete;  

        // adds the address of the person object received as parameter into the m_persons vector.
        College& operator +=(Person* thePerson);

        // iterates over the persons stored in m_persons and prints their details using the following format 
        // (one person per line, see the sample output for formatting details).
        // Use Person::display() for the first test, and use the other public functions for the second test. 
        // To iterate over the elements of the vector, use STL iterators!
        //First Test
        void display(std::ostream& out) const;


        //Second test
        template <typename T>
        void Test(const T& test, std::list<const Person*>& persons)
        {
            for (auto i = m_persons.begin(); i != m_persons.end(); i++)
            {
                if (test(*i))
                {
                    persons.push_back(*i);
                }
            }
        }

    };

} // namespace seneca

#endif    // !SENECA_COLLEGE_H



