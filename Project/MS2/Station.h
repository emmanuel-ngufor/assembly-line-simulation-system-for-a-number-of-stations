#pragma once
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <string>

namespace seneca
{
    class Station
    {
    private:
        std::string m_name{};
        std::string m_description{};
        int m_id{};
        unsigned int m_nextSerialNum{};
        unsigned int m_numItems{};

        // class variables
        static size_t m_widthField;
        static int id_generator;

    public:
        Station() = default;
        Station(const std::string& record);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;

    };

}  // namespace seneca

#endif  // !SENECA_STATION_H

