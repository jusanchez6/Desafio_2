#include <QCoreApplication>
#include <iostream>

#include "Database.hpp"
#include "PlaybackSession.hpp"
#include "MemoryTracker.hpp"

int main() {
    Database db;
    db.loadDummyData();

    User* u1 = db.findUser("juanito");
    if (!u1) {
        std::cout << "Usuario no encontrado." << std::endl;
        return 0;
    }

    PlaybackSession session(u1, &db, false);
    session.playFavorites(false);
    session.playRandom(3);
    session.showMetrics();

    // Reporte de memoria
    MemoryTracker::showReport();

    return 0;
}
