#include "classifyCommand.hpp"

classifyCommand::classifyCommand(defaultIO *dio, std::string description, CLI *cli)
    : command(dio, description), cli(cli){};

void classifyCommand::execute()
{
    if (!cli->filesUploaded())
    {
        getIO()->write("Please upload data before classifying.");
        return;
    }
    this->cli->setUnclassified(this->cli->getClassifier()->getCategories(this->cli->getTrainer(),
                                                                         this->cli->getUnclassified(),
                                                                         this->cli->getK(),
                                                                         this->cli->getMetric()));
    this->cli->setClassificationState(true);
    this->getIO()->write("classifying data complete");
}