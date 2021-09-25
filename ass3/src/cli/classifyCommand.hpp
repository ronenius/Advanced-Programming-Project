#include "command.hpp"
#include "../classifier/knnClassifier.hpp"
#ifndef CLASSIFY_COMMAND_HPP
#define CLASSIFY_COMMAND_HPP
class classifyCommand : public command
{
private:
    classifier *cliClassifier;
    int k;
    std::string metric;
    std::vector<classifiable> train;
    std::vector<classifiable> unClassified;
    std::vector<classifiable> classified;

public:
    classifyCommand(defaultIO *dio, std::string description, classifier *cliClassifier,
                    int k, std::string metric, std::vector<classifiable> train,
                    std::vector<classifiable> unClassified);
    void execute();
    std::vector<classifiable> getClassifiedVector();
};
#endif