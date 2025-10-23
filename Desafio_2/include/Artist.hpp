/**
 * @file Artist.hpp
 * @brief Declaración de la clase Artist que representa a un artista musical.
 *
 * Esta clase define la estructura y comportamiento de un artista, incluyendo
 * su información personal y la lista de álbumes asociados.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <string>
#include <iostream>
#include "DynamicArray.hpp"
#include "Album.hpp"

/**
 * @class Artist
 * @brief Representa un artista musical y sus álbumes asociados.
 *
 * La clase Artist almacena información como el nombre, país de origen,
 * edad e identificador del artista, además de administrar su colección de álbumes.
 */
class Artist {
private:
    int id;                         ///< Identificador único del artista.
    unsigned char age;              ///< Edad del artista.
    std::string name;               ///< Nombre del artista.
    std::string country;            ///< País de origen del artista.
    DynamicArray<Album*> albums;    ///< Lista de álbumes asociados al artista.

public:
    /**
     * @brief Constructor con parámetros.
     *
     * Crea un artista con la información especificada.
     *
     * @param id Identificador único del artista.
     * @param age Edad del artista.
     * @param name Nombre del artista.
     * @param country País de origen del artista.
     */
    Artist(int id, unsigned char age, const std::string& name, const std::string& country);

    /**
     * @brief Destructor del artista.
     *
     * Libera los recursos asociados al objeto.
     */
    ~Artist();

    /**
     * @brief Agrega un álbum al artista.
     * @param album Puntero al álbum que se desea asociar al artista.
     */
    void addAlbum(Album* album);

    /**
     * @brief Obtiene un álbum del artista por su identificador.
     * @param id Identificador del álbum.
     * @return Puntero al álbum encontrado, o nullptr si no existe.
     */
    Album* getAlbum(int id);

    /**
     * @brief Obtiene el identificador del artista.
     * @return Identificador único del artista.
     */
    int getId() const;

    /**
     * @brief Obtiene la edad del artista.
     * @return Edad del artista.
     */
    unsigned char getAge() const;

    /**
     * @brief Obtiene el nombre del artista.
     * @return Referencia constante al nombre del artista.
     */
    const std::string& getName() const;

    /**
     * @brief Obtiene el país de origen del artista.
     * @return Referencia constante al país del artista.
     */
    const std::string& getCountry() const;

    /**
     * @brief Obtiene la cantidad de álbumes asociados al artista.
     * @return Número de álbumes.
     */
    size_t getAlbumCount() const;

    /**
     * @brief Muestra la información general del artista.
     *
     * Imprime los datos principales del artista y su lista de álbumes.
     */
    void show() const;
};

#endif // ARTIST_HPP
