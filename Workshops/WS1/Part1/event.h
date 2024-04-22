#pragma once
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca 
{
    // System clock representing the time of day | extern for linkage to other files
    extern size_t g_sysClock;   

    const int MAX_CHARS = 128;

    class Event 
    {
    private:
        char m_description[MAX_CHARS + 1]{};
        size_t m_startTime{}; 
        static size_t counter;  // Counter for the display function  

    public:
        // Default constructor
        Event() = default;  
        // Display function
        void display();
        // Modifier function to set the event
        void set(const char* desc = nullptr);
        // Added function to format time as HH:MM:SS
        static std::string formatTime(size_t timeInSeconds);
    };

}  // namespace seneca

#endif // ! SENECA_EVENT_H
