#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Default constructor is called for Cat" << std::endl;
    this->type = "Cat";
}

WrongCat::~WrongCat() {
    std::cout << "Deconstructor is called for WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "Copy is called for WrongCat" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "Operator is called for WrongCat" << std::endl;
    if (this != &other)
        this->type = "WrongCat";
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Miaou" << std::endl;
}