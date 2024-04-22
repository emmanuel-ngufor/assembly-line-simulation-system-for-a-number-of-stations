#pragma once
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

#include "Toy.h"

namespace seneca
{
    class ConfirmOrder
    {
    private:
        const Toy** m_toy{ nullptr };                           //  a dynamically-allocated array of pointers to objects of type
        size_t m_itemCount{ 0 };

    public:
        ConfirmOrder() = default;                               // Default Constructor

        // Rule of Five(5)
        ~ConfirmOrder();                                        // Destructor
        ConfirmOrder& operator=(const ConfirmOrder& order);     // Copy Assignment Operator
        ConfirmOrder(const ConfirmOrder& order);                // Copy Constructor
        ConfirmOrder& operator=(ConfirmOrder&& order)noexcept;  // Move Assignment Operator
        ConfirmOrder(ConfirmOrder&& order)noexcept;             // Move Constructor

        /* adds the toy toy to the array by adding its address.
         - if the address of toy is already in the array, this operator does nothing
         - resizes the array to make room for toy if necessary
         - stores the address of toy in the array (your function should not make copies of the toy itself) */
        ConfirmOrder& operator+=(const Toy& toy);

        /* removes the toy toy from the array by removing its address
         - if the address of toy is not in the array, this operator does nothing
         - searches the array for the address of toy, sets the pointer in the array to nullptr if toy is found.
         - To challenge yourself, try to actually resize the array. */
        ConfirmOrder& operator-=(const Toy& toy);

        // overload the insertion operator to insert the content of a ConfirmOrder object into an ostream object
        friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& order); 
    };


}  // namespace seneca

#endif  // ! SENECA_CONFIRMORDER_H



/*
Notes
 Very Important: This class is responsible for managing the array of pointers but is not managing the life of Toy objects.
*/


