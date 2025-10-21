#include <Database.hpp>

Database::Database() {}

Database::~Database()
{
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

void Database::loadDummyData()
{
    // === Canciones ===
    Song *s1 = new Song(10001, "Niebla", 200, "/music/Niebla");
    Song *s2 = new Song(10002, "Luz del Sol", 180, "/music/LuzDelSol");
    Song *s3 = new Song(10003, "Caminos", 210, "/music/Caminos");
    Song *s4 = new Song(10004, "Ecos del Mar", 230, "/music/EcosDelMar");
    Song *s5 = new Song(10005, "Sueño Infinito", 250, "/music/SuenoInfinito");
    Song *s6 = new Song(10006, "Raíces", 220, "/music/Raices");
    Song *s7 = new Song(10007, "Sombras", 240, "/music/Sombras");
    Song *s8 = new Song(10008, "Despierta", 195, "/music/Despierta");
    Song *s9 = new Song(10009, "Reflejos", 210, "/music/Reflejos");
    Song *s10 = new Song(10010, "Horizonte Azul", 260, "/music/HorizonteAzul");

    songs.push_back(s1);
    songs.push_back(s2);
    songs.push_back(s3);
    songs.push_back(s4);
    songs.push_back(s5);
    songs.push_back(s6);
    songs.push_back(s7);
    songs.push_back(s8);
    songs.push_back(s9);
    songs.push_back(s10);

    // === Álbumes ===
    Album *a1 = new Album(20001, "Horizontes", "IndieSound", 0b00001101, 20240610);
    a1->addSong(s1);
    a1->addSong(s2);
    a1->addSong(s3);

    Album *a2 = new Album(20002, "Tierra y Mar", "OceanWave", 0b00001010, 20230521);
    a2->addSong(s4);
    a2->addSong(s5);

    Album *a3 = new Album(20003, "Raíces del Alba", "Roots Records", 0b00011100, 20231212);
    a3->addSong(s6);
    a3->addSong(s7);
    a3->addSong(s8);

    Album *a4 = new Album(20004, "Reflejos", "UrbanBeats", 0b00010010, 20240901);
    a4->addSong(s9);
    a4->addSong(s10);

    albums.push_back(a1);
    albums.push_back(a2);
    albums.push_back(a3);
    albums.push_back(a4);

    // === Artistas ===
    Artist *art1 = new Artist(30001, 29, "Laura Gómez", "Colombia");
    art1->addAlbum(a1);

    Artist *art2 = new Artist(30002, 34, "Diego Rivera", "México");
    art2->addAlbum(a2);

    Artist *art3 = new Artist(30003, 26, "Ana Lucía Torres", "Argentina");
    art3->addAlbum(a3);

    Artist *art4 = new Artist(30004, 31, "The Urban Keys", "Chile");
    art4->addAlbum(a4);

    artists.push_back(art1);
    artists.push_back(art2);
    artists.push_back(art3);
    artists.push_back(art4);

    // === Usuarios ===
    User *u1 = new User("juanito", false, "Bogotá", "Colombia", 20240115);
    User *u2 = new User("Maria", true, "Medellín", "Colombia", 20240310);
    User *u3 = new User("Angie", true, "Cartagena", "Colombia", 20241201);
    User *u4 = new User("Julián", false, "Rionegro", "Colombia", 20241201);
    User *u5 = new User("Carlos", false, "Quito", "Ecuador", 20240412);
    User *u6 = new User("Lucía", true, "Lima", "Perú", 20240505);

    // === Favoritos ===
    u1->addFavorite(s2);
    u1->addFavorite(s3);
    u2->addFavorite(s1);
    u2->addFavorite(s5);
    u3->addFavorite(s4);
    u3->addFavorite(s8);
    u4->addFavorite(s6);
    u5->addFavorite(s7);
    u5->addFavorite(s9);
    u6->addFavorite(s10);
    u6->addFavorite(s1);

    // === Seguimientos ===
    u1->follow(u2);
    u1->follow(u3);
    u2->follow(u1);
    u2->follow(u4);
    u3->follow(u5);
    u4->follow(u1);
    u4->follow(u2);
    u5->follow(u6);
    u6->follow(u1);
    u6->follow(u3);

    users.push_back(u1);
    users.push_back(u2);
    users.push_back(u3);
    users.push_back(u4);
    users.push_back(u5);
    users.push_back(u6);

    // === Anuncios ===
    ads.push_back(new AdMessage("¡Suscríbete a Premium para evitar anuncios!", 'A', 10));
    ads.push_back(new AdMessage("Descubre los nuevos lanzamientos semanales.", 'B', 5));
    ads.push_back(new AdMessage("Tu música, sin límites. Mejora tu cuenta hoy.", 'C', 8));
    ads.push_back(new AdMessage("Vuelve a escuchar tus canciones favoritas.", 'A', 6));
    ads.push_back(new AdMessage("Conecta con tus artistas preferidos en vivo.", 'B', 7));

    std::cout << "Datos de prueba cargados correctamente.\n";
}

void Database::saveData()
{
    std::cout << "Guardando datos en base de datos simulada..." << std::endl;
    std::cout << "Usuarios: " << users.getSize()
              << ", Canciones: " << songs.getSize()
              << ", Álbumes: " << albums.getSize()
              << ", Artistas: " << artists.getSize()
              << ", Anuncios: " << ads.getSize() << std::endl;
}

User *Database::findUser(const std::string &nick)
{
    for (size_t i = 0; i < users.getSize(); ++i)
    {
        if (users[i]->getNick() == nick)
            return users[i];
    }
    return nullptr;
}

Song *Database::findSong(int id)
{
    for (size_t i = 0; i < songs.getSize(); ++i)
    {
        if (songs[i]->getId() == id)
            return songs[i];
    }
    return nullptr;
}

DynamicArray<Song *> &Database::getSongs()
{
    return songs;
}

DynamicArray<AdMessage *> &Database::getAds()
{
    return ads;
}

void Database::showSummary() const
{
    std::cout << "\n=== Resumen de la Base de Datos ===" << std::endl;
    std::cout << "Usuarios: " << users.getSize()
              << "\nArtistas: " << artists.getSize()
              << "\nÁlbumes: " << albums.getSize()
              << "\nCanciones: " << songs.getSize()
              << "\nAnuncios: " << ads.getSize() << std::endl;
}