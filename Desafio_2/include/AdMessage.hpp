/**
 * @file AdMessage.hpp
 * @brief Declaración de la clase AdMessage que representa un mensaje publicitario.
 *
 * Esta clase define la estructura y las funciones necesarias para manejar 
 * mensajes publicitarios con texto, categoría y peso o prioridad. 
 * Incluye métodos para establecer, obtener y mostrar la información del anuncio.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef ADMESSAGE_HPP
#define ADMESSAGE_HPP

#include <string>
#include <iostream>

/**
 * @class AdMessage
 * @brief Representa un mensaje publicitario con texto, categoría y peso.
 *
 * La clase AdMessage permite crear, modificar y visualizar mensajes publicitarios 
 * que contienen un texto, una categoría (por ejemplo, C, B, AAA) y un peso 
 * o prioridad asociados.
 */
class AdMessage {
private:
    std::string text;  ///< Texto del anuncio.
    char category;     ///< Categoría del anuncio (por ejemplo, 'C', 'B', 'A').
    int weight;        ///< Peso o prioridad del anuncio.

public:

    /**
     * @brief Constructor por defecto.
     * 
     * Inicializa los atributos con valores por defecto.
     */
    AdMessage();

    /**
     * @brief Constructor con parámetros.
     * 
     * @param text Texto del anuncio.
     * @param category Categoría del anuncio.
     * @param weight Peso o prioridad del anuncio.
     */
    AdMessage(const std::string& text, char category, int weight);

    /**
     * @brief Establece el texto del anuncio.
     * 
     * @param t Nuevo texto del anuncio.
     */
    void setText(const std::string& t);

    /**
     * @brief Establece la categoría del anuncio.
     * 
     * @param c Nueva categoría del anuncio.
     */
    void setCategory(char c);

    /**
     * @brief Establece el peso o prioridad del anuncio.
     * 
     * @param w Nuevo peso o prioridad del anuncio.
     */
    void setWeight(int w);

    /**
     * @brief Obtiene el texto del anuncio.
     * 
     * @return Referencia constante al texto del anuncio.
     */
    const std::string& getText() const;

    /**
     * @brief Obtiene la categoría del anuncio.
     * 
     * @return Categoría del anuncio.
     */
    char getCategory() const;

    /**
     * @brief Obtiene el peso o prioridad del anuncio.
     * 
     * @return Peso o prioridad del anuncio.
     */
    int getWeight() const;

    /**
     * @brief Muestra la información del anuncio por consola.
     * 
     * Imprime el texto, categoría y peso del anuncio.
     */
    void show() const;
};

#endif
