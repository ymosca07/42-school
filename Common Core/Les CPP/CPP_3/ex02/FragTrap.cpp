#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "Default constructor is called for FragTrap" << std::endl;
    this->attack_damage = 30;
    this->energy_points = 100;
    this->hit_points = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "Constructor is called for FragTrap" << std::endl;
    this->attack_damage = 30;
    this->energy_points = 100;
    this->hit_points = 100;
}

FragTrap::~FragTrap() {
    std::cout << "Destructor is called for FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "Copy constructor called for FragTrap" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "Copy assignment operator called for FragTrap" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->attack_damage = other.attack_damage;
        this->energy_points = other.energy_points;
        this->hit_points = other.hit_points;
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " wants a positive high-fives !" << std::endl;
}