#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <cstddef>
#include <iostream>


template <typename T>
class DynamicArray {
public:
    // Constructor 
    DynamicArray(): data(nullptr), len(0), capacity(0) {}

    // Destructor
    ~DynamicArray() {
        clear();
    }

    void push_back(const T& value);
    void reserve(size_t n);
    void clear();
    void removeAt(size_t index);
    size_t getSize() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

private:
    T* data;
    size_t len;
    size_t capacity;

};


// se implementa directamente en el hpp porque el compilador necesita esto siempre

template <typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (len >= capacity) {
        reserve(capacity == 0 ? 1 :capacity * 2);
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



#endif //DynamicArray.hpp
