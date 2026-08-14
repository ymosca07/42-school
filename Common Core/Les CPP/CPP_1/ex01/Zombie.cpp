#include "Zombie.hpp"

Zombie::Zombie() {

};

Zombie::~Zombie() {
    std::cout << name << " is died" << std::endl;
};

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};