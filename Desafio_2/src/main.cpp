#include <QCoreApplication>
#include <iostream>

#include <DynamicArray.hpp>
#include <Credit.hpp>


using namespace std;
int main()
{
    cout << "hola desafio 2\n";
    cout << "inciando prueba\n";

    DynamicArray<int> numeros;

    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);


    for (size_t i = 0; i < numeros.getSize(); i++)
    {
        cout << numeros[i] << " ";
    }

    cout << "\n total de elementos: " << numeros.getSize() << endl;

    Credit c1("Carlos", "Santana", "MUS12345");
    c1.show();

    Credit c2("Shakira", "Mebarak", "PROD9988");
    c2.show();

    // Mostrar acceso directo a los getters
    std::cout << "Código de c2: " << c2.getCode() << std::endl;

    return 0;

}
