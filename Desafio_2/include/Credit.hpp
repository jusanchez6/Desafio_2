/**
 * @file Credit.hpp
 * @brief Declaración de la clase Credit que almacena información de crédito o autoría.
 *
 * Esta clase contiene datos personales básicos como nombre, apellido y un código 
 * identificador, utilizados para representar información de crédito o autoría en el sistema.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef CREDIT_HPP
#define CREDIT_HPP

#include <string>
#include <cstring>
#include <iostream>

/**
 * @class Credit
 * @brief Representa la información de crédito o autoría de una persona.
 *
 * La clase Credit almacena el nombre, apellido y un código identificador
 * de hasta 10 caracteres, permitiendo su visualización y consulta.
 */
class Credit
{
private:
    std::string name;               ///< Nombre de la persona.
    std::string surname;            ///< Apellido de la persona.
    char code[11];                  ///< Código identificador (máximo 10 caracteres más terminador nulo).

public:
    /**
     * @brief Constructor con parámetros.
     *
     * Crea un objeto Credit con la información proporcionada.
     *
     * @param nom Nombre de la persona.
     * @param apen Apellido de la persona.
     * @param cod Código identificador.
     */
    Credit(const std::string& nom, const std::string& apen, const std::string& cod);

    /**
     * @brief Obtiene el nombre de la persona.
     * @return Referencia constante al nombre.
     */
    const std::string& getName() const;

    /**
     * @brief Obtiene el apellido de la persona.
     * @return Referencia constante al apellido.
     */
    const std::string& getSurname() const;

    /**
     * @brief Obtiene el código identificador.
     * @return Puntero constante al código (cadena C).
     */
    const char* getCode() const;

    /**
     * @brief Muestra la información del crédito por consola.
     *
     * Imprime el nombre, apellido y código del crédito.
     */
    void show() const;
};

#endif // CREDIT_HPP
