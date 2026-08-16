#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- 1. CONSTRUCTION ET CHRONOLOGIE ---" << std::endl;
    FragTrap yannis("Yannis");
    FragTrap brother("Brother");

    std::cout << "\n--- 2. FORME CANONIQUE ---" << std::endl;
    FragTrap clone(yannis); 
    FragTrap vide;
    vide = brother;

    std::cout << "\n--- 3. TEST DE COMBAT (STATISTIQUES FRAGTRAP) ---" << std::endl;
    yannis.attack("Brother");
    brother.takeDamage(30);
    brother.beRepaired(20);

    std::cout << "\n--- 4. COMPÉTENCE SPÉCIALE ---" << std::endl;
    yannis.highFivesGuys();
    clone.highFivesGuys();

    std::cout << "\n--- 5. TEST DE MORT ---" << std::endl;
    brother.takeDamage(200); 
    brother.attack("Yannis");
    brother.beRepaired(50);

    std::cout << "\n--- 6. DESTRUCTION ---" << std::endl;
    return 0;
}