#include "defaultIO.hpp"
#include <iostream>
#ifndef STANDARD_IO_HPP
#define STANDARD_IO_HPP
//Standrad IO for the CLI (cout and cin).
class standardIO : public defaultIO
{
public:
    std::string read();
    void write(std::string output);
};
#endif