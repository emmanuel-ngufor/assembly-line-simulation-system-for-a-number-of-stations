#pragma once
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H
#include <string>


namespace seneca
{
    class Utilities
    {
    private:
        size_t m_widthField{ 1 }; 
        static char m_delimiter;   // class variable
      
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more); 
        static void setDelimiter(char newDelimiter);    // class function
        static char getDelimiter();                     // class function
        
    };

}  // namespace seneca

#endif  // !SENECA_UTILITIES_H


