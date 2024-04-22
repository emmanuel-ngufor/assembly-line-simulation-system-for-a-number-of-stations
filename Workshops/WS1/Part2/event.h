#pragma once
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca
{
    // extern for linkage to other files
    extern size_t g_sysClock;

    class Event { 
    private:
        char* m_description{};  // Dynamically allocated description
        size_t m_startTime{};
        static size_t counter;

        // Helper function to format time as HH:MM:SS
        static std::string formatTime(size_t timeInSeconds);

    public:
        // Default constructor
        Event() = default;

        // Constructor with description
        Event(const char* desc);

        // Destructor
        virtual ~Event();

        // Copy constructor
        Event(const Event& other);

        // Copy assignment operator
        Event& operator=(const Event& other);

        // Move constructor
        Event(Event&& other) noexcept;

        // Move assignment operator
        Event& operator=(Event&& other) noexcept;

        // Display function
        void display() const;

        // Modifier function to set the event
        void set(const char* desc = nullptr);    
    };

}  // namespace seneca
   

#endif // ! SENECA_EVENT_H