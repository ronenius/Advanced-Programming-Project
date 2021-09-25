#include "confusionMatrix.hpp"
confusionMatrix::confusionMatrix(defaultIO* dio, CLI* cli) : command(dio, "display algorithm confusion matrix"), cli(cli) { }
void confusionMatrix::execute()
{
    if (!cli->dataClassified()) {
        getIO()->write("Please upload data and classify it before calculating the consufion matrix.");
        return;
    }
    std::vector<classifiable> test = cli->getTester(), classification = cli->getUnclassified();
    std::vector<std::string> categories = test[0].getPossibleCategories();
    std::string message;
    for (int i = 0; i < categories.size(); i++) {
        message+=(categories[i]+"\t");
        for (int j = 0; j < categories.size(); j++) {
            double countI = 0, countJ = 0;
            for (int k = 0; k < test.size(); k++) {
                if (test[k].getCategory()==categories[i]) {
                    countI++;
                    if (classification[k].getCategory() == categories[j]) {
                        countJ++;
                    }
                }
            }
            message += (std::to_string(countI / countI * 100) + "\t");
        }
        message += "\n";
    }
    message+=("The current KNN parameters are: K = " + std::to_string(this->cli->getK()) +
                         ", distance metric = " + this->cli->getMetric());
    getIO()->write(message);
}