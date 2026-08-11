#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc == 1)
    {
        std::cout << ("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
    }
    else
    {
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << static_cast<char>(std::toupper(argv[i][j]));
                j++;
            }
            if (i < argc - 1)
                std::cout << (" ");
            i++;
        }
    }
    std::cout << std::endl;
    return 0;
}
