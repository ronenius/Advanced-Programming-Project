#include "command.hpp"
#include "cli.hpp"
#ifndef CONFUSION_MATRIX_COMMAND_HPP
#define CONFUSION_MATRIX_COMMAND_HPP
class confusionMatrix : command
{
private:
    CLI *cli;

public:
    confusionMatrix(defaultIO *dio, std::string description, CLI *cli);
    void execute();
};
#endif