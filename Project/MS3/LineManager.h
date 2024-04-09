#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Workstation.h"


namespace seneca
{
    class LineManager 
    {
        std::vector<Workstation*> m_Active_Line{};
        size_t m_cntCustomerOrder{};
        Workstation* m_First_Station{};

    public:
        LineManager() = default;
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void reorderStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
};

#endif  // !SENECA_LINE_MANAGER_H