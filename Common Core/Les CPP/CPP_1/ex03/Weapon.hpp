#include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string);
        ~Weapon();
        std::string getType();
        void setType(std::string new_weapon);
};