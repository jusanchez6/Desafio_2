/**
 * @file Database.cpp
 * @brief Implementación de la clase Database.
 *
 * Gestiona la base de datos interna de la aplicación: usuarios,
 * artistas, álbumes, canciones y anuncios.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#include "Database.hpp"


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

void Database::loadFromFile(const std::string &filename)
{
    std::ifstream file("dataset.txt");

    if (!file.is_open())
    {
        std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, '|');

        if (token == "SONG")
        {
            int id, duration;
            std::string title, path;
            std::string value;

            std::getline(ss, value, '|');
            id = std::stoi(value);
            std::getline(ss, title, '|');
            std::getline(ss, value, '|');
            duration = std::stoi(value);
            std::getline(ss, path, '|');

            Song *s = new Song(id, title, duration, path);
            songs.push_back(s);
        }

        else if (token == "ALBUM")
        {
            int id, mask, date;
            std::string title, studio, songList, value;

            std::getline(ss, value, '|');
            id = std::stoi(value);
            std::getline(ss, title, '|');
            std::getline(ss, studio, '|');
            std::getline(ss, value, '|');
            mask = std::stoi(value);
            std::getline(ss, value, '|');
            date = std::stoi(value);
            std::getline(ss, songList, '|');

            Album *a = new Album(id, title, studio, mask, date);

            // Relacionar canciones
            std::stringstream songStream(songList);
            std::string sid;
            while (std::getline(songStream, sid, ','))
            {
                Song *s = findSong(std::stoi(sid));
                if (s)
                    a->addSong(s);
            }

            albums.push_back(a);
        }

        else if (token == "ARTIST")
        {
            int id, age;
            std::string name, country, albumsStr, value;

            std::getline(ss, value, '|');
            id = std::stoi(value);
            std::getline(ss, value, '|');
            age = std::stoi(value);
            std::getline(ss, name, '|');
            std::getline(ss, country, '|');
            std::getline(ss, albumsStr, '|');

            Artist *art = new Artist(id, age, name, country);

            std::stringstream albStream(albumsStr);
            std::string aid;
            while (std::getline(albStream, aid, ','))
            {
                for (size_t i = 0; i < albums.getSize(); ++i)
                {
                    if (albums[i]->getId() == std::stoi(aid))
                    {
                        art->addAlbum(albums[i]);
                    }
                }
            }

            artists.push_back(art);
        }

        else if (token == "USER")
        {
            std::string name, city, country, favStr, followName, value;
            bool premium;
            int date;

            std::getline(ss, name, '|');
            std::getline(ss, value, '|');
            premium = std::stoi(value);
            std::getline(ss, city, '|');
            std::getline(ss, country, '|');
            std::getline(ss, value, '|');
            date = std::stoi(value);
            std::getline(ss, favStr, '|');
            std::getline(ss, followName, '|');

            User *u = new User(name, premium, city, country, date);

            // Agregar favoritos
            std::stringstream favs(favStr);
            std::string sid;
            while (std::getline(favs, sid, ','))
            {
                Song *s = findSong(std::stoi(sid));
                if (s)
                    u->addFavorite(s);
            }

            // Seguir a otro usuario (si ya está cargado)
            if (!followName.empty())
            {
                User *other = findUser(followName);
                if (other)
                    u->follow(other);
            }

            users.push_back(u);
        }

        else if (token == "AD")
        {
            char type;
            std::string msg, value;
            int weight;

            std::getline(ss, value, '|');
            type = value[0];
            std::getline(ss, msg, '|');
            std::getline(ss, value, '|');
            weight = std::stoi(value);

            AdMessage *ad = new AdMessage(msg, type, weight);
            ads.push_back(ad);
        }
        
        else if (token == "CREDIT")
        {
            int songId;
            std::string name, surname, role, value;

            std::getline(ss, value, '|');
            songId = std::stoi(value);
            std::getline(ss, name, '|');
            std::getline(ss, surname, '|');
            std::getline(ss, role, '|');

            Song *song = findSong(songId);
            if (!song)
                continue;

            Credit *c = new Credit(name, surname, role.c_str());

            if (role == "composer")
                song->addComposer(c);
            else if (role == "producer")
                song->addProducer(c);
            else if (role == "musician")
                song->addMusician(c);
        }
    }

    file.close();
    std::cout << "Dataset cargado desde archivo con éxito.\n";
}

void Database::loadDummyData()
{
    // Canciones
    Song *s1 = new Song(10001, "Niebla", 200, "/music/Niebla");
    Song *s2 = new Song(10002, "Luz del Sol", 180, "/music/LuzDelSol");
    Song *s3 = new Song(10003, "Caminos", 210, "/music/Caminos");
    songs.push_back(s1);
    songs.push_back(s2);
    songs.push_back(s3);

    // Álbum
    Album *a1 = new Album(20001, "Horizontes", "IndieSound", 0b00001101, 20240610);
    a1->addSong(s1);
    a1->addSong(s2);
    a1->addSong(s3);
    albums.push_back(a1);

    // Artista
    Artist *art1 = new Artist(30001, 29, "Laura Gómez", "Colombia");
    art1->addAlbum(a1);
    artists.push_back(art1);

    // Usuarios
    User *u1 = new User("juanito", false, "Bogotá", "Colombia", 20240115);
    User *u2 = new User("Maria", true, "Medellín", "Colombia", 20240310);

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

DynamicArray<Song *> &Database::getSongs() { return songs; }

DynamicArray<AdMessage *> &Database::getAds() { return ads; }

DynamicArray<User *> &Database::getUsers() { return users; }

void Database::showSummary() const
{
    std::cout << "\n=== Resumen de la Base de Datos ===" << std::endl;
    std::cout << "Usuarios: " << users.getSize()
              << "\nArtistas: " << artists.getSize()
              << "\nÁlbumes: " << albums.getSize()
              << "\nCanciones: " << songs.getSize()
              << "\nAnuncios: " << ads.getSize() << std::endl;
}