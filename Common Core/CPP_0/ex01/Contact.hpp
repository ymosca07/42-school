#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Contact {

    private :
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string darkestSecret;
        std::string phone;
        std::string formatField(std::string text);
    
    public:
        Contact();
        ~Contact();
        void init();
        void view(int index);
        void display();
};

#endif