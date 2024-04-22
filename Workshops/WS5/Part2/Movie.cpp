#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Movie.h"

namespace seneca
{
	void Movie::exterminate(std::string& str)
	{
		bool ok = false;

		while (!ok)
		{
			if (str[0] == ' ') {
				str.erase(0, 1);
			}
			else if (str[str.length() - 1] == ' ') {
				str.erase(str.length() - 1, str.length());
			}
			else {
				ok = true;
			}
		}
	} 

    const std::string& Movie::title() const { return m_title; }  

	Movie::Movie(const std::string& strMovie) 
	{
		std::string temp = strMovie;

		m_title = temp.substr(0, temp.find(',')); 
		temp.erase(0, temp.find(',') + 1);

		m_year = std::stoi(temp.substr(0, temp.find(',')));
		temp.erase(0, temp.find(',') + 1);

		m_description = temp;   

		exterminate(m_title);
		exterminate(m_description); 
	}

	std::ostream& Movie::display(std::ostream& os) const
	{
		os.width(40); 
		os.setf(std::ios::right); 
		os << m_title << " | ";   
		os.unsetf(std::ios::right); 
		os.width(4); 
		os << m_year << " | "; 
		os.setf(std::ios::left); 
		os << m_description << std::endl; 

		return os; 
	}

	std::ostream& operator<<(std::ostream& ostr, const Movie& movie)
	{
		return movie.display(ostr);  
	}

} // namespace seneca