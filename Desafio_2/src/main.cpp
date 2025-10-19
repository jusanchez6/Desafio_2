#include <QCoreApplication>
#include <iostream>

#include <DynamicArray.hpp>


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

    return 0;

}
