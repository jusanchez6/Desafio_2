/**
 * @file main.cpp
 * @brief Punto de entrada de la aplicación musical.
 *
 * Este archivo contiene la función main que inicia la aplicación AppMusic.
 * Se encarga de crear una instancia de la aplicación y ejecutar su ciclo principal.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#include <QCoreApplication>
#include <iostream>

#include <AppMusic.hpp>

/**
 * @brief Función principal de la aplicación.
 *
 * Crea una instancia de AppMusic y ejecuta el ciclo principal de la aplicación.
 *
 * @return Código de salida de la aplicación (0 si finaliza correctamente).
 */
int main() {
    AppMusic app;

    app.run();
    
    return 0;
}
