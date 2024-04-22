#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include "event.h"

namespace seneca 
{
    // Initializing variables
    size_t g_sysClock{};
    size_t Event::counter = 0;

    // Default constructor
    // Event::Event() : m_description(nullptr), m_startTime(0) {}

    // Constructor with description
    Event::Event(const char* desc)
    {
        set(desc);
    }

    // Destructor
    Event::~Event() 
    {
        delete[] m_description;
        m_description = nullptr;
    }

    // Copy constructor
    Event::Event(const Event& other)
    {
        // Reusing copy assignment operator
        *this = other;  
    }

    // Copy assignment operator
    Event& Event::operator=(const Event& other) 
    {
        // 1. check for self-assignment
        if (this != &other) 
        {
            // 2. clean-up the resource used by the current instance
            delete[] m_description;   // Release existing memory

            // 3. shallow copy non-resource instance variables
            m_startTime = other.m_startTime;

            // Check for nullidity of the other resourceinstance variable

            if (other.m_description) // same as if(other.m_description != nullptr)
            {
                // 4.Deep copy resource instance instance variables
                m_description = new char[strlen(other.m_description) + 1];
                strcpy(m_description, other.m_description);
            }
            else 
            {
                m_description = nullptr;
            }
        }
        return *this;
    }

    // Move constructor
    Event::Event(Event&& other) noexcept
    {
        // Reusing  move assignment operator
        *this = std::move(other);  
    }

    // Move assignment operator
    Event& Event::operator=(Event&& other) noexcept  
    {
        // 1. check for self-assignment
        if (this != &other) 
        {
            // 2. clean-up the resource used by the current instance
            delete[] m_description;  // Release existing memory

            // 3. shallow copy
            m_startTime = other.m_startTime;

            // 4. move the resource from parameter into current instance
            m_description = other.m_description; 
            
            // Empty the parameters because they have been moved
            other.m_startTime = 0;
            other.m_description = nullptr;   // the parameter doesn't have the resource anymore
        }
        return *this;
    }
     
    // Display function
    void Event::display() const 
    {
        counter++;

        std::cout << std::setw(2) << counter << ". ";

        if (!m_description || m_description[0] == '\0') 
        {
            std::cout << "| No Event |";
        }
        else
        {
            std::cout << formatTime(m_startTime) << " => " << m_description;
        }

        std::cout << "\n";
    }

    // Modifier function to set the event
    void Event::set(const char* desc) 
    {
        // Release existing memory
        delete[] m_description;  

        if (desc && *desc)
        {
            m_startTime = g_sysClock;
            m_description = new char[strlen(desc) + 1];
            strcpy(m_description, desc);
        }
        else 
        {
            m_startTime = 0;
            m_description = nullptr;
        }
    }

    // Helper function to format time as HH:MM:SS
    std::string Event::formatTime(size_t timeInSeconds) 
    {
        size_t hours = timeInSeconds / 3600;
        size_t minutes = (timeInSeconds % 3600) / 60;
        size_t seconds = timeInSeconds % 60;

        std::ostringstream oss{};
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds;

        return oss.str(); 
    }

}  // namespace seneca