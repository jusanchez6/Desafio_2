/**
 * @file Counter.hpp
 * @brief Declaración de la clase Counter que registra operaciones o eventos.
 *
 * Esta clase proporciona una forma sencilla de contar operaciones realizadas
 * dentro del sistema, permitiendo incrementar, reiniciar y mostrar el contador.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream>

/**
 * @class Counter
 * @brief Contador simple de operaciones o métricas del sistema.
 *
 * La clase Counter permite llevar el registro del número de operaciones,
 * con funciones para incrementarlo, reiniciarlo y visualizar su valor.
 */
class Counter {
private:
    int count; ///< Número de operaciones registradas.

public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa el contador en cero.
     */
    Counter();

    /**
     * @brief Incrementa el contador en una unidad.
     */
    void increment();

    /**
     * @brief Reinicia el contador a cero.
     */
    void reset();

    /**
     * @brief Obtiene el valor actual del contador.
     * @return Valor entero del contador.
     */
    int getCount() const;

    /**
     * @brief Muestra las métricas actuales por consola.
     *
     * Imprime el valor del contador junto a un contexto opcional.
     *
     * @param context Texto descriptivo opcional que identifica el uso del contador.
     */
    void showMetrics(const std::string& context = "") const;
};

#endif // COUNTER_HPP
