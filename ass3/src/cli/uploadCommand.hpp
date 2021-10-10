#include "command.hpp"
#include "cli.hpp"
#ifndef UPLOAD_COMMAND_HPP
#define UPLOAD_COMMAND_HPP
//a command that uploads the files.
class uploadCommand : public command
{
private:
    CLI *cli;

public:
    uploadCommand(defaultIO *dio, CLI *cli);
    //will recieve the files and save the required information.
    void execute();
};
#endif