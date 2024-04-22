#pragma once
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <string>


namespace seneca {

    class Book {
    private:
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        std::string m_description{};
        size_t m_year{};
        double m_price{};

    public:
        Book() = default;
        const std::string& author() const { return m_author; }
        const std::string& title() const { return m_title; }
        const std::string& country() const { return m_country; }
        const std::string& description() const { return m_description; }
        const size_t& year() const { return m_year; }
        double& price() { return m_price; }

        Book(const std::string& strBook);
       
        std::ostream& display(std::ostream& ostr) const;
        
        // friend helper
        friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
    };

}  // namespace seneca

#endif  // !SENECA_BOOK_H
