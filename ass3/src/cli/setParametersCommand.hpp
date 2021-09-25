#include "command.hpp"
#include "cli.hpp"
#ifndef SET_PARAMETERS_COMMAND_HPP
#define SET_PARAMETERS_COMMAND_HPP
class setParametersCommand : public command
{
private:
    CLI *cli;

public:
    setParametersCommand(defaultIO *dio, std::string description, CLI *cli);
    void execute();
};
#endif