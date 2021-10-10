#include "printClassificationCommand.hpp"

printClassificationCommand::printClassificationCommand(defaultIO *dio, CLI *cli)
    : command(dio, "display results"), cli(cli){};

void printClassificationCommand::execute()
{
    //if the data is not classified
    if (!cli->dataClassified())
    {
        getIO()->write("Please upload data and classify it before printing.\n");
        //wait for "\n".
        while (getIO()->read() != "\n")
            ;
        return;
    }
    std::vector<classifiable> unclassified = cli->getUnclassified();
    std::string message = "";
    //add each objects index and category.
    for (int i = 0; i < unclassified.size(); i++)
    {
        message += (std::to_string(i + 1) + "\t" + unclassified[i].getCategory() + "\n");
    }
    message += "Done.\n";
    getIO()->write(message);
    //wait for "\n".
    while (getIO()->read() != "\n")
        ;
}