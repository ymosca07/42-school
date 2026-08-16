#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Default constructor is called for Dog" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Deconstructor is called for Dog" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Copy is called for Dog" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Operator is called for Dog" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        if (this->brain != NULL)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Waf" << std::endl;
}