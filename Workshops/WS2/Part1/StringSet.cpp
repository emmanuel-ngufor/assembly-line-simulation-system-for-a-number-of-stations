#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "StringSet.h"

namespace seneca
{
    StringSet::StringSet(const char* fileName)
    {
        // Open the file
        std::ifstream fileReader(fileName);  

        // Check if the file is open
        if (!fileReader.is_open()) 
        { 
            std::cerr << "Error: Unable to open file " << fileName << std::endl;
            return;
        }
        else
        {
            // Count the number of strings using space as the delimiter
            std::string word;
           
            char delimiter = ' ';  // Specify the delimiter

            // Read lines from the file using getline
            while (std::getline(fileReader, word, delimiter)) 
            {
                m_numStrings++;     
            }
            

            // Allocate memory for the strings
            m_strings = new std::string[m_numStrings];

            // Re-read the file and load the strings into the array
            fileReader.clear(); // Clear the end-of-file flag  
            fileReader.seekg(0, std::ios::beg); // Move the file pointer to the beginning  

            size_t index{};
            while (std::getline(fileReader, m_strings[index], delimiter)) 
            {
                index++; 
            }

            // Close the file
            fileReader.close(); 

        }
    }

    size_t StringSet::size() const 
    {
        return m_numStrings;
    }

   std::string StringSet::operator[](size_t index) const
   {
        if (index < m_numStrings) 
        {
            return m_strings[index];
        }
        else
        {
            return ""; // Return an empty string for invalid index
        }
   }

   StringSet::~StringSet()
   {
       if (m_strings != nullptr)
       {
           delete[] m_strings;
           m_strings = nullptr;
       }    
   }

   StringSet::StringSet(const StringSet& other) 
   {
       m_strings = nullptr;
       *this = other;
   }

   StringSet& StringSet::operator=(const StringSet& other)
   {
       // 1. Check for self assignment
       if (this != &other)
       {
           // 2. Shallow copy non resource instance variables
           m_numStrings = other.m_numStrings;

           // 3. Deallocate existing memory
           delete[] m_strings;

           // 4. Check of nullidity of resource instance variables of the other and deep copy them if present
           if (other.m_strings != nullptr)
           {
               m_strings = new std::string[other.m_numStrings]; 

               // Copy the strings
               for (size_t i = 0; i < m_numStrings; i++)  
               {
                   m_strings[i] = other.m_strings[i];  
               }
           }
           else
           {
               m_strings = nullptr;
           }
          
       }

       return *this;
   } 

}  // namespace seneca