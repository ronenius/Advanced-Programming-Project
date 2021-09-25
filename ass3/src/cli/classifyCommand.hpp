#include "command.hpp"
#include "cli.hpp"
#ifndef CLASSIFY_COMMAND_HPP
#define CLASSIFY_COMMAND_HPP
class classifyCommand : public command
{
private:
    CLI *cli;

public:
    classifyCommand(defaultIO *dio, CLI *cli);
    void execute();
};
#endif