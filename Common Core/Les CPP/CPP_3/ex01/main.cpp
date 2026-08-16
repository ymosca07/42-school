#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    std::cout << "\n--- 1. CONSTRUCTION (Preuve de l'ordre) ---" << std::endl;
    ClapTrap yannis("Yannis");
    std::cout << std::endl;
    ScavTrap brother("Brother");

    std::cout << "\n--- 2. ATTAQUES (Messages différents) ---" << std::endl;
    yannis.attack("le mur");
    brother.attack("le mur");

    std::cout << "\n--- 3. RECYCLAGE (Fonctions héritées) ---" << std::endl;
    brother.takeDamage(50);
    brother.beRepaired(25);

    std::cout << "\n--- 4. COMPÉTENCE SPÉCIALE ---" << std::endl;
    brother.guardGate();

    std::cout << "\n--- 5. DESTRUCTION (Preuve de l'ordre inverse) ---" << std::endl;
    
    return 0;
}