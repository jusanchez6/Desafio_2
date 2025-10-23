/**
 * @file Song.hpp
 * @brief Declaración de la clase Song que representa una canción musical.
 *
 * Esta clase almacena información de una canción, incluyendo identificador,
 * nombre, duración, ruta de archivo, contador de reproducciones y créditos
 * asociados (productores, músicos y compositores). Proporciona métodos para
 * reproducir la canción y gestionar sus créditos.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
*/

#ifndef SONG_HPP
#define SONG_HPP

#include <string>
#include <iostream>
#include <thread>
#include <chrono>

#include <DynamicArray.hpp>
#include <Credit.hpp>

#define DURATION_MS 5000  ///< Duración estándar en milisegundos para simulación de reproducción.
#define DURATION_MIN 3    ///< Duración mínima en minutos por defecto.

/**
 * @class Song
 * @brief Representa una canción con su información y créditos asociados.
 *
 * La clase Song permite reproducir canciones, almacenar sus créditos y
 * consultar sus propiedades como duración, nombre, ruta y número de reproducciones.
 */
class Song
{
private:
    int id;                 ///< Identificador único de la canción.
    int duration;           ///< Duración de la canción en segundos.
    std::string name;       ///< Nombre de la canción.
    std::string path;       ///< Ruta del archivo de la canción.
    unsigned int playCount; ///< Contador de reproducciones.

    DynamicArray<Credit*> producers; ///< Créditos de los productores.
    DynamicArray<Credit*> musicians; ///< Créditos de los músicos.
    DynamicArray<Credit*> composers; ///< Créditos de los compositores.

public:
    /**
     * @brief Constructor con parámetros.
     *
     * Crea una canción con los valores especificados.
     *
     * @param id Identificador único de la canción.
     * @param name Nombre de la canción.
     * @param duration Duración de la canción en segundos.
     * @param path Ruta del archivo de la canción.
     */
    Song(int id, const std::string& name, int duration, const std::string& path);

    /**
     * @brief Destructor de la canción.
     */
    ~Song();

    // Métodos funcionales
    /**
     * @brief Reproduce la canción simulando el tiempo de reproducción.
     * @param kbps Calidad de reproducción en kbps (simulada).
     */
    void play(int kbps);

    /**
     * @brief Agrega un productor a la canción.
     * @param c Puntero al crédito del productor.
     */
    void addProducer(Credit* c);

    /**
     * @brief Agrega un músico a la canción.
     * @param c Puntero al crédito del músico.
     */
    void addMusician(Credit* c);

    /**
     * @brief Agrega un compositor a la canción.
     * @param c Puntero al crédito del compositor.
     */
    void addComposer(Credit* c);

    // Métodos de acceso
    /**
     * @brief Obtiene el identificador de la canción.
     * @return Identificador único.
     */
    int getId() const;

    /**
     * @brief Obtiene el nombre de la canción.
     * @return Referencia constante al nombre.
     */
    const std::string& getName() const;

    /**
     * @brief Obtiene la ruta del archivo de la canción.
     * @return Referencia constante a la ruta.
     */
    const std::string& getPath() const;

    /**
     * @brief Obtiene el número de reproducciones de la canción.
     * @return Cantidad de veces reproducida.
     */
    unsigned int getPlayCount() const;

    /**
     * @brief Obtiene la duración de la canción.
     * @return Duración en segundos.
     */
    int getDuration() const;

    /**
     * @brief Obtiene los productores asociados a la canción.
     * @return Referencia constante al arreglo dinámico de productores.
     */
    const DynamicArray<Credit*>& getProducers() const { return producers; }

    /**
     * @brief Obtiene los músicos asociados a la canción.
     * @return Referencia constante al arreglo dinámico de músicos.
     */
    const DynamicArray<Credit*>& getMusicians() const { return musicians; }

    /**
     * @brief Obtiene los compositores asociados a la canción.
     * @return Referencia constante al arreglo dinámico de compositores.
     */
    const DynamicArray<Credit*>& getComposers() const { return composers; }

    /**
     * @brief Muestra la información completa de la canción por consola.
     */
    void show();
};

#endif
