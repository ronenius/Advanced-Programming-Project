#include <string>
#ifndef DEFAULT_IO_HPP
#define DEFAULT_IO_HPP
//An interface of the IO in the CLI.
class defaultIO
{
public:
    //Reads the input from the user.
    virtual std::string read() = 0;
    //Writes the output for the user.
    virtual void write(std::string output) = 0;
};
#endif