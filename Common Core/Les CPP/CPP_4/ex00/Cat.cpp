#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Default constructor is called for Cat" << std::endl;
    this->type = "Cat";
}

Cat::~Cat() {
    std::cout << "Deconstructor is called for Cat" << std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "Copy is called for Cat" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Operator is called for Cat" << std::endl;
    if (this != &other)
        this->type = "Cat";
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Miaou" << std::endl;
}