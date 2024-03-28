#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <thread>
#include <future>
#include <functional>
#include "TreasureMap.h"

namespace seneca
{

    size_t digForTreasure(const std::string &str, char mark)
    {
        size_t cnt = 0;
        for (auto &x : str)
        {
            if (x == mark)
            {
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char *filename)
    {
        std::fstream fin(filename);
        if (fin)
        {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin)
            {
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else
        {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap()
    {
        delete[] map;
    }

    std::ostream &TreasureMap::display(std::ostream &os) const
    {
        if (map)
        {
            for (size_t i = 0; i < rows; ++i)
            {
                os << map[i] << std::endl;
            }
        }
        else
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char *filename)
    {
        // Binary write
        if (map)
        {
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.

            // END TODO
            std::ofstream fout(filename, std::ios::binary); // Open the file in binary mode
            if (fout.is_open())
            {
                fout.write(reinterpret_cast<const char *>(&rows), sizeof(size_t));    // Write the number of rows
                fout.write(reinterpret_cast<const char *>(&colSize), sizeof(size_t)); // Write the column size
                for (size_t i = 0; i < rows; ++i)
                {
                    fout.write(map[i].c_str(), colSize); // Write each row to the file
                }
                fout.close(); // Close the file
            }
            else
            {
                throw std::string("Unable to open file for writing: ") + filename;
            }
        }
        else
        {
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char *filename)
    {
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.

        // END TODO
        std::ifstream fin(filename, std::ios::binary); // Open the file in binary mode
        if (fin.is_open())
        {
            fin.read(reinterpret_cast<char *>(&rows), sizeof(size_t));    // Read the number of rows
            fin.read(reinterpret_cast<char *>(&colSize), sizeof(size_t)); // Read the column size
            delete[] map;                                                 // Clear existing map if any
            map = new std::string[rows];                                  // Allocate memory for the map
            for (size_t i = 0; i < rows; ++i)
            {
                char *rowBuffer = new char[colSize + 1]; // Allocate buffer for each row
                fin.read(rowBuffer, colSize);            // Read a row from the file
                rowBuffer[colSize] = '\0';               // Null-terminate the string
                map[i] = rowBuffer;                      // Store the row in the map
                delete[] rowBuffer;                      // Free the buffer
            }
            fin.close(); // Close the file
        }
        else
        {
            throw std::string("Unable to open file for reading: ") + filename;
        }
    }

    void TreasureMap::clear()
    {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark)
    {
        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        // for (size_t i = 0; i < rows; ++i)
        // {
        //     count += digForTreasure(map[i], mark);
        // }

        size_t count = 0;
        size_t numThreads = 4; // Number of threads to use
        std::vector<std::thread> threads(numThreads);
        std::vector<size_t> partialCounts(numThreads, 0);

        // Partition the data
        size_t partitionSize = rows / numThreads;

        // Function to be executed by each thread
        auto threadFunction = [&](size_t threadId)
        {
            size_t start = threadId * partitionSize;
            size_t end = (threadId == numThreads - 1) ? rows : (threadId + 1) * partitionSize;
            for (size_t i = start; i < end; ++i)
            {
                partialCounts[threadId] += digForTreasure(map[i], mark);
            }
        };

        // Create and execute threads
        for (size_t i = 0; i < numThreads; ++i)
        {
            threads[i] = std::thread(threadFunction, i);
        }

        // Join threads and accumulate partial counts
        for (size_t i = 0; i < numThreads; ++i)
        {
            threads[i].join();
            count += partialCounts[i];
        }

        return count;
    }
}