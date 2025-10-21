#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <string>
#include <iostream>
#include "DynamicArray.hpp"
#include "Album.hpp"

class Artist {
private:
    int id;                        // Identificador único del artista
    unsigned char age;             // Edad
    std::string name;              // Nombre del artista
    std::string country;           // País de origen
    DynamicArray<Album*> albums;   // Álbumes asociados al artista

public:
    // Constructores
    Artist(int id, unsigned char age, const std::string& name, const std::string& country);

    // Destructor
    ~Artist();

    // Métodos funcionales
    void addAlbum(Album* album);
    Album* getAlbum(int id);

    // Getters
    int getId() const;
    unsigned char getAge() const;
    const std::string& getName() const;
    const std::string& getCountry() const;
    size_t getAlbumCount() const;

    // Mostrar información general (debug)
    void show() const;
};

#endif // ARTIST_HPP
