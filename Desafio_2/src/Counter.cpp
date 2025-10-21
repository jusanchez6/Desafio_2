#include "Counter.hpp"

Counter::Counter() : count(0) {}

void Counter::increment() {
    ++count;
}

void Counter::reset() {
    count = 0;
}

int Counter::getCount() const {
    return count;
}

void Counter::showMetrics(const std::string& context) const {
    std::cout << "\n === Métricas de Contador ===" << std::endl;
    if (!context.empty())
        std::cout << "Contexto: " << context << std::endl;
    std::cout << "Operaciones registradas: " << count << std::endl;
}

