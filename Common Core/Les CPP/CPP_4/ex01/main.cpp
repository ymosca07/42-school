#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "\n--- 1. LE TEST DU SUJET (Allocation basique) ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; 
    delete i;

    std::cout << "\n--- 2. LE TABLEAU DE LA MOULINETTE ---" << std::endl;
    int size = 4;
    Animal* zoo[size];

    for (int k = 0; k < size / 2; k++) {
        zoo[k] = new Dog();
    }
    for (int k = size / 2; k < size; k++) {
        zoo[k] = new Cat();
    }

    std::cout << "\n--- Destruction du tableau ---" << std::endl;
    for (int k = 0; k < size; k++) {
        delete zoo[k];
    }

    std::cout << "\n--- 3. LE CRASH-TEST DE LA COPIE PROFONDE ---" << std::endl;
    Dog originalDog;
    Dog copyDog(originalDog);
    
    Dog assignedDog;
    assignedDog = originalDog;

    std::cout << "Destruction automatique à la sortie du main..." << std::endl;

    return 0;
}