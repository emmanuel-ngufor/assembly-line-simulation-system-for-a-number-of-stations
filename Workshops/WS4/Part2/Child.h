#pragma once
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace seneca
{
    class Child
    {
    private:
        Toy* m_toy{};                               // a dynamically allocated array of pointers of type Toy : each elem of arr -> Obj of type toy 
        size_t m_numToys{};
        std::string m_childName{};
        int m_age{}; 
        

    public:
        Child() = default;                          // Default constructor

        // Rule of 5(Five)
        Child(const Child& child);                  // Copy Constructor
        Child& operator=(const Child& child);       // Assignment Operator
        Child(Child&& child) noexcept;              // Move Constructor
        Child& operator=(Child&& child) noexcept;   // Move Assignment
        ~Child();                                   // Destructor


        // A constructor that receives as a parameter a name and an age, and an array of pointers to objects of type Toy 
        // (i.e., each element of the array is a pointer). this constructor should store copies of all toys
        Child(std::string name, int age, const Toy* toys[], size_t count);


        // a query that returns the number of toys stored in the array attribute.
        size_t size() const;

        // Helper operator
        friend std::ostream& operator<<(std::ostream& os, const Child& child);
    };

}  // namespace seneca

#endif  // ! SENECA_CHILD_H

