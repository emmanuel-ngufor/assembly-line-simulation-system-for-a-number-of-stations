#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <fstream>
#include "SpellChecker.h"

namespace seneca
{
    SpellChecker::SpellChecker(const char* filename)
    {
		std::ifstream fin(filename); 

		if (!fin)
		{
			throw "Bad file name!";
		}
		else 
		{
			for (size_t i = 0; i < MAX_WORDS && fin; i++) 
			{ 
				std::getline(fin, m_badWords[i], ' '); 
				m_badWords[i].erase(0, m_badWords[i].find_first_not_of(' '));
				m_badWords[i].erase(m_badWords[i].find_last_not_of(' ') + 1);

				std::getline(fin, m_goodWords[i], '\n');
				m_goodWords[i].erase(0, m_goodWords[i].find_first_not_of(' '));
				m_goodWords[i].erase(m_goodWords[i].find_last_not_of(' ') + 1);
			}
		}

    }

    void SpellChecker::operator()(std::string& text)
    {
		for (size_t i = 0; i < MAX_WORDS; i++) 
		{
			while (text.find(m_badWords[i]) != std::string::npos)
			{
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
				m_cnt[i]++;
			}
		}
    }

	void SpellChecker::showStatistics(std::ostream& out) const {
		std::cout << "Spellchecker Statistics" << std::endl; 

		for (size_t i = 0; i < MAX_WORDS; i++)  
		{ 
			out.width(15);
			out.setf(std::ios::right); 
			out << m_badWords[i] << ": "; 
			out << m_cnt[i] << " replacements" << std::endl; 
		}
	}


} // namespace seneca