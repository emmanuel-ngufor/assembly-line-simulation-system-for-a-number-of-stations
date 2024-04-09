#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <utility>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace seneca
{
    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(const std::string& input)  
    { 
        Utilities utility; 
        size_t pos = 0;
        bool more = true;

        m_name = utility.extractToken(input, pos, more); 
        m_product = utility.extractToken(input, pos, more); 

        std::string listOfItems = ""; 
        size_t count = 0; 

        do 
        {
            std::string tmp = utility.extractToken(input, pos, more); 
            if (listOfItems.length() > 0)
            {
                listOfItems += Utilities::getDelimiter();
            }
            listOfItems += tmp; 
            count++;

        } while (more);

        m_lstItem = new Item * [count]; 
        m_cntItem = count; 
        pos = 0;
        count = 0;
        more = true;

        do 
        {
            std::string tmp = utility.extractToken(listOfItems, pos, more); 
            m_lstItem[count++] = new Item(tmp);

        } while (more);

        if (m_widthField < utility.getFieldWidth()) 
        {
            m_widthField = utility.getFieldWidth();
        }
    }

    CustomerOrder::CustomerOrder(const CustomerOrder& order)
    {
        throw std::string("Copy constructor cannot be called");  
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept 
    {
        *this = std::move(order); 
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept { 
        if (this == &order)
        {
            return *this;
        }

        std::swap(m_name, order.m_name);  
        std::swap(m_product, order.m_product); 
        std::swap(m_cntItem, order.m_cntItem);  
        std::swap(m_lstItem, order.m_lstItem);   

        return *this;
    }

    CustomerOrder::~CustomerOrder() 
    {
        for (size_t i = 0; i < m_cntItem; i++)  
        {
            delete m_lstItem[i];
        }

        delete[] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const 
    {
        size_t count = 0;

        for (size_t i = 0; i < m_cntItem; i++) 
        {
            if (m_lstItem[i]->m_isFilled)
            {
                count++;
            }
        }

        return count == m_cntItem;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const 
    {
        size_t itemCount = 0;
        size_t filledCount = 0;

        for (size_t i = 0; i < m_cntItem; i++) 
        {
            if (m_lstItem[i]->m_itemName == itemName) 
            {
                itemCount++;

                if (m_lstItem[i]->m_isFilled) 
                {
                    filledCount++;
                }
            }
        }

        return itemCount == filledCount;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os)
    {
        for (size_t i = 0; i < m_cntItem; i++) 
        {

            if (m_lstItem[i]->m_itemName == station.getItemName()) 
            {

                if (station.getQuantity() > 0)
                {
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true; 
                    station.updateQuantity();
                    os << std::setw(11) << std::right; 
                    os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                    break;

                }
                else 
                {
                    os << std::setw(11) << std::right; 
                    os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl; 
                    break;

                }
            }
        }


    }

    void CustomerOrder::display(std::ostream& os) const 
    {
        os << m_name << " - " << m_product << std::endl; 

        for (size_t i = 0; i < m_cntItem; i++) 
        {
            os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
            os << std::setfill(' ') << std::left;
            os << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - "; 
            os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED"); 
            os << std::endl; 
        }
    }


} // namespace seneca