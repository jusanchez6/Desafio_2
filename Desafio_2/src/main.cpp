#include <QCoreApplication>
#include <iostream>

#include "Database.hpp"
#include "PlaybackSession.hpp"


int main() {
    std::cout << "=== Cargando base de datos ===" << std::endl;

    // Cargar base de datos de prueba
    Database db;
    db.loadDummyData();
    db.showSummary();

    // Buscar un usuario
    User* u1 = db.findUser("juanito");
    User* u2 = db.findUser("Maria");
    User* u3 = db.findUser("Angie");
    User* u4 = db.findUser("Julián");

    if (!u1 || !u2 || !u3 || !u4) {
        std::cout << "Error: No se pudieron cargar todos los usuarios de prueba." << std::endl;
        return 0;
    }

    // Crear sesión de reproducción para Juanito
    std::cout << "\n=== Sesión de Juanito ===" << std::endl;
    PlaybackSession session1(u1, &db, false);

    std::cout << "Reproduciendo canciones favoritas..." << std::endl;
    session1.playFavorites(false);

    std::cout << "\nReproduciendo 3 canciones aleatorias..." << std::endl;
    session1.playRandom(3);

    std::cout << "\nMétricas de la sesión:" << std::endl;
    session1.showMetrics();

    // Crear sesión de reproducción para Maria (premium)
    std::cout << "\n=== Sesión de Maria (Premium) ===" << std::endl;
    PlaybackSession session2(u2, &db, true);

    std::cout << "Reproduciendo canciones favoritas..." << std::endl;
    session2.playFavorites(false);

    std::cout << "\nReproduciendo 2 canciones aleatorias..." << std::endl;
    session2.playRandom(2);

    std::cout << "\nMétricas de la sesión:" << std::endl;
    session2.showMetrics();

    // Crear sesión para Angie
    std::cout << "\n=== Sesión de Angie ===" << std::endl;
    PlaybackSession session3(u3, &db, true);
    session3.playFavorites(false);
    session3.playRandom(1);
    session3.showMetrics();

    // Crear sesión para Julián
    std::cout << "\n=== Sesión de Julián ===" << std::endl;
    PlaybackSession session4(u4, &db, false);
    session4.playFavorites(false);
    session4.playRandom(2);
    session4.showMetrics();

    // Repetir reproducción de favoritos (simulando que el usuario vuelve)
    std::cout << "\n=== Juanito vuelve a escuchar sus favoritos ===" << std::endl;
    session1.playFavorites(false);
    session1.showMetrics();

    // Mostrar resumen general de métricas
    std::cout << "\n=== Resumen general de sesiones ===" << std::endl;
    std::cout << "Usuarios en la base de datos: " << std::endl;
    db.showSummary();

    std::cout << "\n=== Fin del programa ===" << std::endl;
    return 0;
}


