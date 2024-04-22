#pragma once
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <string>

namespace seneca 
{
    class Movie
    {
    private:
        std::string m_title{};
        std::string m_description{};
        size_t m_year{}; 
        void exterminate(std::string& str);
        
    public:
        Movie() = default;                       // Default Constructor

        const std::string& title() const;        // a query that returns the title of the movie

        /* receives the movie through a reference to a string.
          - This constructor extracts the information about the movie from the string and stores the tokens in the attributes. 
          - The received string always has the following format: TITLE, YEAR, DESCRIPTION
          - This constructor removes all spaces from the beginning and end of any token in the string.
          - When implementing this constructor, consider the following functions :
            std::string::substr() ,std::string::find(), std::string::erase(), std::stoi() */
        Movie(const std::string& strMovie);

        std::ostream& display(std::ostream& ostr) const;

        friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie); 

        /* a templated function. 
        This function calls the overloaded operator() on instance spellChecker, passing to it the movie title and description.
        ASSUMPTION: In this design, type T must have an overload of the operator() that accepts a string as a parameter.
        Since this is a templated function, it must be implemented in the header! The class is not a templated class. */
        template<typename T>
        void fixSpelling(T& spellChecker)
        {
            spellChecker(m_title);
            spellChecker(m_description); 
        }
    };

}  // namespace seneca

#endif  // !SENECA_MOVIE_H
