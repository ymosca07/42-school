#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){  
    index = 0;
};

PhoneBook::~PhoneBook(){};

void PhoneBook::addContact() {
    
    contacts[index % 8].init();
    index++;
};

void PhoneBook::searchContact() {
    
    std::string input;
    int index_input;
    int limite;
    int i;

    i = 0;

    if (index == 0)
    {
        std::cout << "Repertory is empty" << std::endl;
        return ;
    }

    if (index > 8)
        limite = 8;
    else
        limite = index;

    while (i < limite)
    {
        contacts[i].view(i);
        i++;
    }
    while (input.empty())
    {
        std::cout << "Which contact do you want to display ?\n";
        std::getline(std::cin, input);

        if (input.length() != 1 || (input[0] < '0' || input[0] > '7'))
        {
            std::cout << "Index invalid" << std::endl;
            input = "";
        }
        else
        {
            index_input = input[0] - '0';
            if (index_input < limite)
                contacts[index_input].display();
            else
            {
                std::cout << "Index invalid" << std::endl;
                input = "";
            }
        }
        if (std::cin.eof())
        {
            std::cout << "Exit \n";
            exit(0);
        }
    }

};

