#ifndef DATABASE_HPP
#define DATABASE_HPP


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <DynamicArray.hpp>
#include <User.hpp>
#include <Artist.hpp>
#include <Album.hpp>
#include <Song.hpp>
#include <AdMessage.hpp>


class Database
{
private:
    DynamicArray<User*> users;
    DynamicArray<Artist*> artists;
    DynamicArray<Album*> albums;
    DynamicArray<Song*> songs;
    DynamicArray<AdMessage*> ads;

public:
    Database();
    ~Database();

    void loadDummyData();
    void saveData();
    void loadFromFile(const std::string& filename);


    User* findUser(const std::string& nick);
    Song* findSong(int id);

    DynamicArray<Song*>& getSongs();
    DynamicArray<AdMessage*>& getAds();
    DynamicArray<User*>& getUsers();

    // debug
    void showSummary() const;
};




#endif