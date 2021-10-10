#include "command.hpp"
#include "cli.hpp"
#include <thread>
#ifndef SAVE_FILE_COMMAND_HPP
#define SAVE_FILE_COMMAND_HPP
//a command that sends the file for downloading.
//It will be done in a different thread so that the cli will be able to keep running while its sending.
class saveFileCommand : public command
{
private:
    CLI *cli;

public:
    saveFileCommand(defaultIO *dio, CLI *cli);
    //sends the data for classifing in a different thread, so that the cli will be able to keep running while its sending.
    void execute();
};
#endif