#include "command.hpp"
#include "cli.hpp"
#ifndef PRINT_CLASSIFICATION_COMMAND_HPP
#define PRINT_CLASSIFICATION_COMMAND_HPP
//a command that prints the classification.
class printClassificationCommand : public command
{
private:
    CLI *cli;

public:
    printClassificationCommand(defaultIO *dio, CLI *cli);
    //will send the classification if the files were classified.
    void execute();
};
#endif