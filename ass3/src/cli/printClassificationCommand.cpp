#include "printClassificationCommand.hpp"

printClassificationCommand::printClassificationCommand(defaultIO *dio, CLI *cli)
    : command(dio, "display results"), cli(cli){};

void printClassificationCommand::execute()
{
    if (!cli->dataClassified())
    {
        getIO()->write("Please upload data and classify it before printing.\n");
        return;
    }
    std::vector<classifiable> unclassified = cli->getUnclassified();
    std::string message = "";
    for (int i = 0; i < unclassified.size(); i++)
    {
        message += (std::to_string(i + 1) + "\t" + unclassified[i].getCategory() + "\n");
    }
    message += "Done.\n";
    getIO()->write(message);
    while (getIO()->read().size() != 0)
        ;
}