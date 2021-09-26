#include "standardIO.hpp"
#include "../classifier/stringIO.hpp"

std::string standardIO::read()
{
    std::string input;
    getline(std::cin, input);
    return input;
}

void standardIO::write(std::string output)
{
    std::cout << output;
}