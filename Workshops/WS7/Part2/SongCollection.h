 #ifndef SENECA_SONGCOLLECTION_H
 #define SENECA_SONGCOLLECTION_H
 #include <string>
 #include <vector>
 #include <list>

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
        void sort(std::string type);
        void cleanAlbum();
        bool inCollection(std::string) const;
        std::list<Song> getSongsForArtist(std::string title) const;
        std::list<Song> getListForAlbum(std::string album) const; 
        
    };

    // Free Helper
    std::ostream& operator<<(std::ostream& out, const Song& theSong);

 }   // namespace seneca

 #endif // !SENECA_SONGCOLLECTION_H
