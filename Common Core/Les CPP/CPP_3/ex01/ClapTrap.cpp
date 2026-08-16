#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "Default constructor is called" << std::endl;
    this->name = "Default";
    this->attack_damage = 0;
    this->energy_points = 10;
    this->hit_points = 10;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "Constructor is called" << std::endl;
    this->name = name;
    this->attack_damage = 0;
    this->energy_points = 10;
    this->hit_points = 10;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return *this; 
}

int ClapTrap::getEnergy() const {
    return this->energy_points;
}

int ClapTrap::getHitpoints() const {
    return this->hit_points;
}

int ClapTrap::getAttackdamage() const {
    return this->attack_damage;
}

std::string ClapTrap::getName() const {
    return this->name;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hit_points == 0 || this->energy_points == 0)
        return ;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage !" << std::endl;
    this->energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hit_points <= (int)amount)
    {
        std::cout << "ClapTrap " << this->name << " lost " << this->hit_points << " hit points" << std::endl;
        this->hit_points = 0;
    }
    else
    {
        this->hit_points -= amount;
        std::cout << "ClapTrap " << this->name << " lost " << amount << " hit points" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hit_points == 0 || this->energy_points == 0)
        return ;
    std::cout << "ClapTrap " << this->name << " repairs " << amount << " hit points" << std::endl;
    this->hit_points += amount;
    this->energy_points -= 1;
}