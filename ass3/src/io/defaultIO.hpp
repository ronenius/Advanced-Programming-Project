#include <string>
#ifndef DEFAULT_IO_HPP
#define DEFAULT_IO_HPP
//An interface of the IO in the CLI.
class defaultIO
{
public:
    virtual std::string read() = 0;
    virtual void write(std::string output) = 0;
};
#endif