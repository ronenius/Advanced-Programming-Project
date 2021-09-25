#include "command.hpp"
#include "cli.hpp"
#ifndef UPLOAD_COMMAND_HPP
#define UPLOAD_COMMAND_HPP
class uploadCommand : public command
{
private:
    CLI *cli;

public:
    uploadCommand(defaultIO *dio, std::string description, CLI *cli);
    void execute();
};
#endif