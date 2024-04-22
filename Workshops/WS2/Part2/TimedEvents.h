#pragma once
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H
#include <string> 
#include <chrono>
#define MAX_EVENTS 10 

namespace seneca
{

	class TimedEvents
	{
	private:
		int m_numRecords{};
		std::chrono::steady_clock::time_point m_startTime{};
		std::chrono::steady_clock::time_point m_endTime{};
		// Event Structure
		struct Events
		{
			std::string m_eventName{};
			std::string m_timeUnits{};
			std::chrono::steady_clock::duration m_duration{};
		} events[MAX_EVENTS]{};;


	public:
		// Default Constructor : Class instance variables already initialized at creattion hence the setting to default
		TimedEvents() = default;

		// a modifier that starts the timer for an event
		void startClock();

		// a modifier that stops the timer for an event
		void stopClock();

		/*
		*  A modifier that receives the address of a C-style null-terminated string that holds the name of the event.
		   This function will update the next time-record in the array:
		   i. stores into the name attribute the C-style string at the pointed to address
		   ii. stores "nanoseconds" as the units of time
		   iii. calculates and stores the duration of the event (use std::chrono::duration_cast<std::chrono::nanoseconds>(),
		   https://en.cppreference.com/w/cpp/chrono/duration/duration_castsee documentation here)
		*/
		void addEvent(const char* eventName);

		/* a friend insertion operator that receives a reference to an std::ostream object and a TimedEvents object.
		This operator should insert in the std::ostream object the records from the array */
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& timedEvents);

	};

}   // namespace seneca

#endif  // ! SENECA_TIMEDEVENTS_H

