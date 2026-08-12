#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    PhoneBook carnet;
    std::string command;

    while (1)
    {
        std::cout << "> ";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "Exit \n";
            break ;
        }
        if (command == "EXIT")
            break ;
        if (command == "SEARCH")
            carnet.searchContact();
        if (command == "ADD")
            carnet.addContact();
    }
    return 0;
}