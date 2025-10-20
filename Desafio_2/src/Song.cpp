#include <Song.hpp>

#include <thread>
#include <chrono>

Song::Song(int id, const std::string &name, int duration, const std::string &path) : id(id), duration(duration), name(name), path(path), playCount(0)
{
}

Song::~Song() {
    for(size_t i = 0; i < producers.getSize(); i++)
        delete producers[i];
    for(size_t i = 0; i < musicians.getSize(); i++)
        delete musicians[i];
    for(size_t i = 0; i < composers.getSize(); i++)
        delete composers[i];
}

void Song::play(int kbps) {
    std::cout << "\n Reproduciendo: " << name
              << "[" << kbps << " kbps]"
              << "(" << duration << "s)" << std::endl;

    std::cout << "Ruta del archivo: " << path << "/" << name << "_" << kbps << ".ogg" << std::endl;
    std::cout << "Mostrando portada: " << path << "/cover.png" << std::endl;

    playCount++;

    // simulación de la duración de la canción 
    std::this_thread::sleep_for(std::chrono::minutes(3));
    std::cout << "Reproducción finalizada (" << playCount << " reproducciones).\n";
    
}

// metodos funcionales
void Song::addProducer(Credit* c) {producers.push_back(c); }
void Song::addMusician(Credit* c) {musicians.push_back(c); }
void Song::addComposer(Credit* c) {composers.push_back(c); }

// metodos getters

int Song::getId() const {return id; }
const std::string& Song::getName() const {return name; }
const std::string& Song::getPath() const {return path; }
unsigned int Song::getPlayCount() const {return playCount; }
int Song::getDuration() const {return duration; } 


void Song::show() {
   std::cout << "\n--- Canción ---\n";
    std::cout << "ID: " << id << "\nNombre: " << name
              << "\nDuración: " << duration << " s"
              << "\nReproducciones: " << playCount
              << "\nRuta: " << path << std::endl;

    std::cout << "\nCréditos:\n";
    std::cout << "  Productores: " << producers.getSize()
              << "\n  Músicos: " << musicians.getSize()
              << "\n  Compositores: " << composers.getSize() << std::endl;
}
