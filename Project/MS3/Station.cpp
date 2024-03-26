#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace seneca
{
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station(const std::string& record)
    {
        Utilities utilities;
        size_t next_pos = 0;
        bool more = true;

        m_id = ++id_generator;
        m_name = utilities.extractToken(record, next_pos, more);
        m_nextSerialNum = stoi(utilities.extractToken(record, next_pos, more));
        m_numItems = stoi(utilities.extractToken(record, next_pos, more));
        m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
        m_description = utilities.extractToken(record, next_pos, more);
    }

    const std::string& Station::getItemName() const { return m_name; }

    size_t Station::getNextSerialNumber() { return m_nextSerialNum++; }

    size_t Station::getQuantity() const { return m_numItems; }

    void Station::updateQuantity()
    {
        if (m_numItems > 0)
        {
            m_numItems--;
        }
    }

    void Station::display(std::ostream& os, bool full) const
    {
        os << std::setw(3) << std::setfill('0') << m_id << " | ";
        os << std::left << std::setfill(' ') << std::setw(m_widthField) << m_name << " | ";
        os << std::right << std::setw(6) << std::setfill('0') << m_nextSerialNum << " | ";

        if (full)
        {
            os << std::setfill(' ');
            os << std::right;
            os << std::setw(4) << m_numItems << " | " << m_description;
        }

        os << std::endl;
    }

}  // namespace seneca