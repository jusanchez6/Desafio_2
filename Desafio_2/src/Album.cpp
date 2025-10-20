#include <Album.hpp>

Album::Album(int id, const std::string &name, const std::string &label, unsigned char genrer_mask, unsigned int release_date) : id(id), name(name), label(label), genrer_mask(genrer_mask), release_date(release_date) {}

Album::~Album() {
    for (size_t i = 0; i < songs.getSize(); ++i)
    {
        delete songs[i];
    }

}

void Album::addSong(Song* s) {
    songs.push_back(s);
}


int Album::totalDuration() const {

    int total = 0;

    for (size_t i = 0; i < songs.getSize(); ++i)
    {
        total += songs[i]->getDuration();
    }

    return total;
}

int Album::getId() const {return id; }
const std::string& Album::getName() const {return name; }
const std::string& Album::getLabel() const {return label; }
unsigned int Album::getReleaseDate() const {return release_date; }
unsigned char Album::getGenderMAsl() const {return genrer_mask; }

// metodo para mostrar la información

void Album::show() const {
    std::cout << "\n--- Álbum ---\n";
    std::cout << "ID: " << id
              << "\nNombre: " << name
              << "\nSello: " << label
              << "\nFecha de lanzamiento: " << release_date
              << "\nGéneros (máscara): " << static_cast<int>(genrer_mask)
              << "\nCanciones: " << songs.getSize()
              << "\nDuración total: " << totalDuration() << " s"
              << std::endl;

    for (size_t i = 0; i < songs.getSize(); ++i) {
        std::cout << "  [" << i + 1 << "] " << songs[i]->getName() << std::endl;
    }
}
