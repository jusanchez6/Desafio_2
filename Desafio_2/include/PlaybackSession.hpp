#ifndef PLAYBACKSESSION_HPP
#define PLAYBACKSESSION_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <DynamicArray.hpp>
#include <User.hpp>
#include <Database.hpp>
#include <AdMessage.hpp>


class PlaybackSession
{
private:
    
    // atributos de sesion
    User* user;
    Database* db;
    DynamicArray<int> history;
    bool repeat;
    int lastAdIndex;

    // metricas
    int songsPlayed;
    int adsShown;

    // metodos privados
    void maybeShowAd();
    void addToHistory(int songId);



public:

    // constructor
    PlaybackSession(User* u, Database* d, bool repeat = false);
    
    // funcionalidades
    void playRandom(int K);
    void playFavorites(bool shuffle, int maxBack);

    

    // debug
    void showMetrics() const;
};

#endif