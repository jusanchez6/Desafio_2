#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream>

class Counter {
private:
    int count;  // número de operaciones registradas

public:
    Counter();

    void increment();   // suma 1 al contador
    void reset();       // reinicia el contador
    int getCount() const; // devuelve el valor actual

    void showMetrics(const std::string& context = "") const;
};

#endif // COUNTER_HPP
