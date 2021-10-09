#include "saveFileCommand.hpp"

void sendResults(std::vector<classifiable> classified, defaultIO *io)
{
    std::string message = "";
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
    if (!this->cli->dataClassified())
    {
        this->getIO()->write("Please upload data and classify it before downloading.\n");
        while (getIO()->read() != "\n")
            ;
        return;
    }
    std::thread th(sendResults, this->cli->getUnclassified(), this->getIO());
    th.detach();
    while (getIO()->read() != "\n")
        ;
}