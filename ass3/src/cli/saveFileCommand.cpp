#include "saveFileCommand.hpp"

//sends the results of the classification.
void sendResults(std::vector<classifiable> classified, defaultIO *io)
{
    std::string message = "";
    //for every object, send its index and classification.
    for (int i = 0; i < classified.size(); i++)
    {
        message += (std::to_string(i + 1) + "\t" + classified[i].getCategory() + "\n");
    }
    io->write(message);
}

saveFileCommand::saveFileCommand(defaultIO *dio, CLI *cli)
    : command(dio, "download results"), cli(cli){};

void saveFileCommand::execute()
{
    //if the data isn't classified
    if (!this->cli->dataClassified())
    {
        this->getIO()->write("Please upload data and classify it before downloading.\n");
        //wait for "\n".
        while (getIO()->read() != "\n")
            ;
        return;
    }
    //opens a new thread for sending the information.
    //The cli will be able to send the menu and get new messages before its done.
    std::thread th(sendResults, this->cli->getUnclassified(), this->getIO());
    th.detach();
    //wait for "\n".
    while (getIO()->read() != "\n")
        ;
}