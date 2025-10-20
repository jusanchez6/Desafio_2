#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include <iostream>
#include <DynamicArray.hpp>
#include <Song.hpp>

class Album
{
private:
    int id;
    std::string name;
    std::string label;
    DynamicArray<Song*> songs;
    unsigned char genrer_mask;
    unsigned int release_date;

public:
    
    // constructos
    Album(int id, const std::string& name, const std::string& label, unsigned char genrer_mask, unsigned int release_date);

    // Destructor
    ~Album();

    // funcionales
    void addSong(Song* s);
    int totalDuration() const;

    // getters

    int getId() const;
    const std::string& getName() const;
    const std::string& getLabel() const;
    unsigned int getReleaseDate() const;
    unsigned char getGenderMAsl() const;


    void show() const;
};



#endif // ALBUM_HPP