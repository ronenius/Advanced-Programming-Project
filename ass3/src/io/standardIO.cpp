#include "standardIO.hpp"
#include "../classifier/stringIO.hpp"

//Reads the input from the user.
std::string standardIO::read()
{
    std::string input;
    //Gets user input.
    getline(std::cin, input);
    return input;
}

//Writes the output for the user.
void standardIO::write(std::string output)
{
    //Prints output.
    std::cout << output;
}