#include "cli.hpp"

std::vector<std::string> CLI::METRICS = {"EUC", "MAN", "CHE"};

CLI::CLI(defaultIO *dio, classifier *cliClassifier)
    : k(5), metric(METRICS[0]), cliClassifier(cliClassifier),
      dio(dio), isUploadedFiles(false), isClassified(false){};

void CLI::start()
{
}

int CLI::getK()
{
    return this->k;
}

void CLI::setK(int k)
{
    this->k = k;
}

std::string CLI::getMetric()
{
    return this->metric;
}

void CLI::setMetric(std::string metric)
{
    this->metric = metric;
}

stringIO CLI::getCsvIO()
{
    return this->csvIO;
}

classifier *CLI::getClassifier()
{
    return this->cliClassifier;
}

void CLI::setClassifier(classifier *cliClassifier)
{
    this->cliClassifier = cliClassifier;
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

std::vector<classifiable> CLI::modifyClassifiedToUnclassified(std::vector<classifiable> classified)
{
    for (int i = 0; i < classified.size(); i++)
    {
        classified[i].setCategory("undefined");
    }
    return classified;
}