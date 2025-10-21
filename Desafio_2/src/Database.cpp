#include <Database.hpp>

Database::Database() {}

Database::~Database() {
    for (size_t i = 0; i < users.getSize(); ++i)
    {
        delete users[i];
    }
    for (size_t i = 0; i < artists.getSize(); ++i)
    {
        delete artists[i];
    }
    for (size_t i = 0; i < albums.getSize(); ++i)
    {
        delete albums[i];
    }
    for (size_t i = 0; i < songs.getSize(); ++i)
    {
        delete songs[i];
    }
    for (size_t i = 0; i < ads.getSize(); ++i)
    {
        delete ads[i];
    }
    
}

void Database::loadDummyData() {
    Song* s1 = new Song(10001, "Niebla", 200, "/music/Niebla");
    Song* s2 = new Song(10002, "Luz del Sol", 180, "/music/LuzDelSol");
    Song* s3 = new Song(10003, "Caminos", 210, "/music/Caminos");

    songs.push_back(s1);
    songs.push_back(s2);
    songs.push_back(s3);

    // Álbum
    Album* a1 = new Album(20001, "Horizontes", "IndieSound", 0b00001101, 20240610);
    a1->addSong(s1);
    a1->addSong(s2);
    a1->addSong(s3);
    albums.push_back(a1);

    // Artista
    Artist* art1 = new Artist(30001, 29, "Laura Gómez", "Colombia");
    art1->addAlbum(a1);
    artists.push_back(art1);

    // Usuarios
    User* u1 = new User("juanito", false, "Bogotá", "Colombia", 20240115);
    User* u2 = new User("maria", true, "Medellín", "Colombia", 20240310);

    u1->addFavorite(s2);
    u1->addFavorite(s3);
    u2->addFavorite(s1);
    u1->follow(u2);

    users.push_back(u1);
    users.push_back(u2);

    // Anuncios
    ads.push_back(new AdMessage("¡Suscríbete a Premium para evitar anuncios!", 'A', 10));
    ads.push_back(new AdMessage("Descubre los nuevos lanzamientos semanales.", 'B', 5));
    ads.push_back(new AdMessage("Tu música, sin límites. Mejora tu cuenta hoy.", 'C', 8));

    std::cout << "Datos de prueba cargados correctamente.\n";
}

void Database::saveData() {
    std::cout << "Guardando datos en base de datos simulada..." << std::endl;
    std::cout << "Usuarios: " << users.getSize()
              << ", Canciones: " << songs.getSize()
              << ", Álbumes: " << albums.getSize()
              << ", Artistas: " << artists.getSize()
              << ", Anuncios: " << ads.getSize() << std::endl;
}


User* Database::findUser(const std::string& nick) {
    for (size_t i = 0; i < users.getSize(); ++i) {
        if (users[i]->getNick() == nick)
            return users[i];
    }
    return nullptr;
}

Song* Database::findSong(int id) {
    for (size_t i = 0; i < songs.getSize(); ++i) {
        if (songs[i]->getId() == id)
            return songs[i];
    }
    return nullptr;
}

void Database::showSummary() const {
    std::cout << "\n=== Resumen de la Base de Datos ===" << std::endl;
    std::cout << "Usuarios: " << users.getSize()
              << "\nArtistas: " << artists.getSize()
              << "\nÁlbumes: " << albums.getSize()
              << "\nCanciones: " << songs.getSize()
              << "\nAnuncios: " << ads.getSize() << std::endl;
}