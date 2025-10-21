#include "MemoryTracker.hpp"
#include <new>     // std::bad_alloc
#include <cstdlib> // malloc, free

void* operator new(size_t size) {
    void* ptr = std::malloc(size);
    if (!ptr) throw std::bad_alloc();
    MemoryTracker::addAllocation(size);
    return ptr;
}

void operator delete(void* ptr) noexcept {
    if (!ptr) return;
    // No sabemos el tamaño exacto, registramos 0 o tamaño simbólico
    MemoryTracker::addDeallocation(0);
    std::free(ptr);
}

void operator delete[](void* ptr) noexcept {
    if (!ptr) return;
    MemoryTracker::addDeallocation(0);
    std::free(ptr);
}
