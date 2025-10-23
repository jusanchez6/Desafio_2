/**
 * @file PlaybackSession.hpp
 * @brief Declaración de la clase PlaybackSession para gestionar la reproducción musical.
 *
 * Esta clase administra una sesión de reproducción para un usuario, controlando
 * canciones reproducidas, historial, anuncios y métricas de la sesión.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef PLAYBACKSESSION_HPP
#define PLAYBACKSESSION_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <DynamicArray.hpp>
#include <User.hpp>
#include <Database.hpp>
#include <AdMessage.hpp>

/**
 * @class PlaybackSession
 * @brief Representa una sesión de reproducción musical para un usuario.
 *
 * La clase PlaybackSession permite reproducir canciones aleatorias o favoritas,
 * gestionar el historial, mostrar anuncios de forma ocasional y medir métricas
 * como canciones reproducidas y anuncios mostrados.
 */
class PlaybackSession
{
private:
    // Atributos de sesión
    User* user; ///< Usuario que realiza la reproducción.
    Database* db; ///< Base de datos que contiene canciones y anuncios.
    DynamicArray<int> history; ///< Historial de canciones reproducidas.
    bool repeat; ///< Indica si la sesión está en modo repetición.
    int lastAdIndex; ///< Índice del último anuncio mostrado.

    // Métricas
    int songsPlayed; ///< Cantidad de canciones reproducidas.
    int adsShown; ///< Cantidad de anuncios mostrados.

    // Métodos privados
    /**
     * @brief Decide si mostrar un anuncio en la sesión y lo muestra si aplica.
     */
    void maybeShowAd();

    /**
     * @brief Agrega una canción al historial de reproducción.
     * @param songId Identificador de la canción reproducida.
     */
    void addToHistory(int songId);

public:
    /**
     * @brief Constructor con parámetros.
     *
     * Inicializa una sesión de reproducción para un usuario y una base de datos específica.
     *
     * @param u Puntero al usuario que realizará la reproducción.
     * @param d Puntero a la base de datos de canciones y anuncios.
     * @param repeat Indica si la sesión será en modo repetición (opcional, por defecto false).
     */
    PlaybackSession(User* u, Database* d, bool repeat = false);
    
    /**
     * @brief Reproduce K canciones seleccionadas aleatoriamente.
     * @param K Número de canciones a reproducir.
     */
    void playRandom(int K);

    /**
     * @brief Reproduce las canciones favoritas del usuario.
     * @param shuffle Indica si se deben reproducir en orden aleatorio.
     * @param maxBack Número máximo de canciones recientes a evitar repetir.
     */
    void playFavorites(bool shuffle, int maxBack);

    /**
     * @brief Muestra métricas de la sesión actual.
     *
     * Incluye la cantidad de canciones reproducidas y anuncios mostrados.
     */
    void showMetrics() const;
};

#endif // PLAYBACKSESSION_HPP
