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

void PlaybackSession::playFavorites(bool shuffle) {
    if (!user) {
        std::cout << "No hay usuario logueado." << std::endl;
        return;
    }

    std::cout << "\nReproduciendo favoritos de " << user->getNick()
              << (shuffle ? " (modo aleatorio)" : "") << std::endl;

    size_t favCount = user->getFavoriteCount();
    if (favCount == 0) {
        std::cout << "El usuario no tiene canciones favoritas." << std::endl;
        return;
    }

    for (size_t i = 0; i < favCount; ++i) {
        size_t index = shuffle ? (std::rand() % favCount) : i;
        Song* s = user->getFavorite(index);

        if (s) {
            s->play(user->isPremium() ? 320 : 128);
            addToHistory(s->getId());
            songsPlayed++;
            maybeShowAd();
        }
    }
}


// debug
void PlaybackSession::showMetrics() const {
    std::cout << "\n=== Métricas de sesión ===" << std::endl;
    std::cout << "Usuario: " << (user ? user->getNick() : "Desconocido")
              << "\nCanciones reproducidas: " << songsPlayed
              << "\nAnuncios mostrados: " << adsShown
              << "\nHistorial guardado: " << history.getSize() << " canciones" << std::endl;
}
