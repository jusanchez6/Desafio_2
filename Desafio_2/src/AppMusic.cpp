#include <AppMusic.hpp>

AppMusic::AppMusic() : currentUser(nullptr) {}

void AppMusic::loginMenu()
{
    Counter iterCount;      // Contador de iteraciones

    std::cout << "====== Inicio de Sesión ======\n";
    std::cout << "Usuarios disponibles: \n";

    // Mostrar los usuarios
    for (size_t i = 0; i < db.getUsers().getSize(); ++i)
    {
        iterCount.increment();      // Aumentar el contador

        User *u = db.getUsers()[i];
        std::cout << i + 1 << ". " << u->getNick();
        if (u->isPremium())
        {
            std::cout << " (Premium)";
        }
        std::cout << "\n";
    }

    int opt;
    std::cout << "\nSeleccione un usuario para iniciar sesión: ";
    std::cin >> opt;

    if (opt < 1 || opt > db.getUsers().getSize())
    {
        std::cout << "Opción inválida.\n";
        currentUser = nullptr;
        return;
    }
    currentUser = db.getUsers()[opt - 1];
    std::cout << "\n=======================\n"
              << "Bienvenido, " << currentUser->getNick() << "!\n";

    
    iterCount.showMetrics("LoginMenu(): ");
    MemoryTracker::showCurrentUsage("LongiMenu(): ");

    

}

void AppMusic::runPlayback(User *user, bool playFavorites)
{
    Counter iterCount;

    if (!user->isPremium() && playFavorites) {
        std::cout << "\n Esta funcionalidad es solo para Usuarios Premium.\n";
        return;
    }

    PlaybackSession session(user, &db, false);

    if (playFavorites)
        session.playFavorites(true, 3);
    else
        session.playRandom(3);

    session.showMetrics();

    // metricas de memoria y loops
    iterCount.increment();
    iterCount.showMetrics("runPlayback()");
    MemoryTracker::showCurrentUsage("Memoria Usada en runPlayback()");
}

void AppMusic::showFavorites(User* user) {

    Counter iterCount;


    if (!user) return;

    if (user->getFavoriteCount() == 0) {
        std::cout << "No hay canciones favoritas.\n";
        return;
    }

    std::cout << "\n=== Canciones favoritas de " << user->getNick() << " ===\n";

    for (size_t i = 0; i < user->getFavoriteCount(); ++i) {

        iterCount.increment();

        Song* s = user->getFavorite(i);
        const auto& musicians = s->getMusicians();
        
        if (!s) 
            continue;

        std::cout << " - " << s->getName();
        
        if (musicians.getSize() > 0) {

            iterCount.increment();

            for (size_t j = 0; j < musicians.getSize(); ++j)
                std::cout << "   - " << musicians[j]->getName() << " " << musicians[j]->getSurname() << std::endl;
        }
    }

    // === Métricas ===
    iterCount.showMetrics("showFavorites()");
    MemoryTracker::showCurrentUsage("Memoria usada en showFavorites()");

}


void AppMusic::editFavorites(User* user) {
    Counter iterCount;

    std::cout << "\n=== Editar mi lista de favoritos ===\n";
    int songId;
    std::cout << "Ingrese el ID de la canción a buscar: ";
    std::cin >> songId;

    Song* song = db.findSong(songId);
    iterCount.increment();

    if(!song) {
        std::cout << "Canción no encontrada.\n";
        iterCount.showMetrics("Editar favoritos - Búsqueda fallida");
        return;
    }

    std::cout << " - " << song->getName() << " (" << song->getDuration() << "s)\n";
    std::cout << "¿Desea (1) Agregar o (2) Eliminar esta canción de sus favoritos? ";
    int opt;
    std::cin >> opt;


    if (opt == 1) {
        if (user->getFavoriteCount() >= 10000) {
            std::cout << "Ha alcanzado el límite máximo de canciones favoritas (10000).\n";
        } else if (user->isFavorite(song)) {
            std::cout << "La canción ya está en su lista.\n";
        } else {
            user->addFavorite(song);
            std::cout << "Canción agregada a favoritos.\n";
        }
    } else if (opt == 2) {
        if (!user->isFavorite(song)) {
            std::cout << "La canción no estaba en su lista.\n";
        } else {
            user->removeFavorite(song);
            std::cout << "Canción eliminada de favoritos.\n";
        }
    } else {
        std::cout << "Opción inválida.\n";
    }

    iterCount.showMetrics("Editar mi lista de favoritos");
    MemoryTracker::showReport();

}

