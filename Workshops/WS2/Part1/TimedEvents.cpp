#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <iomanip>
#include "TimedEvents.h"


namespace seneca
{
	void TimedEvents::startClock() 
	{
		m_startTime = std::chrono::steady_clock::now();  
	}

	void TimedEvents::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();  
	}

	void TimedEvents::addEvent(const char* eventName)
	{
		if (m_numRecords < MAX_EVENTS) 
		{ 
			events[m_numRecords].m_eventName = eventName; 
			events[m_numRecords].m_timeUnits = "nanoseconds"; 
			events[m_numRecords].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime); 
			m_numRecords++; 
		}

	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& timedEvents)
	{
		os << "--------------------------" << std::endl; 
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;

		for (int i = 0; i < timedEvents.m_numRecords; i++) 
		{
			os << std::left << std::setw(21) << timedEvents.events[i].m_eventName;   
			os << std::right << std::setw(13) << timedEvents.events[i].m_duration.count(); 
			os << " " << timedEvents.events[i].m_timeUnits << "\n"; 
		}

		os << "--------------------------\n";

		return os;
	}


} // namespace seneca