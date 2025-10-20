#ifndef CREDIT_HPP
#define CREDIT_HPP


#include <string>
#include <cstring>
#include <iostream>


class Credit
{
private:
    /* data */

    std::string name;
    std::string surname;
    char code[11];

public:

    // constructor
    Credit(const std::string& nom, const std::string& apen,  const std::string& cod);

    const std::string& getName() const;
    const std::string& getSurname() const;
    const char* getCode() const;
    
    void show() const;
    
};

#endif
