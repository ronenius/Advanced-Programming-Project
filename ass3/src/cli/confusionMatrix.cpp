#include "confusionMatrix.hpp"

confusionMatrix::confusionMatrix(defaultIO *dio, CLI *cli)
    : command(dio, "display algorithm confusion matrix"), cli(cli){};

void confusionMatrix::execute()
{
    if (!cli->filesUploaded())
    {
        getIO()->write("Please upload data before calculating the confusion matrix.\n");
        while (getIO()->read() != "\n")
            ;
        return;
    }
    //reclassify, in case the classification parameters has changed or the files are not even classified.
    this->cli->setUnclassified(this->cli->getClassifier()->getCategories(this->cli->getTrainer(),
                                                                         this->cli->getUnclassified(),
                                                                         this->cli->getK(),
                                                                         this->cli->getMetric()));
    this->cli->setClassificationState(true);
    std::vector<classifiable> test = cli->getTester(), classification = cli->getUnclassified();
    std::vector<std::string> categories = test[0].getPossibleCategories();
    std::string message;
    //for every category
    for (int i = 0; i < categories.size(); i++)
    {
        //add to the message the category and tab
        message += (categories[i] + "\t");
        //for every category
        for (int j = 0; j < categories.size(); j++)
        {
            double countI = 0, countJ = 0;
            //count how many categories are category i, and how many of them were cassified as category j.
            for (int k = 0; k < test.size(); k++)
            {
                if (test[k].getCategory() == categories[i])
                {
                    countI++;
                    if (classification[k].getCategory() == categories[j])
                    {
                        countJ++;
                    }
                }
            }
            //add the presentage of countJ/countI.
            message += (std::to_string(countJ / countI * 100) + "\t");
        }
        message += "\n";
    }
    message += ("The current KNN parameters are: K = " + std::to_string(this->cli->getK()) +
                ", distance metric = " + this->cli->getMetric() + "\n");
    getIO()->write(message);
    //wait for "\n".
    while (getIO()->read() != "\n")
        ;
}