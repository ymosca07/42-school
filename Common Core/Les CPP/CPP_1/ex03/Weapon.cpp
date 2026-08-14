#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) {
    this->type = weapon;
}

Weapon::~Weapon() {
}

void Weapon::setType(std::string new_weapon) {
    this->type = new_weapon;
}

std::string Weapon::getType() {
    return this->type;
}