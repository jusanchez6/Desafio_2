#include <QCoreApplication>
#include <iostream>

#include "Database.hpp"


int main() {
    Database db;

    // Cargar datos simulados
    db.loadDummyData();

    // Mostrar resumen general
    db.showSummary();

    // Buscar usuario existente
    User* u = db.findUser("maria");
    if (u) {
        std::cout << "\n👤 Usuario encontrado: " << u->getNick()
                  << " (" << (u->isPremium() ? "Premium" : "Standard") << ")\n";
        u->playFavorites(false);
    }

    // Buscar una canción
    Song* s = db.findSong(10002);
    if (s) {
        std::cout << "\n🎶 Canción encontrada: " << s->getName() << std::endl;
    }

    // Simular guardado
    db.saveData();

    return 0;
}


