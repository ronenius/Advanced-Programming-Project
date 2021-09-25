#include "saveFileCommand.hpp"

saveFileCommand::saveFileCommand(defaultIO *dio, CLI *cli)
    : command(dio, "download results"), cli(cli){};

void saveFileCommand::execute()
{
    if (!this->cli->dataClassified())
    {
        this->getIO()->write("Please upload data and classify it before printing.");
        return;
    }
    std::vector<classifiable> classified = this->cli->getUnclassified();
    std::string message = "";
    for (int i = 0; i < classified.size(); i++)
    {
        message += (std::to_string(i) + "\t" + classified[i].getCategory() + "\n");
    }
    this->getIO()->write(message);
}