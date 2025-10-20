#include <Credit.hpp>

Credit::Credit(const std::string& nom, const std::string& apen, const std::string& cod) : name(nom), surname(apen)
{
    std::strncpy(code, cod.c_str(), 10);
    code[10] = '\0';
}


const std::string& Credit::getName() const {
    return name;
}
const std::string& Credit::getSurname() const {
    return surname;
}
const char* Credit::getCode() const {
    return code;
}


    
void Credit::show() const{
    std::cout << "Nombre: " << name << " " << surname
    << ", Código: " << code << std::endl;
}
