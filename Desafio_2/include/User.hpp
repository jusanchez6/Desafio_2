/**
 * @file User.hpp
 * @brief Declaración de la clase User que representa un usuario de la aplicación musical.
 *
 * Esta clase almacena información de un usuario, incluyendo nickname, estado premium,
 * ciudad, país, fecha de registro, lista de canciones favoritas y seguimiento de otros usuarios.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <iostream>
#include <cstdlib>

#include <DynamicArray.hpp>
#include <Song.hpp>

/**
 * @class User
 * @brief Representa un usuario de la aplicación musical.
 *
 * La clase User permite gestionar favoritos, reproducir canciones favoritas,
 * seguir a otros usuarios y consultar información personal y estadísticas.
 */
class User
{
private:
    std::string nickname;               ///< Apodo del usuario.
    std::string password;
    bool premium;                       ///< Indica si el usuario tiene cuenta premium.
    std::string city;                   ///< Ciudad de residencia del usuario.
    std::string country;                ///< País de residencia del usuario.
    unsigned int signup_date;           ///< Fecha de registro del usuario.
    DynamicArray<Song*> favorites;      ///< Lista de canciones favoritas.
    User* following;                    ///< Usuario al que sigue actualmente.

public:
    /**
     * @brief Constructor con parámetros.
     *
     * Inicializa un usuario con la información proporcionada.
     *
     * @param nick Apodo del usuario.
     * @param premiumStatus Indica si es usuario premium.
     * @param city Ciudad de residencia.
     * @param country País de residencia.
     * @param signup_date Fecha de registro.
     */
    User(const std::string& nick, const std::string& pass, bool premiumStatus, const std::string& city, const std::string& country, unsigned int signup_date);

    /**
     * @brief Destructor del usuario.
     */
    ~User();

    // Funcionales
    /**
     * @brief Agrega una canción a la lista de favoritos del usuario.
     * @param s Puntero a la canción a agregar.
     */
    void addFavorite(Song* s);

    /**
     * @brief Reproduce las canciones favoritas del usuario.
     * @param shuffle Indica si la reproducción será aleatoria.
     */
    void playFavorites(bool shuffle = false);

    /**
     * @brief Permite seguir a otro usuario.
     * @param other Puntero al usuario a seguir.
     */
    void follow(User* other);

    /**
     * @brief Verifica si una canción es favorita del usuario.
     * @param s Puntero a la canción.
     * @return true si es favorita, false en caso contrario.
     */
    bool isFavorite(Song* s);

    /**
     * @brief Elimina una canción de la lista de favoritos.
     * @param s Puntero a la canción a eliminar.
     */
    void removeFavorite(Song* s);

    // Getters
    /**
     * @brief Verifica si el usuario es premium.
     * @return true si es premium, false en caso contrario.
     */
    bool isPremium() const;

    /**
     * @brief Obtiene el nickname del usuario.
     * @return Referencia constante al nickname.
     */
    const std::string& getNick() const;

    const std::string& getPass() const;

    /**
     * @brief Obtiene la ciudad del usuario.
     * @return Referencia constante a la ciudad.
     */
    const std::string& getCity() const;

    /**
     * @brief Obtiene el país del usuario.
     * @return Referencia constante al país.
     */
    const std::string& getCountry() const;

    /**
     * @brief Obtiene la fecha de registro del usuario.
     * @return Fecha de registro.
     */
    unsigned int getSignupDate() const;

    /**
     * @brief Obtiene la cantidad de canciones favoritas.
     * @return Número de canciones en favoritos.
     */
    size_t getFavoriteCount() const;

    /**
     * @brief Obtiene una canción favorita por índice.
     * @param index Índice de la canción.
     * @return Puntero a la canción favorita.
     */
    Song* getFavorite(size_t index);

    // Test
    /**
     * @brief Muestra información general del usuario.
     *
     * Incluye nickname, estado premium, ubicación y cantidad de favoritos.
     */
    void show() const;
};

#endif
