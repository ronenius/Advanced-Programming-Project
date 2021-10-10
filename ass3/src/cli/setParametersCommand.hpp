#include "command.hpp"
#include "cli.hpp"
#ifndef SET_PARAMETERS_COMMAND_HPP
#define SET_PARAMETERS_COMMAND_HPP
//a command that changes the classifier parameters.
class setParametersCommand : public command
{
private:
    CLI *cli;

public:
    setParametersCommand(defaultIO *dio, CLI *cli);
    //sends the current parameters, and changes them according to the input (if given).
    //it will continue to wait for change until the input is valid.
    void execute();
};
#endif