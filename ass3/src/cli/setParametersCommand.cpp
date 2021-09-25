#include "setParametersCommand.hpp"

setParametersCommand::setParametersCommand(defaultIO *dio, std::string description, CLI *cli)
    : command(dio, description), cli(cli){};

void setParametersCommand::execute()
{
    this->getIO()->write("The current KNN parameters are: K = " + std::to_string(this->cli->getK()) +
                         ", distance metric = " + this->cli->getMetric());
    bool isCorrect = false;
    int k;
    std::string newMetric;
    while (!isCorrect)
    {
        k = std::stoi(this->getIO()->read());
        newMetric = this->getIO()->read();
        if (k < 1 || k > 10)
        {
            this->getIO()->write("Invalid value for K");
        }
        else
        {
            isCorrect = true;
        }
        if (newMetric.compare(this->cli->getPossibleMetrics()[0]) != 0 &&
            newMetric.compare(this->cli->getPossibleMetrics()[1]) != 0 &&
            newMetric.compare(this->cli->getPossibleMetrics()[2]) != 0)
        {
            this->getIO()->write("Invalid value for distance metric");
            isCorrect = false;
        }
    }
    this->cli->setK(k);
    this->cli->setMetric(newMetric);
}