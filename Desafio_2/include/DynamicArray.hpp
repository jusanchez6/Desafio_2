/**
 * @file DynamicArray.hpp
 * @brief Implementación genérica de un arreglo dinámico tipo vector.
 *
 * Esta plantilla de clase proporciona una estructura de datos que puede
 * redimensionarse automáticamente, similar a std::vector, permitiendo
 * almacenar elementos de cualquier tipo.
 * 
 * @authors Julián Sánchez
 *          Jaider Bedoya
 * 
 * @version 1.0.0
 */

#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <cstddef>
#include <iostream>

/**
 * @class DynamicArray
 * @brief Arreglo dinámico genérico para almacenar elementos de tipo T.
 *
 * La clase DynamicArray permite agregar, eliminar y acceder a elementos
 * de manera secuencial, ajustando su capacidad automáticamente según las necesidades.
 *
 * @tparam T Tipo de dato que almacenará el arreglo.
 */
template <typename T>
class DynamicArray {
public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa un arreglo vacío sin memoria reservada.
     */
    DynamicArray(): data(nullptr), len(0), capacity(0) {}

    /**
     * @brief Destructor.
     *
     * Libera la memoria utilizada por el arreglo.
     */
    ~DynamicArray() {
        clear();
    }

    /**
     * @brief Agrega un nuevo elemento al final del arreglo.
     * @param value Valor a insertar.
     */
    void push_back(const T& value);

    /**
     * @brief Reserva memoria para al menos n elementos.
     * @param n Nueva capacidad deseada.
     */
    void reserve(size_t n);

    /**
     * @brief Elimina todos los elementos del arreglo.
     *
     * Libera la memoria y reinicia los contadores internos.
     */
    void clear();

    /**
     * @brief Elimina el elemento en una posición específica.
     * @param index Índice del elemento a eliminar.
     */
    void removeAt(size_t index);

    /**
     * @brief Obtiene la cantidad actual de elementos.
     * @return Número de elementos almacenados.
     */
    size_t getSize() const;

    /**
     * @brief Accede a un elemento por índice.
     * @param index Índice del elemento deseado.
     * @return Referencia al elemento correspondiente.
     */
    T& operator[](size_t index);

    /**
     * @brief Accede a un elemento por índice (versión constante).
     * @param index Índice del elemento deseado.
     * @return Referencia constante al elemento correspondiente.
     */
    const T& operator[](size_t index) const;

private:
    T* data; ///< Puntero al arreglo de elementos.
    size_t len; ///< Número actual de elementos.
    size_t capacity; ///< Capacidad total reservada del arreglo.
};


// se implementa directamente en el hpp porque el compilador necesita esto siempre

template <typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (len >= capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }

    data[len++] = value;
}

template <typename T>
void DynamicArray<T>::reserve(size_t n) {
    if (n <= capacity) return;
    
    T* newData = new T[n];
    for (size_t i = 0; i < len; ++i) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
    capacity = n;
}

template <typename T>
void DynamicArray<T>::clear() {
    delete[] data;
    data = nullptr;
    len = 0;
    capacity = 0;
}

template <typename T>
size_t DynamicArray<T>::getSize() const {
    return len;
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
void DynamicArray<T>::removeAt(size_t index) {
    if (index >= len) {
        std::cerr << "Fuera de rango en: " << index << "\n";
        return;
    }

    // Desplazar los elementos hacia la izquierda
    for (size_t i = index; i < len - 1; ++i) {
        data[i] = data[i + 1];
    }

    --len;
}

#endif // DYNAMICARRAY_HPP
