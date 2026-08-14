#include "HumanA.hpp"

HumanA::HumanA(std::string name_param, Weapon& weapon_param):name(name_param), weapon(weapon_param)
{

}

HumanA::~HumanA() {
}

void HumanA::attack() {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}