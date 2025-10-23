/**
 * @file MemoryTracker.hpp
 * @brief Declaración de la clase MemoryTracker para monitorear uso de memoria.
 *
 * Esta clase permite llevar un registro global del uso de memoria en la aplicación,
 * controlando las asignaciones, liberaciones y proporcionando reportes detallados.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef MEMORYTRACKER_HPP
#define MEMORYTRACKER_HPP

#include <iostream>
#include <cstddef>
#include <mutex>

/**
 * @class MemoryTracker
 * @brief Monitorea las asignaciones y liberaciones de memoria del sistema.
 *
 * MemoryTracker registra el total de memoria asignada, liberada y la memoria
 * actualmente en uso. También ofrece métodos para mostrar reportes y métricas
 * de uso de memoria.
 */
class MemoryTracker
{
private:
    static size_t totalAllocated; ///< Total de memoria asignada desde el inicio.
    static size_t totalFreed; ///< Total de memoria liberada desde el inicio.
    static size_t currentUsage; ///< Memoria actualmente en uso.
    static std::mutex mtx; ///< Mutex para proteger accesos concurrentes.

    /**
     * @brief Constructor privado.
     *
     * Evita instanciación de la clase ya que todos los métodos son estáticos.
     */
    MemoryTracker();

public:
    /**
     * @brief Registra una nueva asignación de memoria.
     * @param bytes Cantidad de bytes asignados.
     */
    static void addAllocation(size_t bytes);

    /**
     * @brief Registra una liberación de memoria.
     * @param bytes Cantidad de bytes liberados.
     */
    static void addDeallocation(size_t bytes);

    /**
     * @brief Obtiene la cantidad total de memoria asignada.
     * @return Total de bytes asignados.
     */
    static size_t getTotalAllocated();

    /**
     * @brief Obtiene la cantidad total de memoria liberada.
     * @return Total de bytes liberados.
     */
    static size_t getTotalFreed();

    /**
     * @brief Obtiene la memoria actualmente en uso.
     * @return Bytes de memoria actualmente en uso.
     */
    static size_t getCurrentUsage();

    /**
     * @brief Muestra un reporte completo del uso de memoria.
     */
    static void showReport();

    /**
     * @brief Muestra la memoria actualmente en uso junto con un contexto.
     * @param context Texto descriptivo opcional que indica el módulo o función.
     */
    static void showCurrentUsage(const std::string& context);
};

#endif // MEMORYTRACKER_HPP
