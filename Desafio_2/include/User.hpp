#ifndef USER_HPP
#define USER_HPP


#include <string>
#include <iostream>
#include <cstdlib>

#include <DynamicArray.hpp>
#include <Song.hpp>

class User
{
private:

    std::string nickname;
    bool premium;
    std::string city;
    std::string country;
    unsigned int signup_date;
    DynamicArray<Song*> favorites;
    User* following;

public:
    User(const std::string& nick, bool premiumStatus, const std::string& city, const std::string& country, unsigned int signup_date);

    ~User();

    // funcionales
    void addFavorite(Song* s);
    void playFavorites(bool shuffle = false);
    void follow(User* other);


    // getters
    bool isPremium() const;
    const std::string& getNick() const;
    const std::string& getCity() const;
    const std::string& getCountry() const;
    unsigned int getSignupDate() const;
    size_t getFavoriteCount() const;


    // test
    void show() const;


};




#endif
