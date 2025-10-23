/**
 * @file Database.hpp
 * @brief Declaración de la clase Database que administra los datos principales del sistema.
 *
 * Esta clase centraliza el manejo de usuarios, artistas, álbumes, canciones y anuncios,
 * proporcionando métodos para cargar, guardar y buscar información dentro de la base de datos.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <DynamicArray.hpp>
#include <User.hpp>
#include <Artist.hpp>
#include <Album.hpp>
#include <Song.hpp>
#include <AdMessage.hpp>

/**
 * @class Database
 * @brief Administra la información principal de la aplicación musical.
 *
 * La clase Database almacena y gestiona colecciones de usuarios, artistas, álbumes,
 * canciones y mensajes publicitarios. Permite cargar datos de prueba, guardar en archivo
 * y realizar búsquedas dentro del sistema.
 */
class Database
{
private:
    DynamicArray<User*> users;          ///< Lista de usuarios registrados.
    DynamicArray<Artist*> artists;      ///< Lista de artistas.
    DynamicArray<Album*> albums;        ///< Lista de álbumes.
    DynamicArray<Song*> songs;          ///< Lista de canciones.
    DynamicArray<AdMessage*> ads;       ///< Lista de anuncios publicitarios.

public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa las estructuras de datos de la base.
     */
    Database();

    /**
     * @brief Destructor.
     *
     * Libera la memoria asociada a los objetos almacenados.
     */
    ~Database();

    /**
     * @brief Carga datos de ejemplo en la base de datos.
     *
     * Útil para pruebas o demostraciones.
     */
    void loadDummyData();

    /**
     * @brief Guarda la información actual en un archivo.
     */
    void saveData();

    /**
     * @brief Carga la información desde un archivo.
     * @param filename Nombre del archivo desde el cual se cargarán los datos.
     */
    void loadFromFile(const std::string& filename);

    /**
     * @brief Busca un usuario por su nombre de usuario.
     * @param nick Nombre de usuario a buscar.
     * @return Puntero al usuario encontrado o nullptr si no existe.
     */
    User* findUser(const std::string& nick);

    /**
     * @brief Busca una canción por su identificador.
     * @param id Identificador de la canción.
     * @return Puntero a la canción encontrada o nullptr si no existe.
     */
    Song* findSong(int id);

    /**
     * @brief Obtiene la lista de canciones almacenadas.
     * @return Referencia al arreglo dinámico de canciones.
     */
    DynamicArray<Song*>& getSongs();

    /**
     * @brief Obtiene la lista de anuncios almacenados.
     * @return Referencia al arreglo dinámico de anuncios.
     */
    DynamicArray<AdMessage*>& getAds();

    /**
     * @brief Obtiene la lista de usuarios registrados.
     * @return Referencia al arreglo dinámico de usuarios.
     */
    DynamicArray<User*>& getUsers();

    /**
     * @brief Muestra un resumen general de la base de datos.
     *
     * Imprime información de conteo o resumen de los elementos almacenados.
     */
    void showSummary() const;
};

#endif // DATABASE_HPP
