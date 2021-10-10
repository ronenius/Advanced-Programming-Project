#include "classifyCommand.hpp"

classifyCommand::classifyCommand(defaultIO *dio, CLI *cli)
    : command(dio, "classify data"), cli(cli){};

void classifyCommand::execute()
{
    //if the files are not uploaded
    if (!cli->filesUploaded())
    {
        getIO()->write("Please upload data before classifying.\n");
        //wait for recieving "\n".
        while (getIO()->read() != "\n")
            ;
        return;
    }
    //if the files are uploaded, classify the test file.
    this->cli->setUnclassified(this->cli->getClassifier()->getCategories(this->cli->getTrainer(),
                                                                         this->cli->getUnclassified(),
                                                                         this->cli->getK(),
                                                                         this->cli->getMetric()));
    //set the classification state to true.
    this->cli->setClassificationState(true);
    this->getIO()->write("classifying data complete\n");
    //wait for "\n".
    while (getIO()->read() != "\n")
        ;
}