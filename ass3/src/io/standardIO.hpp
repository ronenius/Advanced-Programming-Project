#include "defaultIO.hpp"
#include "../cli/cli.hpp"
#include <iostream>
#ifndef STANDARD_IO_HPP
#define STANDARD_IO_HPP
//Standrad IO for the CLI (cout and cin).
class standardIO : public defaultIO
{
public:
    //Reads the input from the user.
    std::string read();
    //Writes the output for the user.
    void write(std::string output);
};
#endif