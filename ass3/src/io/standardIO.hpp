#include "defaultIO.hpp"
#include "../cli/cli.hpp"
#include <iostream>
#ifndef STANDARD_IO_HPP
#define STANDARD_IO_HPP
//Standrad IO for the CLI (cout and cin).
class standardIO : public defaultIO
{
private:
    bool is1, is12, is5;

public:
    standardIO();
    std::string read();
    void write(std::string output);
};
#endif