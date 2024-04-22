#pragma once
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H
#include <string> 

namespace seneca
{
	class StringSet
	{
	private:
		std::string* m_strings{}; // Dynamically allocated array of strings
		size_t m_numStrings{};    // Number of strings currently stored 

	public:
		// No-argument default constructor
		StringSet() = default;

		/*
		1-argument constructor that receives the address of a C-style null terminated string containing the name of a file
		from which this member function populates the current object. This function
		i. reads the file to count the number of strings present in the file (the record delimiter should be a single space ' ')
		ii. allocates memory for that number of strings in the array
		iii. re-reads the file and loads the strings into the array.
		*/
		StringSet(const char* filename);

		// A query that returns the number of strings stored in the current object.
		size_t size() const;

		/* A query that returns a copy of the string at the index received as the function parameter.
		   If the index is invalid, this function should return an empty string. */
		std::string operator[](size_t) const;

		// Destructor to free dynamically allocated memory
		virtual ~StringSet();

		// Copy Constructor
		StringSet(const StringSet& other);

		// Copy Assignment
		StringSet& operator=(const StringSet& other);

		// Move Constructor
		StringSet(StringSet&& other) noexcept;

		// Move Assignment
		StringSet& operator=(StringSet&& other) noexcept;

	};

}   // namespace seneca

#endif  // ! SENECA_STRINGSET_H

