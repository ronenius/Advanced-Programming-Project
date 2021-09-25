#include "uploadCommand.hpp"

uploadCommand::uploadCommand(defaultIO *dio, std::string description, CLI *cli)
    : command(dio, description), cli(cli){};

void uploadCommand::execute()
{
    this->cli->setTrainer({});
    this->cli->setTester({});
    this->cli->setUnclassified({});
    this->getIO()->write("Please upload your local train CSV file.");
    std::string file = this->getIO()->read();
    this->cli->setTrainer(this->cli->getCsvIO().importStringToVector(file));
    this->getIO()->write("Upload complete.");
    this->getIO()->write("Please upload your local test CSV file.");
    file = this->getIO()->read();
    this->cli->setTester(this->cli->getCsvIO().importStringToVector(file));
    this->cli->setUnclassified(this->cli->modifyClassifiedToUnclassified(this->cli->getTester()));
    this->getIO()->write("Upload complete.");
    this->cli->setFilesUploadState(true);
    this->cli->setClassificationState(false);
}