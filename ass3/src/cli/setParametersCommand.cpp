#include "setParametersCommand.hpp"

setParametersCommand::setParametersCommand(defaultIO *dio, std::string description, CLI *cli)
    : command(dio, description), cli(cli){};

void setParametersCommand::execute()
{
    this->getIO()->write("The current KNN parameters are: K = " + std::to_string(this->cli->getK()) +
                         ", distance metric = " + this->cli->getMetric());
    bool isKCorrect = false, isMetricCorrect = false;
    int k;
    std::string newMetric;
    while (!isKCorrect || !isMetricCorrect)
    {
        k = std::stoi(this->getIO()->read());
        newMetric = this->getIO()->read();
        if (k < 1 || k > 10)
            this->getIO()->write("Invalid value for K");
        else
            isKCorrect = true;
        for (int i = 0; i < this->cli->getPossibleMetrics().size(); i++)
        {
            if (newMetric.compare(this->cli->getPossibleMetrics()[i]) == 0)
            {
                isMetricCorrect = true;
            }
        }
        if (!isMetricCorrect)
            this->getIO()->write("Invalid value for distance metric");
    }
    this->cli->setK(k);
    this->cli->setMetric(newMetric);
}