#include <QCoreApplication>
#include <iostream>

#include <Album.hpp>
#include <Song.hpp>
#include <Credit.hpp>
#include <User.hpp>


int main()
{
     // Crear canciones
    Song* s1 = new Song(101, "Sol de Enero", 210, "/music/sol");
    Song* s2 = new Song(102, "Brisa Marina", 180, "/music/brisa");
    Song* s3 = new Song(103, "Atardecer", 200, "/music/atardecer");

    // Crear usuarios
    User u1("andres99", true, "Bogotá", "Colombia", 20240120);
    User u2("sofia12", false, "Medellín", "Colombia", 20240501);

    // Configurar favoritos
    u1.addFavorite(s1);
    u1.addFavorite(s2);
    u2.addFavorite(s3);

    // Mostrar información de usuarios
    u1.show();
    u2.show();

    // Reproducir favoritos
    u1.playFavorites(false);
    u2.playFavorites(true);

    // Seguir a otro usuario
    u2.follow(&u1);

    // Mostrar nuevamente
    u2.show();

    return 0;
}
