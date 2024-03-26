#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"



namespace seneca 
{
    extern std::deque<seneca::CustomerOrder> g_pending;
    extern std::deque<seneca::CustomerOrder> g_completed;
    extern std::deque<seneca::CustomerOrder> g_incomplete;

    class Workstation : public Station 
    {
        std::deque<CustomerOrder> m_orders{};
        Workstation* m_pNextStation = nullptr;

    public:
        Workstation() = default;
        Workstation(const std::string& data);
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const; 
        Workstation& operator+=(CustomerOrder&& newOrder);
        bool empty() const;
    };

};  // namespace seneca

#endif  // !SENECA_WORKSTATION_H