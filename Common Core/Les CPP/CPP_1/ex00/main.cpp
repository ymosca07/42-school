#include "Zombie.hpp"

int main()
{
    std::cout << "TEST - NEW ZOMBIE" << std::endl;

    Zombie *Zombie = newZombie("Yannis");
    Zombie->announce();

    std::cout << "TEST - RANDOM CHUP" << std::endl;

    randomChump("Brother");
    delete Zombie;

    return 0;
}