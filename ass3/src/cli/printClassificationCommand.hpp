#include "command.hpp"
#include "cli.hpp"
#ifndef PRINT_CLASSIFICATION_COMMAND_HPP
#define PRINT_CLASSIFICATION_COMMAND_HPP
class printClassificationCommand : command
{
private:
    CLI *cli;

public:
    printClassificationCommand(defaultIO *dio, std::string description, CLI *cli);
    void execute();
};
#endif