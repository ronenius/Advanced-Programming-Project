#include "printClassificationCommand.hpp"

printClassificationCommand::printClassificationCommand(defaultIO *dio, std::string description, CLI *cli) : command(dio, description), cli(cli){};

void printClassificationCommand::printClassificationCommand::execute()
{
    std::vector<classifiable> unclassified = cli->getUnclassified();
    if (unclassified.size() == 0 || unclassified[0].getCategory() == "undefined")
    {
        getIO()->write("Please upload data and classify it before printing.");
        return;
    }
    std::string message = "";
    for (int i = 0; i < unclassified.size(); i++)
    {
        message += (std::to_string(i) + "\t" + unclassified[i].getCategory() + "\n");
    }
    message += "Done.";
    getIO()->write(message);
}