#ifndef ADMESSAGE_HPP
#define ADMESSAGE_HPP

#include <string>
#include <iostream>

class AdMessage {
private:
    std::string text;  // Texto del anuncio
    char category;     // Categoría (C, B, AAA)
    int weight;        // Peso o prioridad del anuncio

public:

    AdMessage();
    AdMessage(const std::string& text, char category, int weight);

    void setText(const std::string& t);
    void setCategory(char c);
    void setWeight(int w);

    const std::string& getText() const;
    char getCategory() const;
    int getWeight() const;

    void show() const;
};

#endif
