#include "cli.hpp"
#include "confusionMatrix.hpp"
#include "printClassificationCommand.hpp"
#include "setParametersCommand.hpp"
#include "uploadCommand.hpp"
#include "classifyCommand.hpp"
#include "saveFileCommand.hpp"
std::vector<std::string> CLI::METRICS = {"EUC", "MAN", "CHE"};

CLI::CLI(defaultIO *dio, classifier *cliClassifier)
    : k(5), metric(METRICS[0]), cliClassifier(cliClassifier),
      dio(dio), isUploadedFiles(false), isClassified(false){};

void CLI::start()
{
    std::vector<command *> commands(6);
    uploadCommand u(dio, this);
    setParametersCommand sp(dio, this);
    classifyCommand c(dio, this);
    printClassificationCommand pc(dio, this);
    saveFileCommand sf(dio, this);
    confusionMatrix cm(dio, this);
    commands[0] = &u;
    commands[1] = &sp;
    commands[2] = &c;
    commands[3] = &pc;
    commands[4] = &sf;
    commands[5] = &cm;
    std::string menu = "";
    for (int i = 0; i < commands.size(); i++)
    {
        menu += (std::to_string(i) + ". " + commands[i]->getDescription() + "\n");
    }
    menu += "7. exit";
    while (1)
    {
        dio->write(menu);
        int i = std::stoi(dio->read());
        if (i == 7)
            break;
        commands[i]->execute();
    }
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

bool CLI::filesUploaded()
{
    return isUploadedFiles;
}

void CLI::setFilesUploadState(bool state)
{
    isUploadedFiles = state;
}

bool CLI::dataClassified()
{
    return isClassified;
}

void CLI::setClassificationState(bool state)
{
    isClassified = state;
}