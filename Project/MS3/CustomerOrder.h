#pragma once
#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H
#include <string>
#include "Station.h"

namespace seneca
{
    struct Item
    {
        std::string m_itemName;
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };

        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder
    {
    private:
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item** m_lstItem{};

        static size_t m_widthField;  // class variable

    public:
        CustomerOrder() = default;
        CustomerOrder(const std::string& input);
        CustomerOrder(const CustomerOrder& order);
        CustomerOrder& operator=(const CustomerOrder& order) = delete;
        CustomerOrder(CustomerOrder&& order) noexcept;
        CustomerOrder& operator=(CustomerOrder&& order) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;

    };

}  // namespace seneca

#endif  // !SENECA_CUSTOMERORDER_H


