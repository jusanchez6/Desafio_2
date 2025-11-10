/**
 * @file AppMusic.hpp
 * @brief Declaración de la clase AppMusic que gestiona la aplicación musical.
 *
 * Esta clase representa el núcleo de la aplicación, encargada de manejar la 
 * base de datos, las sesiones de usuario y las interacciones principales 
 * como el inicio de sesión, la reproducción y la gestión de favoritos.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef AppMusic_HPP
#define AppMusic_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <Database.hpp>
#include <PlaybackSession.hpp>
#include <MemoryTracker.hpp>
#include <Counter.hpp>

/**
 * @class AppMusic
 * @brief Clase principal que controla la ejecución de la aplicación musical.
 *
 * Administra la base de datos, los usuarios y las funciones principales 
 * del sistema, como la reproducción, los favoritos y la interacción 
 * con listas musicales.
 */
class AppMusic
{
private:
    Database db; ///< Base de datos que contiene la información principal del sistema.
    User* currentUser; ///< Puntero al usuario actualmente autenticado.

    /**
     * @brief Carga todos los datos iniciales del sistema.
     */
    void loadAllData();

    /**
     * @brief Muestra el menú de inicio de sesión.
     */
    bool loginMenu();

    /**
     * @brief Inicia la sesión del usuario autenticado.
     */
    void userSession();

    /**
     * @brief Muestra la lista de favoritos de un usuario.
     * @param user Puntero al usuario cuyas canciones favoritas se mostrarán.
     */
    void showFavorites(User *user);

    /**
     * @brief Ejecuta una sesión de reproducción.
     * @param user Usuario que realiza la reproducción.
     * @param playFavorites Indica si se deben reproducir los favoritos.
     */
    void runPlayback(User* user, bool playFavorites);

    /**
     * @brief Gestiona las canciones favoritas del usuario.
     * @param user Puntero al usuario que modifica sus favoritos.
     */
    void manageFavorites(User* user);

    /**
     * @brief Permite editar la lista de favoritos de un usuario.
     * @param user Puntero al usuario que edita sus favoritos.
     */
    void editFavorites(User* user);

    /**
     * @brief Permite seguir la lista de otro usuario.
     * @param user Puntero al usuario que desea seguir una lista ajena.
     */
    void followOtherList(User* user);

    /**
     * @brief Ejecuta la lista de favoritos del usuario.
     * @param user Puntero al usuario cuyas canciones favoritas se reproducirán.
     */
    void executeFavorites(User* user);

public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa la aplicación musical y sus componentes internos.
     */
    AppMusic();

    /**
     * @brief Inicia la ejecución principal de la aplicación.
     */
    void run();
};

#endif // AppMusic_HPP
