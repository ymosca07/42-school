#include "Zombie.hpp"

int main()
{
    int j;
    Zombie *my_horde = zombieHorde(5, "Yannis");
    
    for(j = 0; j < 5; j++)
        my_horde[j].announce();

    delete[] my_horde;

    return 0;
}