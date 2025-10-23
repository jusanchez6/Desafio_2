/**
 * @file PlaybackSession.cpp
 * @brief Implementación de la clase PlaybackSession.
 *
 * Contiene los métodos para reproducir canciones, administrar historial,
 * mostrar anuncios y medir métricas de la sesión.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#include <PlaybackSession.hpp>

PlaybackSession::PlaybackSession(User *u, Database *d, bool repeat)
    : user(u), db(d), repeat(repeat), lastAdIndex(-1), songsPlayed(0), adsShown(0)
{
    std::srand(std::time(nullptr));
}

void PlaybackSession::addToHistory(int songId) {
    history.push_back(songId);
}

void PlaybackSession::maybeShowAd() {
    if (user->isPremium()) {
        return; // solo mostrar a no-premium
    }

    // Mostrar anuncio cada 2 canciones
    if (songsPlayed % 2 == 0) {
        DynamicArray<AdMessage*>& ads = db->getAds();
        if (ads.getSize() == 0) return;

        lastAdIndex = (lastAdIndex + 1) % ads.getSize();
        AdMessage* ad = ads[lastAdIndex];

        std::cout << "\n[ANUNCIO - " << ad->getCategory() << "] "
                  << ad->getText() << std::endl;

        adsShown++;
    }
}

void PlaybackSession::playRandom(int K) {
    if (!db) {
        std::cout << "No hay base de datos cargada." << std::endl;
        return;
    }

    DynamicArray<Song*>& songs = db->getSongs();
    size_t songCount = songs.getSize();

    if (songCount == 0) {
        std::cout << "No hay canciones disponibles." << std::endl;
        return;
    }

    std::cout << "\nReproduciendo " << K << " canciones aleatorias..." << std::endl;

    for (int i = 0; i < K; ++i) {
        int index = std::rand() % songCount;
        Song* s = songs[index];

        if (s) {
            s->play(user->isPremium() ? 320 : 128);
            addToHistory(s->getId());
            songsPlayed++;
            maybeShowAd();
        }
    }

    if (repeat) {
        std::cout << "\nRepetición activada, repitiendo lista..." << std::endl;
        playRandom(K);
    }
}

void PlaybackSession::playFavorites(bool shuffle, int maxBack) {
    if (!user) {
        std::cout << "No hay usuario logueado." << std::endl;
        return;
    }

    std::cout << "\nReproduciendo favoritos de " << user->getNick()
              << (shuffle ? " (modo aleatorio)" : "") << std::endl;

    int favCount = user->getFavoriteCount();
    if (favCount == 0) {
        std::cout << "El usuario no tiene canciones favoritas." << std::endl;
        return;
    }

    // Crear una copia de las canciones favoritas
    Song** playlist = new Song*[favCount];
    for (int i = 0; i < favCount; ++i) {
        playlist[i] = user->getFavorite(i);
    }

    // Si se elige modo aleatorio, hacer shuffle manual
    if (shuffle) {
        for (int i = 0; i < favCount - 1; ++i) {
            int j = std::rand() % favCount;
            Song* temp = playlist[i];
            playlist[i] = playlist[j];
            playlist[j] = temp;
        }
    }

    int history[10000]; // hasta 10k canciones reproducidas
    int historyCount = 0;

    int currentIndex = 0;
    while (currentIndex < favCount) {
        Song* s = playlist[currentIndex];
        if (s) {
            s->play(user->isPremium() ? 320 : 128);
            addToHistory(s->getId());
            history[historyCount++] = currentIndex;
            songsPlayed++;
            maybeShowAd();
        }

        std::cout << "\n¿Desea (1) siguiente, (2) retroceder, (3) salir? ";
        int opt;
        std::cin >> opt;

        if (opt == 1) {
            currentIndex++;
        } else if (opt == 2) {
            if (historyCount <= 1) {
                std::cout << "No hay canciones previas.\n";
            } else {
                int stepsBack;
                std::cout << "¿Cuántas canciones desea retroceder? (máx " << maxBack << "): ";
                std::cin >> stepsBack;

                if (stepsBack < 1) stepsBack = 1;
                if (stepsBack > maxBack) stepsBack = maxBack;

                if (historyCount > stepsBack) {
                    currentIndex = history[historyCount - 1 - stepsBack];
                    historyCount -= stepsBack; // “retroceder” historial
                } else {
                    currentIndex = 0;
                    historyCount = 0;
                }
            }
        } else if (opt == 3) {
            std::cout << "Reproducción detenida por el usuario.\n";
            break;
        } else {
            std::cout << "Opción inválida, avanzando...\n";
            currentIndex++;
        }
    }

    std::cout << "\nFin de la lista de reproducción.\n";

    delete[] playlist; // liberar memoria dinámica
}



// debug
void PlaybackSession::showMetrics() const {
    std::cout << "\n=== Métricas de sesión ===" << std::endl;
    std::cout << "Usuario: " << (user ? user->getNick() : "Desconocido")
              << "\nCanciones reproducidas: " << songsPlayed
              << "\nAnuncios mostrados: " << adsShown
              << "\nHistorial guardado: " << history.getSize() << " canciones" << std::endl;
}
