#include <QCoreApplication>
#include <iostream>

#include <DynamicArray.hpp>
#include <Credit.hpp>
#include <Song.hpp>

int main()
{
    std::cout << "hola desafio 2\n";
    std::cout << "inciando prueba\n";

    DynamicArray<int> numeros;

    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);


    for (size_t i = 0; i < numeros.getSize(); i++)
    {
        std::cout << numeros[i] << " ";
    }

    std::cout << "\n total de elementos: " << numeros.getSize() << std::endl;

    // Crear créditos
    Credit* prod = new Credit("Rick", "Rubin", "PROD001");
    Credit* mus  = new Credit("John", "Frusciante", "MUS009");
    Credit* comp = new Credit("Anthony", "Kiedis", "COMP007");

    // Crear canción
    Song s1(10001001, "Californication", 330, "/media/red_hot_chili_peppers");

    // Agregar créditos
    s1.addProducer(prod);
    s1.addMusician(mus);
    s1.addComposer(comp);

    // Mostrar información
    s1.show();

    // Reproducir (128 kbps)
    s1.play(128);

    // Mostrar información actualizada
    std::cout << "\nReproducciones totales: " << s1.getPlayCount() << std::endl;

    return 0;
    return 0;

}
