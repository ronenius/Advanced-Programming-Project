#include "classifyCommand.hpp"
#include <iostream>

classifyCommand::classifyCommand(defaultIO *dio, CLI *cli)
    : command(dio, "classify data"), cli(cli){};

template <class T>
std::ostream &operator<<(std::ostream &o, std::vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        o << v[i] << std::endl;
    }
    return o;
}

std::ostream &operator<<(std::ostream &o, classifiable c)
{
    std::vector<double> v = c.getProperties();
    for (int i = 0; i < v.size(); i++)
    {
        o << v[i] << " ";
    }
    o << c.getCategory();
    return o;
}

void classifyCommand::execute()
{
    if (!cli->filesUploaded())
    {
        getIO()->write("Please upload data before classifying.\n");
        return;
    }
    std::cout << this->cli->getClassifier()->getCategories(this->cli->getTrainer(),
                                                           this->cli->getUnclassified(),
                                                           this->cli->getK(),
                                                           this->cli->getMetric());
    this->cli->setUnclassified(this->cli->getClassifier()->getCategories(this->cli->getTrainer(),
                                                                         this->cli->getUnclassified(),
                                                                         this->cli->getK(),
                                                                         this->cli->getMetric()));
    this->cli->setClassificationState(true);
    this->getIO()->write("classifying data complete\n");
}