/**
 * @file MemoryTrackerOverrides.cpp
 * @brief Sobrecarga global de operadores new y delete para seguimiento de memoria.
 *
 * Este archivo redefine los operadores globales new y delete para interceptar
 * todas las asignaciones y liberaciones de memoria, registrándolas en la clase
 * MemoryTracker.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#include "MemoryTracker.hpp"
#include <new>     
#include <cstdlib> 

/**
 * @brief Sobrecarga del operador new global.
 *
 * Asigna memoria dinámica utilizando malloc y registra la asignación en MemoryTracker.
 *
 * @param size Tamaño en bytes a asignar.
 * @return Puntero a la memoria asignada.
 * @throws std::bad_alloc Si la asignación falla.
 */
void* operator new(size_t size) {
    void* ptr = std::malloc(size);
    if (!ptr) throw std::bad_alloc();
    MemoryTracker::addAllocation(size);
    return ptr;
}

/**
 * @brief Sobrecarga del operador delete global.
 *
 * Libera memoria dinámica utilizando free y registra la liberación en MemoryTracker.
 *
 * @param ptr Puntero a la memoria a liberar.
 */
void operator delete(void* ptr) noexcept {
    if (!ptr) return;
    // No se conoce el tamaño exacto, se registra simbólicamente 0.
    MemoryTracker::addDeallocation(0);
    std::free(ptr);
}

/**
 * @brief Sobrecarga del operador delete[] global.
 *
 * Libera memoria dinámica de arreglos y registra la liberación en MemoryTracker.
 *
 * @param ptr Puntero al arreglo a liberar.
 */
void operator delete[](void* ptr) noexcept {
    if (!ptr) return;
    MemoryTracker::addDeallocation(0);
    std::free(ptr);
}
