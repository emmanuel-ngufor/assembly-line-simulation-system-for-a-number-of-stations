#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "TreasureMap.h"
#include "TreasureMap.h"

int cout = 0; // will prevent compilation if headers don't follow convention

void dumpFileAsHex(const char* filename)
{
	std::fstream file(filename, std::ios::in | std::ios::ate | std::ios::binary);
	char c{};
	int cnt{1};
	std::cout << "\nThe content of the binary file\n";
	std::cout <<   "------------------------------\n";
	std::cout << "File size in bytes: [" << file.tellg()
	          << std::setfill('0') << std::hex;
	file.seekg(std::ios::beg);
	while(file.get(c))
	{
		if (cnt % 20 == 1)
			std::cout << "]\n" << std::setw(2) << (1 + cnt / 20) << ": [";
		std::cout << " " << std::setw(2) << static_cast<unsigned short>(c);
		++cnt;
	}
	file.close();
	std::cout << "]" << std::setfill(' ') << std::dec;
	std::cout << "\n------------------------------\n";
}

int main(int argc, char** argv){

    std::cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		std::cout << " " << argv[i];
	std::cout << std::endl << std::endl;

	if (argc != 3)
	{
		std::cerr << std::endl << "***Incorrect number of arguments***" << std::endl;
		return 1;
	}

    try {
        seneca::TreasureMap tmap(argv[1]);
        std::cout << "***Displaying original Map***" << std::endl;
        tmap.display(std::cout) << std::endl;

        std::cout << "***Enscribing Map and displaying cleared current Map***" << std::endl;
        tmap.enscribe(argv[2]);
        tmap.clear();
        tmap.display(std::cout) << std::endl;

        std::cout << "***Recalling Map and displaying current Map***" << std::endl;
        tmap.recall(argv[2]);
        tmap.display(std::cout) << std::endl;

        std::cout << "***Finding treasure on current Map***" << std::endl;
        size_t treasureFound = 0;
        treasureFound = tmap.findTreasure('X');
        std::cout << "***Found " << treasureFound << " treasure on current Map***" << std::endl;

    } catch (std::string& msg){
        std::cout << msg << std::endl;
    }

    dumpFileAsHex(argv[2]);

    return cout;
}