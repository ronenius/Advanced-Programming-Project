#include "command.hpp"
#include "cli.hpp"

class setParametersCommand : public command
{
private:
    CLI *cli;

public:
    setParametersCommand(defaultIO *dio, std::string description, CLI *cli);
    void execute();
};