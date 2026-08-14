#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    Zombie *horde = new Zombie[N];
    int i;

    for (i = 0; i < N; i++)
        horde[i].setName(name);
    return (horde);
};