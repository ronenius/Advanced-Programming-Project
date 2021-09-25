#include "printClassificationCommand.hpp"
printClassificationCommand::printClassificationCommand(defaultIO *dio, CLI& cli) : 
    command(dio,"display results"), dio(dio), cli(cli) { }
void printClassificationCommand::execute()
{
    std::vector<classifiable> unclassified = cli.getUnclassified();
    if (unclassified.size() == 0 || unclassified[0].getCategory() == "undefined") {
        dio->write("Please upload data and classify it before printing.");
        return;
    }
    std::string message;
    for (int i = 0; i < unclassified.size(); i++) {
        message+=(i+"\t"+unclassified[i].getCategory()+"\n");
    }
    message+="Done.";
    dio->write(message);
}