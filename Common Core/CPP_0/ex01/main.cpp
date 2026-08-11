
#include "Contact.hpp"

#include <iostream>

void Contact::call() {
    std::cout << "Mon telephone sonne: " << this->number << std::endl;
}

int main() {
    Contact joseph;

    joseph.call();
    std::cout << "JE doxx joseph ce grosa noobz: " << joseph.number << std::endl;
}