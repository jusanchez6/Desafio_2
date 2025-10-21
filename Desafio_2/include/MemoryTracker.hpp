#ifndef MEMORYTRACKER_HPP
#define MEMORYTRACKER_HPP

#include <iostream>
#include <cstddef>
#include <mutex>


class MemoryTracker
{
private:
    /* data */
    static size_t totalAllocated;
    static size_t totalFreed;
    static size_t currentUsage;
    static std::mutex mtx;

    MemoryTracker(/* args */);



public:
    static void addAllocation(size_t bytes);
    static void addDeallocation(size_t bytes);

    static size_t getTotalAllocated();
    static size_t getTotalFreed();
    static size_t getCurrentUsage();


    static void showReport();
};

#endif