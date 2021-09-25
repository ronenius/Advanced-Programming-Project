#include "command.hpp"
#include "cli.hpp"
#ifndef SAVE_FILE_COMMAND_HPP
#define SAVE_FILE_COMMAND_HPP
class saveFileCommand : public command
{
private:
    CLI *cli;

public:
    saveFileCommand(defaultIO *dio, CLI *cli);
    void execute();
};
#endif