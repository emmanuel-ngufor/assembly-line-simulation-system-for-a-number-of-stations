#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <iomanip>
#include "Book.h"

namespace seneca 
{

    Book::Book(const std::string& strBook)
    {
        // FORMAT = AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION

        std::string tempStr = strBook;
        std::string author, title, country, year, price, description;
        size_t index{};

        // Extracting the author
        author = tempStr.substr(index, tempStr.find(','));
        author = author.erase(index, author.find_first_not_of(' '));
        author = author.erase(author.find_last_not_of(' ') + 1);
        tempStr.erase(index, tempStr.find(',') + 1);

        // Extracting the title
        title = tempStr.substr(index, tempStr.find(','));
        title = title.erase(index, title.find_first_not_of(' '));
        title = title.erase(title.find_last_not_of(' ') + 1);
        tempStr.erase(index, tempStr.find(',') + 1);

        // Extracting the country
        country = tempStr.substr(index, tempStr.find(','));
        country = country.erase(index, country.find_first_not_of(' '));
        country = country.erase(country.find_last_not_of(' ') + 1);
        tempStr.erase(index, tempStr.find(',') + 1);

        // Extracting the price
        price = tempStr.substr(index, tempStr.find(','));
        price = price.erase(index, price.find_first_not_of(' '));
        price = price.erase(price.find_last_not_of(' ') + 1);
        tempStr.erase(index, tempStr.find(',') + 1);

        // Extracting the year
        year = tempStr.substr(index, tempStr.find(','));
        year = year.erase(index, year.find_first_not_of(' '));
        year = year.erase(year.find_last_not_of(' ') + 1);
        tempStr.erase(index, tempStr.find(',') + 1);

        // Extracting the description 
        description = tempStr.substr(index);
        description = description.erase(index, description.find_first_not_of(' '));
        description = description.erase(description.find_last_not_of(' ') + 1);

        tempStr.clear();  // Clearing the original string

        // Setting values of the data members in class 
        this->m_author = author;
        this->m_title = title;
        this->m_country = country;
        this->m_price = std::stod(price);
        this->m_year = std::stoi(year);
        this->m_description = description;

    }

    std::ostream& Book::display(std::ostream& ostr) const
    {
        ostr << std::setw(20) << m_author << " | "
            << std::setw(22) << m_title << " | "
            << std::setw(5) << m_country << " | "
            << std::setw(4) << m_year << " | "
            << std::setw(6) << std::fixed << std::setprecision(2) << m_price << " | "
            << m_description << "\n";
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Book& book)
    {
        return book.display(ostr);
    }

} // namespace seneca