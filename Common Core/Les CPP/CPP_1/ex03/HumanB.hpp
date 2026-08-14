#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon *weapon;
    public:
        void    attack();
        void    setWeapon(Weapon &weapon);
        HumanB(std::string name);
        ~HumanB();
};