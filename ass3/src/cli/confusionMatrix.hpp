#include "command.hpp"
#include "cli.hpp"
class confusionMatrix : command
{
private:
    CLI* cli;
public:
    confusionMatrix(defaultIO* dio, CLI* cli);
    void execute();
};