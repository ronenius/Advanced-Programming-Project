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
    std::vector<classifiable> modifyClassifiedToUnclassified(std::vector<classifiable> classified);

public:
    uploadCommand(defaultIO *dio, std::string description);
    void execute();
    std::vector<classifiable> getTrainVector();
    std::vector<classifiable> getTestVector();
    std::vector<classifiable> getUnclassifiedTestVector();
};
#endif