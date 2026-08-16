#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Default constructor is called for Animal" << std::endl;
    this->type = "Animal";
}

Animal::~Animal() {
    std::cout << "Destructor is called for Animal" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Copy is called for Animal" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Operator is called for Animal" << std::endl;
    if (this != &other)
        this->type = "Animal";
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}