#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void setName(std::string my_name) {
            name = my_name;
        }
};

Zombie* zombieHorde( int N, std::string name );