#pragma once
#ifndef SENECA_SET_H
#define SENECA_SET_H
#include <iostream>
#include <cmath>
#include "Pair.h"
#include "Collection.h"
#include <string>

namespace seneca
{
    template<class T>
    class Set : public Collection<T, 100>
    {
        const size_t CAPACITY = 100; 

    public:

        Set() { ; }

        // override the inherited function add to prevent adding an item if it already exists in the Set.
        bool add(const T& item) 
        {

            for (auto i = 0; (unsigned)i < this->m_numElements; i++)  
            {
                if (item == this->m_array[i]) 
                {
                    return false;
                }
            }

            return Collection<T, 100>::add(item);   
        }

    };

    // Specializations

    /* for T = double, the function add() should consider that two numbers are the same if their difference
    in the absolute value is smaller or equal to 0.01. 
    When implementing this specialization, consider the function std::fabs(). */
    template<>
    bool Set<double>::add(const double& item) 
    {
        for (auto i = 0; (unsigned)i < this->m_numElements; i++)  
        {
            if (std::fabs(item - this->m_array[i]) <= 0.01) 
            {
                return false;
            }
        }

        return Collection<double, 100>::add(item);
    };

}   // namespace seneca


#endif  // ! SENECA_SET_H
