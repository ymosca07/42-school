#include "HumanB.hpp"

HumanB::HumanB(std::string name_param):name(name_param) 
{
    weapon = NULL;
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() {
    std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}