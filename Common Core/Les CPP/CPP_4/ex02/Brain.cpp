#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Default constructor is called for Brain" << std::endl;
}

Brain::~Brain() {
    std::cout << "Deconstructor is called for Brain" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Copy is called for Brain" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
}
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Operator is called for Brain" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}