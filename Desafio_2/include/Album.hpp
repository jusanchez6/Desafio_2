/**
 * @file Album.hpp
 * @brief Declaración de la clase Album que representa un álbum musical.
 *
 * Esta clase define la estructura y comportamiento de un álbum musical, 
 * que contiene información como el nombre, sello discográfico, género, 
 * fecha de lanzamiento y una lista dinámica de canciones.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include <iostream>
#include <DynamicArray.hpp>
#include <Song.hpp>

/**
 * @class Album
 * @brief Representa un álbum musical compuesto por varias canciones.
 *
 * La clase Album administra una colección de canciones, junto con su 
 * información asociada, como el nombre, sello discográfico, género, 
 * fecha de lanzamiento e identificador único.
 */
class Album
{
private:
    int id;                         ///< Identificador único del álbum.
    std::string name;               ///< Nombre del álbum.
    std::string label;              ///< Sello discográfico.
    DynamicArray<Song*> songs;      ///< Lista dinámica de canciones pertenecientes al álbum.
    unsigned char genrer_mask;      ///< Máscara que representa los géneros del álbum.
    unsigned int release_date;      ///< Fecha de lanzamiento del álbum (formato numérico).

public:
    /**
     * @brief Constructor con parámetros.
     *
     * Crea un objeto Album con los valores especificados.
     *
     * @param id Identificador único del álbum.
     * @param name Nombre del álbum.
     * @param label Sello discográfico.
     * @param genrer_mask Máscara de géneros del álbum.
     * @param release_date Fecha de lanzamiento del álbum.
     */
    Album(int id, const std::string& name, const std::string& label, unsigned char genrer_mask, unsigned int release_date);

    /**
     * @brief Destructor del álbum.
     *
     * Libera los recursos asociados, como la lista de canciones.
     */
    ~Album();

    /**
     * @brief Agrega una canción al álbum.
     *
     * @param s Puntero a la canción que se desea agregar.
     */
    void addSong(Song* s);

    /**
     * @brief Calcula la duración total del álbum.
     *
     * Suma la duración de todas las canciones contenidas en el álbum.
     *
     * @return Duración total en segundos.
     */
    int totalDuration() const;

    /**
     * @brief Obtiene el identificador del álbum.
     * @return Identificador único del álbum.
     */
    int getId() const;

    /**
     * @brief Obtiene el nombre del álbum.
     * @return Referencia constante al nombre del álbum.
     */
    const std::string& getName() const;

    /**
     * @brief Obtiene el sello discográfico del álbum.
     * @return Referencia constante al sello discográfico.
     */
    const std::string& getLabel() const;

    /**
     * @brief Obtiene la fecha de lanzamiento del álbum.
     * @return Fecha de lanzamiento en formato numérico.
     */
    unsigned int getReleaseDate() const;

    /**
     * @brief Obtiene la máscara de género del álbum.
     * @return Máscara de géneros representada por un valor de tipo unsigned char.
     */
    unsigned char getGenderMAsl() const;

    /**
     * @brief Muestra la información del álbum por consola.
     *
     * Imprime los datos principales del álbum y la información de sus canciones.
     */
    void show() const;
};

#endif // ALBUM_HPP
