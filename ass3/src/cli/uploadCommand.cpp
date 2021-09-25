#include "uploadCommand.hpp"

uploadCommand::uploadCommand(defaultIO *dio, std::string description)
    : command(dio, description){};

void uploadCommand::execute()
{
    this->getIO()->write("Please upload your local train CSV file.");
    std::string file = this->getIO()->read();
    this->train = csvIO.importStringToVector(file);
    this->getIO()->write("Upload complete.");
    this->getIO()->write("Please upload your local test CSV file.");
    file = this->getIO()->read();
    this->test = csvIO.importStringToVector(file);
    this->getIO()->write("Upload complete.");
}

std::vector<classifiable> uploadCommand::getTrainVector()
{
    return this->train;
}

std::vector<classifiable> uploadCommand::getTestVector()
{
    return this->test;
}

std::vector<classifiable> modifyClassifiedToUnclassified(std::vector<classifiable> classified)
{
    for (int i = 0; i < classified.size(); i++)
    {
        classified[i].setCategory("undefined");
    }
    return classified;
}

std::vector<classifiable> uploadCommand::getUnclassifiedTestVector()
{
    return this->modifyClassifiedToUnclassified(this->test);
}