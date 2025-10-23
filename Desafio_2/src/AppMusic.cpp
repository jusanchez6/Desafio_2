#include <AppMusic.hpp>

AppMusic::AppMusic() : currentUser(nullptr) {}

void AppMusic::loginMenu()
{
    std::cout << "====== Inicio de Sesión ======\n";
    std::cout << "Usuarios disponibles: \n";

    // Mostrar los usuarios
    for (size_t i = 0; i < db.getUsers().getSize(); ++i)
    {
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
}

void AppMusic::runPlayback(User *user, bool playFavorites)
{
    PlaybackSession session(user, &db, false);
    if (playFavorites)
        session.playFavorites(true);
    else
        session.playRandom(3);

    session.showMetrics();
}

void AppMusic::ShowFollowed(User* user) {

}


void showFavorites(User* user) {
    
}

void AppMusic::userSession() {
    if (!currentUser) return;

    int opcion;
    do {
        std::cout << "\n====== Menú Principal ======\n";
        std::cout << "1. Ver información del usuario\n";
        std::cout << "2. Ver canciones favoritas\n";
        std::cout << "3. Reproducir canciones favoritas\n";
        std::cout << "4. Reproducir canciones aleatorias\n";
        std::cout << "5. Cerrar sesión\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: currentUser->show(); break;
            case 2: showFavorites(currentUser); break;
            case 3: runPlayback(currentUser, true); break;
            case 4: runPlayback(currentUser, false); break;
            case 5: std::cout << "Sesión cerrada.\n"; break;
            default: std::cout << "Opción inválida.\n"; break;
        }

    } while (opcion != 5);
}

void AppMusic::run()
{

    // 1. Cargar la base de datos
    db.loadFromFile("dataset.txt");
    db.showSummary();

    // 2. Desplegar el menú de usuarios registrados
    loginMenu();

    // 3. revisar si tenemos un usuario logueado y mostrarle menu de usuario
    if(!currentUser) {
        return;
    }

    userSession();


}
