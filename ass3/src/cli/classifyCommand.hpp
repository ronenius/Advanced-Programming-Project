#include "command.hpp"
#include "cli.hpp"
#ifndef CLASSIFY_COMMAND_HPP
#define CLASSIFY_COMMAND_HPP
//a command that classifies the file.
class classifyCommand : public command
{
private:
    CLI *cli;

public:
    classifyCommand(defaultIO *dio, CLI *cli);
    //checks if the file is uploaded, and will classify it if it is.
    void execute();
};
#endif