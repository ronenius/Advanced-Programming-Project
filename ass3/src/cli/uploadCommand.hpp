#include "command.hpp"
#include "../classifier/stringIO.hpp"
#ifndef UPLOAD_COMMAND_HPP
#define UPLOAD_COMMAND_HPP
class uploadCommand : public command
{
private:
    stringIO csvIO;
    std::vector<classifiable> train;
    std::vector<classifiable> test;

public:
    uploadCommand(defaultIO *dio, std::string description);
    void execute();
};
#endif