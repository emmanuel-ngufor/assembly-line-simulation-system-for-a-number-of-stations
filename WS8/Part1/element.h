#ifndef SENECA_ELEMENT_H
#define SENECA_ELEMENT_H

#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept> 

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace seneca {

	struct Description {
		unsigned code{};
		std::string desc{};

		// 	bool load(std::ifstream& f) {
		// 		f >> code >> desc;
		// 		return f.good();
		// 	}
		bool load(std::ifstream &f)
		{
			return (f >> code >> desc) ? true : false; 
		}

		void display(std::ostream& os) const 
		{
			os << std::setw(FWC) << code
				<< std::setw(FWD) << desc
				<< std::endl;
		}
	};

	struct Price {
		unsigned code{};
		double price{};
		
		// bool load(std::ifstream& f) {
		// 	f >> code >> price;
		// 	return f.good();
		// }
		bool load(std::ifstream &f)
		{
			return (f >> code >> price) ? true : false; 
		}

		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product {
		std::string m_desc{};
		double m_price{};
		size_t m_id{}; 

		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;

		Product() {
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}

		Product(const std::string& str, double p) {
			this->m_desc = str;
			this->m_price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}

		Product(const Product& other) {
			this->m_desc = other.m_desc;
			this->m_price = other.m_price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
				<< "] from [" << other.m_id << "]"
				<< std::endl;
		}

		~Product() {
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}

		// TODO: add a function here to validate the price
        void validate() const
        {
            if(m_price <= 0) throw std::string("*** Negative prices are invalid ***");
        }

		void display(std::ostream& os) const {
			os << std::setw(FWD) << m_desc
				<< std::setw(FWP) << m_price
				<< std::endl;
		}
	};
}
#endif