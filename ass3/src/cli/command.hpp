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
    //Retuerns the description of the command.
    std::string getDescription();
    //Returns the defaultIO the command uses to communicate.
    defaultIO *getIO();
    //The command itself. Uses the defaultIO provided in the constructor to communicate and send the information.
    virtual void execute() = 0;
};
#endif