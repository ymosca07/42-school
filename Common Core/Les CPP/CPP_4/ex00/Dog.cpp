#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Default constructor is called for Dog" << std::endl;
    this->type = "Dog";
}

Dog::~Dog() {
    std::cout << "Deconstructor is called for Dog" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Copy is called for Dog" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Operator is called for Dog" << std::endl;
    if (this != &other)
        this->type = "Dog";
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Waf" << std::endl;
}