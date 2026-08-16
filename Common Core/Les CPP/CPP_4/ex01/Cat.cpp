#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Default constructor is called for Cat" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::~Cat() {
    std::cout << "Deconstructor is called for Cat" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat& other) : Animal(other){
    std::cout << "Copy is called for Cat" << std::endl;
    this->type = other.type;
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Operator is called for Cat" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        if (this->brain != NULL)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Miaou" << std::endl;
}