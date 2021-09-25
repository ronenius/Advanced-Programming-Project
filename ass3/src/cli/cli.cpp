#include "cli.hpp"

std::vector<std::string> CLI::METRICS = {"EUC", "MAN", "CHE"};

CLI::CLI(defaultIO *dio) : k(5), metric(CLI::METRICS[0]), dio(dio){};

void CLI::start()
{
}

std::vector<std::string> CLI::getPossibleMetrics()
{
    return CLI::METRICS;
}

std::vector<classifiable> CLI::getTrainer()
{
    return train;
}

void CLI::setTrainer(std::vector<classifiable> trainer)
{
    train = trainer;
}

std::vector<classifiable> CLI::getTester()
{
    return test;
}

void CLI::setTester(std::vector<classifiable> tester)
{
    test = tester;
}

std::vector<classifiable> CLI::getUnclassified()
{
    return unClassified;
}

void CLI::setUnclassified(std::vector<classifiable> unclassified)
{
    this->unClassified = unClassified;
}