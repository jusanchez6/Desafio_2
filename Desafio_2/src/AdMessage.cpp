#include "AdMessage.hpp"

AdMessage::AdMessage() : text(""), category('C'), weight(0) {}

AdMessage::AdMessage(const std::string& text, char category, int weight)
    : text(text), category(category), weight(weight) {}

void AdMessage::setText(const std::string& t) { text = t; }
void AdMessage::setCategory(char c) { category = c; }
void AdMessage::setWeight(int w) { weight = w; }

const std::string& AdMessage::getText() const { return text; }
char AdMessage::getCategory() const { return category; }
int AdMessage::getWeight() const { return weight; }

void AdMessage::show() const {
    std::cout << "\n--- Anuncio ---\n";
    std::cout << "Categoría: " << category
              << "\nPeso: " << weight
              << "\nMensaje: " << text << std::endl;
}

