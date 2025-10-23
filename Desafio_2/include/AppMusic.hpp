#ifndef AppMusic_HPP
#define AppMusic_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <Database.hpp>
#include <PlaybackSession.hpp>
#include <MemoryTracker.hpp>
#include <Counter.hpp>

class AppMusic
{
private:
    /* data */
    Database db;
    User* currentUser;


    void loadAllData();
    void loginMenu();
    void userSession();
    void ShowFollowed(User* user);
    void showFavorites(User *user);
    void runPlayback(User* user, bool playFavorites);

public:
    AppMusic();
    void run();
};

#endif //AppMusic_hpp
