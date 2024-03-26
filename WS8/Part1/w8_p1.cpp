#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include "element.h"
#include "list.h"
#include "utilities.h"

const int FWC = 5;
const int FWD = 12;
const int FWP = 8;

size_t seneca::Product::idGenerator = 0;
bool seneca::Product::Trace = true;

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc != 4) {
		std::cerr << std::endl << "***Incorrect number of arguments***" << std::endl;
		return 1;
	}

	try {
		seneca::List<seneca::Description> desc(argv[1]);
		seneca::List<seneca::Price> priceBad(argv[2]);
		seneca::List<seneca::Price> priceGood(argv[3]);

		std::cout << std::setw(FWC) << "Code" << std::setw(FWD) << "Description" << std::endl;
		std::cout << desc << std::endl;

		std::cout << "********************************************" << std::endl
			      << "* Good Prices" << std::endl
			      << "********************************************" << std::endl;
		std::cout << std::setw(FWC) << "Code" << std::setw(FWP) << "Price" << std::endl;
		std::cout << priceGood << std::endl;

		std::cout << "********************************************" << std::endl
			      << "* Bad Prices" << std::endl
			      << "********************************************" << std::endl;
		std::cout << std::setw(FWC) << "Code" << std::setw(FWP) << "Price" << std::endl;
		std::cout << priceBad << std::endl;

		seneca::Product::Trace = true;
		std::cout << "********************************************" << std::endl
			      << "* Merging bad prices using Raw Pointers" << std::endl
			      << "********************************************" << std::endl;
		try {
			seneca::List<seneca::Product> priceList = seneca::mergeRaw(desc, priceBad);
		}
		catch (const std::string& msg) {
			std::cout << "ERROR: " << msg << std::endl;
			std::cout << "NOTE: An exception occurred while creating the list of products!" << std::endl;
		}

		seneca::Product::Trace = false;
		std::cout << std::endl << std::endl;
		// no exceptions should be generated from the code below.
		std::cout << "********************************************" << std::endl
			      << "* Merging good prices using Raw Pointers" << std::endl
			      << "********************************************" << std::endl;
		{
			seneca::List<seneca::Product> priceList = seneca::mergeRaw(desc, priceGood);
			std::cout << std::setw(FWD) << "Description" << std::setw(FWP) << "Price" << std::endl;
			std::cout << priceList << std::endl;
		}
	}
	catch (...) {
		std::cout << "ERROR: Unknown error!";
	}
	return cout;
}