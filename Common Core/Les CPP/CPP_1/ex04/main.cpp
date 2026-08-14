#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    
    if (argc != 4)
    {
        std::cerr << "ARGS NUMBERS INVALID" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (s1.empty())
    {
        std::cerr << "S1 EMPTY" << std::endl;
        return 1;
    }
    
    std::ifstream infile(filename.c_str());
    
    if (!infile.is_open())
    {
        std::cerr << "FILE ERROR" << std::endl;
        return 1;
    }
    
    std::string outname = filename + ".replace";
    std::ofstream outfile(outname.c_str());

    if (!outfile.is_open())
    {
        std::cerr << "FILE ERROR" << std::endl;
        return 1;
    }

    std::string buf;

    while (std::getline(infile, buf))
    {
        size_t pos = 0;
        while ((pos = buf.find(s1, pos)) != std::string::npos)
        {
            buf.erase(pos, s1.length());
            buf.insert(pos, s2);
            pos += s2.length();
        }
        outfile << buf;
        if (!infile.eof())
            outfile << std::endl;
    }
    return 0;
}