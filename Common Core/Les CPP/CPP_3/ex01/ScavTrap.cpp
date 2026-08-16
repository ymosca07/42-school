#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "Default constructor is called for ScavTrap" << std::endl;
    this->name = "Default";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "Constructor is called for ScavTrap" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "Destructor is called for ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    std::cout << "Copy constructor called for ScavTrap" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "Copy assignment operator called for ScavTrap" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->hit_points == 0 || this->energy_points == 0)
        return ;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage !" << std::endl;
    this->energy_points -= 1;
}

void ScavTrap::guardGate() const {
    std::cout << "Gate keeper mode" << std::endl;
}