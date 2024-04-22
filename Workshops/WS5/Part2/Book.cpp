#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <iomanip>
#include "Book.h"

namespace seneca
{
    void Book::exterminate(std::string& str) {
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

    Book::Book(const std::string& strBook) 
    {
        std::string temp = strBook;

        m_author = temp.substr(0, temp.find(','));
        exterminate(m_author);
        temp.erase(0, temp.find(',') + 1);

        m_title = temp.substr(0, temp.find(','));
        exterminate(m_title);
        temp.erase(0, temp.find(',') + 1);

        m_country = temp.substr(0, temp.find(','));
        exterminate(m_country);
        temp.erase(0, temp.find(',') + 1);

        m_price = std::stod(temp.substr(0, temp.find(',')));
        temp.erase(0, temp.find(',') + 1);

        m_year = std::stoi(temp.substr(0, temp.find(',')));
        temp.erase(0, temp.find(',') + 1);

        m_description = temp; 
        exterminate(m_description); 
    }

    std::ostream& Book::display(std::ostream& os) const
    {
        os.setf(std::ios::right);
        os.width(20);
        os << author() << " | "; 
        os.width(22);
        os << title() << " | ";
        os.width(5);
        os << country() << " | ";
        os.width(4);
        os << year() << " | ";
        os.width(6);
        os.precision(2);
        os.setf(std::ios::fixed);
        os << m_price << " | "; 
        os << description() << std::endl; 

        return os;
    }

    std::ostream& operator<<(std::ostream& ostr, const Book& book)
    {
        return book.display(ostr);
    }

} // namespace seneca