void AppMusic::followOtherList(User* user) {
    Counter iterCount;
    std::cout << "\n=== Seguir la lista de otro usuario ===\n";
    std::cout << "Ingrese el nombre del usuario a seguir: ";
    std::string nick;
    std::cin >> nick;

    User* other = db.findUser(nick);
    iterCount.increment();

    if (!other) {
        std::cout << "Usuario no encontrado.\n";
        iterCount.showMetrics("Seguir lista - Usuario no existe");
        return;
    }

    if (other == user) {
        std::cout << "No puede seguirse a sí mismo.\n";
        iterCount.showMetrics("Seguir lista - Operación invalida");
        return;
    }

    for (size_t i = 0; i < other->getFavoriteCount(); ++i) {
        Song* song = other->getFavorite(i);
        if (song && !user->isFavorite(song)) {
            user->addFavorite(song);
        }
        iterCount.increment();
    }

    std::cout << "Ahora sigue también la lista de " << other->getNick() << ".\n";
    iterCount.showMetrics("Seguir lista de favoritos");
    MemoryTracker::showReport();
}


void AppMusic::executeFavorites(User* user) {
    Counter iterCount;

    if (user->getFavoriteCount() == 0) {
        std::cout << "No tiene canciones en su lista de favoritos.\n";
        return;
    }

    std::cout << "\n=== Reproducir mi lista de favoritos ===\n";
    std::cout << "¿Desea reproducir en (1) orden original o (2) aleatorio? ";
    int opt;
    std::cin >> opt;

    PlaybackSession session(user, &db, false);
    const int M = 6;

    if (opt == 1)
        session.playFavorites(false, M);
    else
        session.playFavorites(true, M);

    iterCount.increment();
    iterCount.showMetrics("Reproducir lista de favoritos");
    MemoryTracker::showReport();
}


void AppMusic::manageFavorites(User* user) {
    if (!user) {
        return;
    }

    if (!user->isPremium()) {
        std::cout << "\nEsta funcionalidad solo está disponible para usuarios premium.\n";
        return;
    }

    int opt;
    do {
        std::cout << "\n====== Mi lista de favoritos ======\n";
        std::cout << "1. Editar mi lista de favoritos\n";
        std::cout << "2. Seguir lista de otro usuario\n";
        std::cout << "3. Reproducir mi lista de favoritos\n";
        std::cout << "4. Volver al menú principal\n";
        std::cout << "===================================\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opt;

        switch (opt) {
            case 1:
                editFavorites(user);
                break;
            case 2:
                followOtherList(user);
                break;
            case 3:
                executeFavorites(user);
                break;
            case 4:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
                break;
        }
    } while (opt != 4);

}

void AppMusic::userSession() {

    Counter iterCount;

    if (!currentUser) return;

    int opcion;
    do {

        iterCount.increment();

        std::cout << "\n====== Menú Principal ======\n";
        std::cout << "1. Ver información del usuario\n";
        std::cout << "2. Ver canciones favoritas\n";
        std::cout << "3. Reproducir canciones favoritas (Premium)\n";
        std::cout << "4. Reproducir canciones aleatorias\n";
        std::cout << "5. Mi lista de favoritos (Premium)\n";
        std::cout << "6. Cerrar sesión\n";
        std::cout << "============================\n\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: currentUser->show(); break;
            case 2: showFavorites(currentUser); break;
            case 3: runPlayback(currentUser, true); break;
            case 4: runPlayback(currentUser, false); break;
            case 5: manageFavorites(currentUser); break;
            case 6: std::cout << "Sesión cerrada.\n"; break;
            default: std::cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 6);

    // === Métricas ===
    iterCount.showMetrics("userSession()");
    MemoryTracker::showCurrentUsage("Memoria usada en userSession()");
}

void AppMusic::run()
{

    Counter iterCount;

    // 1. Cargar la base de datos
    db.loadFromFile("dataset.txt");
    iterCount.increment();

    db.showSummary();
    iterCount.increment();

    // 2. Menú de usuarios
    loginMenu();
    iterCount.increment();

    if(!currentUser) {
        return;
    }

    // 3. Menú de usuario
    userSession();
    iterCount.increment();

    // 4. Mostrar métricas globales
    MemoryTracker::showReport();
    iterCount.showMetrics("AppMusic::run()");
    MemoryTracker::showCurrentUsage("Memoria total al finalizar AppMusic::run()");



}
