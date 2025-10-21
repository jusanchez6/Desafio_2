#include <MemoryTracker.hpp>

size_t MemoryTracker::totalAllocated = 0;
size_t MemoryTracker::totalFreed = 0;
size_t MemoryTracker::currentUsage = 0;
std::mutex MemoryTracker::mtx;


void MemoryTracker::addAllocation(size_t bytes) {
    std::lock_guard<std::mutex> lock(mtx);
    totalAllocated += bytes;
    currentUsage += bytes;
}

void MemoryTracker::addDeallocation(size_t bytes) {
    std::lock_guard<std::mutex> lock(mtx);
    totalFreed += bytes;

    if (currentUsage >= bytes) {
        currentUsage -= bytes;
    } else {
        currentUsage = 0;
    }
}

size_t MemoryTracker::getTotalAllocated() {return totalAllocated; }
size_t MemoryTracker::getTotalFreed() {return totalFreed; }
size_t MemoryTracker::getCurrentUsage() {return currentUsage; }


void MemoryTracker::showReport() {
    std::cout << "\n==== Reporte de Uso de Memoria ====" << std::endl;
    std::cout << "Total reservado:   " << totalAllocated << " bytes" << std::endl;
    std::cout << "Total liberado:    " << totalFreed << " bytes" << std::endl;
    std::cout << "Uso actual:        " << currentUsage << " bytes" << std::endl;
}
