/*=============================================================================================================
 Name: Emmanuel Sahfor Ngufor
 Seneca Student ID: 135801215
 Seneca email: esngufor@myseneca.ca
 Date of completion:  12-03-2024
 Workshop# : WS7 - Part 2 - STL Algorithms
 File : SongCollection.h

 I declare that this submission is the result of my own work and I only copied the code that my professor provided
 to complete my workshops and assignments.This submitted piece of work has not been shared with any other student
 or 3rd party content provider.
 ===============================================================================================================*/

 #ifndef SENECA_SONGCOLLECTION_H
 #define SENECA_SONGCOLLECTION_H
 #include <string>
 #include <vector>
 #include <chrono>

 namespace seneca
 {

    struct Song
    {
      std::string m_title{};
      std::string m_artist{};
      std::string m_album{};
      std::string m_year{};
      int m_length{};
      double m_price{};
    };

    class SongCollection
    {
        private:
        std::vector<Song*> songList{};
        std::string remove_spaces(std::string str);
        

        public:
        SongCollection() = default;
        SongCollection(std::string filename); // constructor to load data from file into vector
        void display(std::ostream& out) const;
        virtual ~SongCollection();


    };

    // Free Helper
    std::ostream& operator<<(std::ostream& out, const Song& theSong);

 }   // namespace seneca

 #endif // !SENECA_SONGCOLLECTION_H
