#define CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Toy.h"

namespace seneca
{
    void Toy::update(int numItems) { this->m_numItems = numItems; } 

	Toy::Toy(const std::string& toy) 
	{
		std::string str = toy;                       
		std::string orderID, name, numOfItems, price; 

		orderID = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		name = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		numOfItems = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		price = str.substr(0, str.find(":"));
		str.erase(0, str.find(":") + 1);

		name.erase(0, name.find_first_not_of(' '));
		name.erase(name.find_last_not_of(' ') + 1);

		m_orderID = stoi(orderID);
		m_name = name;
		m_numItems = stoi(numOfItems);
		m_price = stod(price); 

	}

	std::ostream& operator<<(std::ostream& ostr, const Toy T)
	{
		// Preliminary Calculations
		double subTotal = (T.m_price * double(T.m_numItems));
		double tax = subTotal * T.m_HST; 
		double total = subTotal + tax;

		ostr << "Toy"; 
		ostr << std::setw(8) << T.m_orderID << ":"; 
		ostr << std::right << std::setw(18) << T.m_name; 
		ostr << std::setw(3) << T.m_numItems;

		ostr << " items" << std::setw(8) << std::fixed << std::setprecision(2) << T.m_price;   
		ostr << "/item  subtotal:" << std::setw(7) << std::fixed << std::setprecision(2) << subTotal; 
		ostr << " tax:" << std::setw(6) << std::fixed << std::setprecision(2) << tax; 
		ostr << " total:" << std::setw(7) << std::fixed << std::setprecision(2) << total << "\n"; 

		return ostr;
	}

}   // namespace seneca
