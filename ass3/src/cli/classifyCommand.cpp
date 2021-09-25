#include "classifyCommand.hpp"

classifyCommand::classifyCommand(defaultIO *dio, std::string description, classifier *cliClassifier,
                                 int k, std::string metric, std::vector<classifiable> train,
                                 std::vector<classifiable> unClassified)
    : command(dio, description), cliClassifier(cliClassifier),
      k(k), metric(metric), train(train), unClassified(unClassified){};

void classifyCommand::execute()
{
    this->classified =
        cliClassifier->getCategories(this->train, this->unClassified, this->k, this->metric);
    this->getIO()->write("classifying data complete");
}

std::vector<classifiable> classifyCommand::getClassifiedVector()
{
    return this->classified;
}