#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "event.h"

namespace seneca 
{
    size_t g_sysClock{}; 
    size_t Event::counter = 0;

    // Event::Event() {} - Already defined in the class instatiation

    void Event::display() 
    {
        // Increment the counter each time the function is called
        counter++;

        std::cout << std::setw(2) << counter << ". ";

        if (m_description[0] == '\0') 
        {
            std::cout << "| No Event |";
        }
        else 
        {
            std::cout << formatTime(m_startTime) << " => " << m_description;
        }

        std::cout << "\n";
    }

    void Event::set(const char* desc) 
    {
        // Check if the address is not null and the array is not empty
        if (desc && *desc)
        {
            // Start a new event
            m_startTime = g_sysClock; 
            strncpy(m_description, desc, sizeof(m_description) - 1); 
            m_description[sizeof(m_description) - 1] = '\0'; 
        }
        else 
        {
            // Reset the current instance to an empty state
            // description[0] = '\0';
            // startTime = 0;
            *this = Event(); // - Evaluates tto default as above
        }
    }

    std::string Event::formatTime(size_t timeInSeconds) 
    {
        size_t hours = timeInSeconds / 3600;
        size_t minutes = (timeInSeconds % 3600) / 60;
        size_t seconds = timeInSeconds % 60;

        std::ostringstream oss{};
        oss << std::setw(2) << std::setfill('0') << hours   << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds;

        return oss.str();
    }

}  // namespace seneca
