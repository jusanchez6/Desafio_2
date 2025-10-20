#include <User.hpp>

User::User(const std::string& nick, bool premiumStatus, const std::string& city, const std::string& country, unsigned int signup_date) 
: nickname(nick), premium(premiumStatus), city(city), country(country), signup_date(signup_date), following(nullptr)
{
}

User::~User() {
    favorites.clear();
}

void User::addFavorite(Song* s) {
    favorites.push_back(s);
}

void User::playFavorites(bool shuffle) {
    
    if (favorites.getSize() == 0) {
        std::cout << "No hay canciones en la lista de favoritos.\n";
        return;
    }

    // falta mensaje de confirmación:
    if (shuffle) {
        size_t idx = std::rand() % favorites.getSize();
        favorites[idx]->play(premium ? 320 : 128);
    } else {
        for (size_t i = 0; i < favorites.getSize(); ++i) {
            favorites[i]->play(premium ? 320 : 128);
        }
    }

}

void User::follow(User* other) {
    if (other == nullptr) {
        std::cout << "Usario invalido para seguir.\n";
        return;
    }

    if (other == this) {
        std::cout << "Debes elegir otro usuario para seguir.\n";
        return;
    }

    following = other;
    std::cout << nickname << "Ahora sigue a " << other->getNick() << " 🎵\n";
}


bool User::isPremium() const {return premium; }
const std::string& User::getNick() const {return nickname; }
const std::string& User::getCity() const {return city; }
const std::string& User::getCountry() const {return country; }
unsigned int User::getSignupDate() const {return signup_date; }
size_t User::getFavoriteCount() const {return favorites.getSize(); }


// función debug para mostrar información:

void User::show() const {
    std::cout << "\n=== Usuario ===\n";
    std::cout << "Nickname: " << nickname
              << "\nTipo de cuenta: " << (premium ? "Premium" : "Standard")
              << "\nCiudad: " << city
              << "\nPaís: " << country
              << "\nFecha de registro: " << signup_date
              << "\nFavoritos: " << favorites.getSize() << std::endl;

    if (following)
        std::cout << "Siguiendo a: " << following->getNick() << std::endl;
}
