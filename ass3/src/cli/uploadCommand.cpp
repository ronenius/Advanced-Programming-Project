#include "uploadCommand.hpp"

uploadCommand::uploadCommand(defaultIO *dio, CLI *cli)
    : command(dio, "upload an unclassified csv data file"), cli(cli){};

void uploadCommand::execute()
{
    this->cli->setTrainer({});
    this->cli->setTester({});
    this->cli->setUnclassified({});
    this->getIO()->write("Please upload your local train CSV file.\n");
    std::string file = this->getIO()->read();
    this->cli->setTrainer(this->cli->getCsvIO().importStringToVector(file));
    this->getIO()->write("Upload complete.\nPlease upload your local test CSV file.\n");
    file = this->getIO()->read();
    this->cli->setTester(this->cli->getCsvIO().importStringToVector(file));
    this->cli->setUnclassified(this->cli->modifyClassifiedToUnclassified(this->cli->getTester()));
    this->getIO()->write("Upload complete.\n");
    this->cli->setFilesUploadState(true);
    this->cli->setClassificationState(false);
    while (getIO()->read() != "\n")
        ;
}