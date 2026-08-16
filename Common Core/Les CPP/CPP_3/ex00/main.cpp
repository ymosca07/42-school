#include "ClapTrap.hpp"

int main() {
    std::cout << "\n--- 1. CREATION & CLONAGE ---" << std::endl;
    ClapTrap yannis("Yannis");
    ClapTrap brother("Brother");
    ClapTrap clone(yannis);
    vide = brother;

    std::cout << "\n--- 2. ACTIONS NORMALES ---" << std::endl;
    yannis.attack("Brother");
    brother.takeDamage(0);
    brother.beRepaired(2);

    std::cout << "\n--- 3. TEST DE FATIGUE ---" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Try " << i + 1 << ": ";
        yannis.attack("a wall");
    }

    std::cout << "\n--- 4. TEST DE MORT ---" << std::endl;
    brother.takeDamage(20);
    brother.attack("Yannis");
    brother.beRepaired(5);

    std::cout << "\n--- 5. DESTRUCTION ---" << std::endl;
    return 0;
}