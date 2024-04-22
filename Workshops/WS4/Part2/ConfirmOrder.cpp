#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "ConfirmOrder.h"

namespace seneca
{
    ConfirmOrder::~ConfirmOrder()
    {
        delete[] m_toy;
        m_toy = nullptr;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& order) 
    {
        // Check for self assignment
        if (this != &order)
        {
            // Shallow copy non-resource instance data members
            m_itemCount = order.m_itemCount;

            // Release existing memory
            delete[] m_toy;

            // Deep copy resource instance data members
            m_toy = new const Toy * [m_itemCount];     // dynamically allocate new memory

            for (size_t i = 0; i < m_itemCount; i++) 
            {
                m_toy[i] = order.m_toy[i]; 
            }

        }

        return *this;
    }

    ConfirmOrder::ConfirmOrder(const ConfirmOrder& order)
    {
        m_toy = nullptr; 
        *this = order;
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& order)noexcept
    {
        // Check for self assignment
        if (this != &order)
        {
            // Shallow move non-resource instance data members
            m_itemCount = order.m_itemCount;

            // Release existing memory
            delete[] m_toy;
            // move current resource
            m_toy = order.m_toy;  

            // Free other resources
            order.m_toy = nullptr;
            order.m_itemCount = 0;
        }

        return *this;
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& order)noexcept
    {
        m_toy = nullptr; 
        *this = std::move(order);
    }

    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) 
    {
        bool inArray = false; 

        for (size_t i = 0; i < m_itemCount; i++)
        {  
            if (m_toy[i] == &toy)  
            {
                inArray = true; 
            }
        }

        if (!inArray) 
        {
            const Toy** temp = nullptr; 
            temp = new const Toy * [m_itemCount + 1];

            for (size_t i = 0; i < m_itemCount; i++)
            {
                temp[i] = m_toy[i];
            }

            temp[m_itemCount] = &toy;
            m_itemCount++;
            delete[] m_toy; 
            m_toy = temp; 
        }

        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) 
    {
        bool inArray = false;

        for (size_t i = 0; i < m_itemCount; i++)
        {
            if (m_toy[i] == &toy)  
            {
                inArray = true; 
            }
        }

        if (inArray)
        {

            for (size_t i = 0; i < m_itemCount; i++)
            {
                if (m_toy[i] == &toy)
                {
                    m_toy[i] = nullptr;
                }
            }

            m_itemCount--;
        }

        return *this;
    }

    std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& order)
    {
        ostr << "--------------------------" << "\n";
        ostr << "Confirmations to Send" << "\n";
        ostr << "--------------------------" << "\n";
        if (order.m_itemCount == 0)
        {
            ostr << "There are no confirmations to send!\n";
        }
        else 
        {
            for (size_t i = 0; i < order.m_itemCount; i++)
            {
                if (order.m_toy[i] != nullptr) 
                {
                    ostr << *order.m_toy[i];
                }
            }
        }
        ostr << "--------------------------\n";

        return ostr;
    }


}  // namespace seneca

