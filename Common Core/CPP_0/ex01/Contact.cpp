#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

void Contact::init(){

    first_name = "";
    last_name = "";
    nickname = "";
    darkestSecret = "";
    phone = "";

    while (first_name.empty())
    {
        std::cout << "First Name: \n";
        std::getline(std::cin, first_name);
        if (std::cin.eof())
        {
            std::cout << "Exit \n";
            exit(0);
        }
    }
    while (last_name.empty())
    {
        std::cout << "Last Name: \n";
        std::getline(std::cin, last_name);
        if (std::cin.eof())
        {
            std::cout << "Exit \n";
            exit(0);
        }
    }
    while (nickname.empty())
    {
        std::cout << "Nickname: \n";
        std::getline(std::cin, nickname);
        if (std::cin.eof())
        {
            std::cout << "Exit \n";
            exit(0);
        }
    }
    while (darkestSecret.empty())
    {
        std::cout << "Darkest Secret: \n";
        std::getline(std::cin, darkestSecret);
        if (std::cin.eof())
        {
            std::cout << "Exit \n";
            exit(0);
        }
    }
    while (phone.empty())
    {
        std::cout << "Phone: \n";
        std::getline(std::cin, phone);
        if (std::cin.eof())
        {
            std::cout << "Exit \n";
            exit(0);
        }
    }
};

std::string Contact::formatField(std::string text)
{
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    return text;
}

void Contact::view(int index) {
    std::cout << std::setw(10) << std::right << index << "|";
    std::cout << std::setw(10) << std::right << formatField(first_name) << "|";
    std::cout << std::setw(10) << std::right << formatField(last_name) << "|";
    std::cout << std::setw(10) << std::right << formatField(nickname) << "|" << std::endl;
};

void Contact::display() {
    std::cout << first_name << std::endl;
    std::cout << last_name << std::endl;
    std::cout << nickname << std::endl;
    std::cout << darkestSecret << std::endl;
    std::cout << phone << std::endl;
};
