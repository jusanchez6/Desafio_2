#include "Artist.hpp"

Artist::Artist(int id, unsigned char age, const std::string& name, const std::string& country)
    : id(id), age(age), name(name), country(country) {}

//  Destructor
Artist::~Artist() {
    albums.clear();
}

//  Agregar un álbum
void Artist::addAlbum(Album* album) {
    albums.push_back(album);
}

//  Buscar un álbum por ID
Album* Artist::getAlbum(int searchId) {
    for (size_t i = 0; i < albums.getSize(); ++i) {
        if (albums[i]->getId() == searchId)
            return albums[i];
    }
    return nullptr;
}

//  Getters
int Artist::getId() const { return id; }
unsigned char Artist::getAge() const { return age; }
const std::string& Artist::getName() const { return name; }
const std::string& Artist::getCountry() const { return country; }
size_t Artist::getAlbumCount() const { return albums.getSize(); }

//  Mostrar información general
void Artist::show() const {
    std::cout << "\n=== Artista ===\n";
    std::cout << "ID: " << id
              << "\nNombre: " << name
              << "\nEdad: " << (int)age
              << "\nPaís: " << country
              << "\nÁlbumes publicados: " << albums.getSize()
              << std::endl;

    for (size_t i = 0; i < albums.getSize(); ++i) {
        std::cout << "  (" << i + 1 << ") " << albums[i]->getName()
        << " [" << albums[i]->getLabel() << "]" << std::endl;
    }
}
