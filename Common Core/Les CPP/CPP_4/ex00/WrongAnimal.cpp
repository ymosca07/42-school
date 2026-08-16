#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "Default constructor is called for WrongAnimal" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor is called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "Copy is called for WrongAnimal" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "Operator is called for WrongAnimal" << std::endl;
    if (this != &other)
        this->type = "WrongAnimal";
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Generic sound WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}