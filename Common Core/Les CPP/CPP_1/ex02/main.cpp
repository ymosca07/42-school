#include <iostream>

int main()
{
    std::string a;
    a = "HI THIS IS BRAIN";

    std::string *stringPTR;
    stringPTR = &a;

    std::string& stringREF = a;

    std::cout << &a << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << a << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}