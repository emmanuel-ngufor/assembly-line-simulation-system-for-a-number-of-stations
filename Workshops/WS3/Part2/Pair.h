#pragma once
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <iostream>
#include <string>

namespace seneca 
{ 
	class Pair
	{
	private:
		std::string m_key{};
		std::string m_value{}; 
	public:
		const std::string& getKey() const { return m_key; }
		const std::string& getValue() const { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

		// TODO: 
		// Add here the missing prototypes for the members that are necessary if this class is to be used
		// with the template classes described below. Implement them in the Pair.cpp file.
		
		// Compares two pairs if they have the same keys
		static bool haveSameKey(const Pair& A, const Pair& B); 
		// No-arg Constructor
		Pair() : m_key{ "" }, m_value{ "" } {}; 
		// display method to print out a pair object
		virtual std::ostream& display(std::ostream& ostr = std::cout) const; 
		// bool operator overlaod to compare two keys of a pair type
		bool operator==(const Pair& pair)const 
		{
			return m_key == pair.getKey();
		}
		
	};

	std::ostream& operator<<(std::ostream& ostr, const Pair& P);  

}   // namespace seneca

#endif  // ! SENECA_PAIR_H