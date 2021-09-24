#include "standardIO.hpp"

std::string read()
{
    std::string input;
    std::cin >> input;
    return input;
}

void write(std::string output)
{
    std::cout << output;
}