#pragma once
#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <string>

namespace seneca
{

	class Toy
	{
	private:
		unsigned int m_orderID{};            // order id the order id of the toy (a positive number)
        std::string m_name{};                // the name the name of the toy
        int  m_numOfItems{};                 // the number of items the number of toys of this type to be ordered
        double m_price{};                    // the price the price of this toy
        double m_HST = 0.13;                 // the harmonized sales tax assume the HST is equal to 13% 


	public:
		// Default destructor
		Toy() = default;

		// a modifier that receives as a parameter the number of toys of this type to be ordered and updates the number of items attribute 
		// with the received value.Assume the parameter is correct and doesn't require validation.
		void update(int numItems);

		/* A constructor that receives the toy attributes as a string; this constructor is responsible for extracting information
		   about the toy from the string and storing the tokens in the instance's attributes.
		   The string will always have the following format: ID:NAME:NUM:PRICE
		   This constructor should remove all leading and trailing spaces from the beginning and end of any token extracted from the string.
		   When implementing the constructor, consider this following functions :
		   std::string::substr() , std::string::find(), std::string::erase(), std::stoi()    */
		Toy(const std::string& toy);


		// Helper operator overloading of the insertion operator to print out a Toy object
		friend std::ostream& operator<<(std::ostream& ostr, const Toy& T);

	};

}   // namespace seneca

#endif  // ! SENECA_TOY_H





