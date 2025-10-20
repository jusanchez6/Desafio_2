#include <QCoreApplication>
#include <iostream>

#include <Album.hpp>
#include <Song.hpp>
#include <Credit.hpp>


int main()
{
    // Crear canciones
    Song* s1 = new Song(10001001, "Intro", 120, "/music/album1");
    Song* s2 = new Song(10001002, "Luna", 210, "/music/album1");
    Song* s3 = new Song(10001003, "Ocaso", 180, "/music/album1");

    // Agregar créditos de ejemplo
    s1->addComposer(new Credit("Mario", "Lopez", "COMP001"));
    s2->addMusician(new Credit("Juan", "Perez", "MUS002"));

    // Crear álbum
    Album a1(20001, "Noches de Verano", "Sunset Records", 0b00001001, 20230815);

    // Agregar canciones al álbum
    a1.addSong(s1);
    a1.addSong(s2);
    a1.addSong(s3);

    // Mostrar información general
    a1.show();

    // Probar reproducción de una canción
    std::cout << "\nReproduciendo la segunda canción...\n";
    a1.show();
    a1.totalDuration();
    s2->play(256);
    s1->play(256);
    s3->play(256);


    return 0;
    

}
