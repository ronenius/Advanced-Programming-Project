#include "command.hpp"
#include "cli.hpp"
class printClassificationCommand : command
{
private:
    defaultIO* dio;
    CLI& cli;
public:
    printClassificationCommand(defaultIO *dio, CLI& cli);
    void execute();
};