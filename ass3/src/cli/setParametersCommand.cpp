#include "setParametersCommand.hpp"

std::vector<std::string> setParametersCommand::METRICS = {"EUC", "MAN", "CHE"};

setParametersCommand::setParametersCommand(defaultIO *dio, std::string description)
    : command(dio, description), K(5), metric("EUC"){};

void setParametersCommand::execute()
{
    this->getIO()->write("The current KNN parameters are: K = " + std::to_string(this->K) + ", distance metric = " + this->metric);
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
        if (newMetric.compare(METRICS[0]) != 0 && newMetric.compare(METRICS[1]) != 0 && newMetric.compare(METRICS[2]) != 0)
        {
            this->getIO()->write("Invalid value for distance metric");
            isCorrect = false;
        }
    }
    this->K = k;
    this->metric = newMetric;
}

int setParametersCommand::getK()
{
    return this->K;
}

std::string setParametersCommand::getMetric()
{
    return this->metric;
}