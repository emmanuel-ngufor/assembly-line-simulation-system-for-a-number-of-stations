#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <numeric>
#include "SongCollection.h"

namespace seneca
{
    // std::string SongCollection::remove_spaces(std::string str)
    // {
    //     std::string newStr = "";
    //     std::string spaces = "";

    //     for (unsigned int i = 0; i < str.length(); i++) {
    //         if (str[i] == ' ')
    //         {
    //             spaces += ' ';
    //         }
    //         else if (str[i] == '\r' || str[i] == '\n')
    //         {
    //             break;
    //         }
    //         else
    //         {
    //             newStr += spaces + str[i];
    //             spaces = "";
    //         }
    //     }

    //     return newStr;

    // }

    std::string SongCollection::remove_spaces(std::string str)
    {
        // Remove leading and trailing spaces from the string
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);

        // Remove consecutive spaces within the string
        str.erase(std::unique(str.begin(), str.end(),[](char a, char b) { return a == ' ' && b == ' '; }), str.end());

        return str;
    }

    SongCollection::SongCollection(std::string filename)
    {
        std::fstream ifile(filename);
        std::string line;

        if (ifile.is_open())
        {
            while (std::getline(ifile, line))
            {
                Song* tmp = new Song();
                tmp->m_title = remove_spaces(line.substr(0, 25));
                tmp->m_artist = remove_spaces(line.substr(25, 25));
                tmp->m_album = remove_spaces(line.substr(50, 25));
                tmp->m_year = remove_spaces(line.substr(75, 5));
                tmp->m_length = std::stod(line.substr(80, 5));
                tmp->m_price = std::stod(line.substr(85, 5));
                songList.emplace_back(tmp);

            }

        }
        else
        {
            throw std::invalid_argument("Invalid file");
        }

    }

    std::ostream& operator<<(std::ostream& out, const Song& theSong)
    {
        // Format length
        double totalSeconds = theSong.m_length;
        int minutes = static_cast<int>(totalSeconds / 60);
        int seconds = static_cast<int>(totalSeconds) % 60;

        out << std::left << "| " << std::setw(20) << theSong.m_title << " | ";
        out << std::setw(15) << theSong.m_artist << " | ";
        out << std::setw(20) << theSong.m_album << " | ";
        out << std::right << std::setw(6) << theSong.m_year << " | ";
        out << minutes << ":";
        seconds < 10 ? out << '0' << seconds << " | " : out << seconds << " | ";
        out << theSong.m_price << " |";

        return out;
    }

    void SongCollection::display(std::ostream& out) const
    {
        // double totalPlaytime = 0.0;
        double totalPlaytime = std::accumulate(songList.begin(), songList.end(), 0.0,[](double sum, const Song *song) 
        { 
            return sum + song->m_length; 
        });

        // Iterate over the songList and print each song
        std::for_each(songList.begin(), songList.end(), [&out, &totalPlaytime](const Song* theSong)
        {
            out << *theSong << "\n";
            // totalPlaytime += theSong->m_length;
            // Accumulate the length of each song : Changed to used lambda experession  and STL accumulate algorithm
        });

        // Format totalPlaytime
        int hours = static_cast<int>(totalPlaytime / 3600);
        int minutes = static_cast<int>((totalPlaytime - hours * 3600) / 60); 
        int seconds = static_cast<int>(totalPlaytime) % 60;

        out << "----------------------------------------------------------------------------------------" << "\n";
        out << "|" << std::right << std::setw(78) << "Total Listening Time: ";
        out << hours << ":" << minutes << ":" << seconds << " |" << "\n";
    }

    SongCollection::~SongCollection()
    {
        for (auto song : songList)
        {
            delete song;
        }
    }

    void SongCollection::sort(std::string type) 
    {
        std::sort(songList.begin(), songList.end(), [type](Song* a, Song* b) 
            {
            if (type == "title") {
                return a->m_title < b->m_title; 
            }
            else if (type == "album") {
                return a->m_album < b->m_album;
            }
            else {
                return a->m_length < b->m_length; 
            }
            });
    }

    void SongCollection::cleanAlbum() 
    {
        std::for_each(songList.begin(), songList.end(), [](Song* theSong) {
            if (theSong->m_album == "[None]") 
            {
                theSong->m_album = ""; 
            }
            });
    }

    bool SongCollection::inCollection(std::string artist) const 
    {
        return std::find_if(songList.begin(), songList.end(), [artist](Song* theSong) 
            { 
                return theSong->m_artist == artist; 
            }) != songList.end(); 
    }

    std::list<Song> SongCollection::getSongsForArtist(std::string artist) const
    {
        std::list<Song> list; 
        std::for_each(songList.begin(), songList.end(), [&list, artist](Song* theSong)
            {
                if (theSong->m_artist == artist) 
                {
                    list.emplace_back(*theSong);
                }
            });

        return list;
    }

    std::list<Song> SongCollection::getListForAlbum(std::string album) const 
    {
        std::list<Song> list;
        std::for_each(songList.begin(), songList.end(), [&list, album](Song* theSong) 
            {
                if (theSong->m_album == album) 
                {
                    list.emplace_back(*theSong);
                }
            });

        return list;
    }

}  // namespace seneca