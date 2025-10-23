#ifndef SONG_HPP
#define SONG_HPP

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

#include <DynamicArray.hpp>
#include <Credit.hpp>


#define DURATION_MS 5000
#define DURATION_MIN 3


class Song
{
private:
    int id;
    int duration;
    std::string name;
    std::string path;
    unsigned int playCount;


    DynamicArray<Credit*> producers;
    DynamicArray<Credit*> musicians;
    DynamicArray<Credit*> composers;
    


public:
    Song(int id, const std::string& name, int duration, const std::string& path);

    ~Song();

    // metofdos funcioanles
    void play(int kbps);
    void addProducer(Credit* c);
    void addMusician(Credit* c);
    void addComposer(Credit* c);
    

    // metodos de acceso
    int getId() const;
    const std::string& getName() const;
    const std::string& getPath() const;
    unsigned int getPlayCount() const;
    int getDuration() const;

    const DynamicArray<Credit*>& getProducers() const { return producers; }
    const DynamicArray<Credit*>& getMusicians() const { return musicians; }
    const DynamicArray<Credit*>& getComposers() const { return composers; }



    void show();

};


#endif