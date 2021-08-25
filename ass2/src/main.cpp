#include "csvIO.hpp"
#include "knnClassifier.hpp"
#include "irisBuilder.hpp"

// The KNN classifier works with K=5.
#define K 1

int main()
{
    irisBuilder builder;
    csvIO irisIO(&builder);
    knnClassifier classifier;
    std::vector<classifiable *> classifiedData = irisIO.importData("classified.csv", 4);
    std::vector<classifiable *> unclassifiedData = irisIO.importData("unclassified.csv", 4);
    std::vector<classifiable *> newData = classifier.getCategories(classifiedData, unclassifiedData, K);
    irisIO.exportData(newData, "output.csv");
    return 0;
}