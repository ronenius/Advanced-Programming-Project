#include <string>
#include "../io/defaultIO.hpp"
#ifndef COMMAND_HPP
#define COMMAND_HPP
//An interface of a command in the CLI.
class command
{
private:
    std::string description;
    defaultIO *dio;

public:
    command(defaultIO *dio, std::string description);
    std::string getDescription();
    defaultIO *getIO();
    virtual void execute() = 0;
};
#endif