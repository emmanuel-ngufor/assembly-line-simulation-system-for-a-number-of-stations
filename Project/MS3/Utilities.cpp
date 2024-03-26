#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
#include "Utilities.h"

namespace seneca
{
    char Utilities::m_delimiter = '|';

    void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

    size_t Utilities::getFieldWidth() const { return m_widthField; }

    void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

    char Utilities::getDelimiter() { return m_delimiter; }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {

        if (str[next_pos] == m_delimiter || next_pos >= str.length())
        {
            more = false;
            throw std::invalid_argument("Invalid next_pos arguement");
        }

        std::string token = "";
        std::string whitespace = "";

        while (next_pos < (size_t)str.length())
        {
            if (str[next_pos] != ' ')
            {
                if (str[next_pos] == '\n' || str[next_pos] == '\r')
                {
                    break;
                }
                else if (str[next_pos] == m_delimiter)
                {
                    if (m_widthField < token.length())
                    {
                        m_widthField = token.length();
                    }
                    more = true;
                    next_pos++;
                    return token;
                }
                else
                {
                    if (token.length() > 0)
                    {
                        token += whitespace + str[next_pos];
                        whitespace = "";
                    }
                    else
                    {
                        token += str[next_pos];
                        whitespace = "";
                    }

                    if (next_pos == (size_t)str.length() - 1)
                    {
                        if (m_widthField < token.length())
                        {
                            m_widthField = token.length();
                        }
                        more = false;
                        next_pos++;
                        return token;
                    }
                }
            }
            else
            {
                whitespace += ' ';
            }
            next_pos++;
        }

        more = false;
        return token;
    }

}   // namespace seneca
