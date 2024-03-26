#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "SongCollection.h"
#include "SongCollection.h"     // intentional

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

void printbar(std::ostream& out = std::cout)
{
	out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
}

void printHeader(const char* title, std::ostream& out = std::cout)
{
	printbar(out);
	out << "| " << std::left << std::setw(85) << title << std::right << "|\n";
	printbar(out);
}

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	seneca::SongCollection theCollection(argv[1]);

	printHeader("The original collection");
	theCollection.display(std::cout);
	printbar();
	
	return cout;
}