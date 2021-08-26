#include "stringIO.hpp"
#include "knnClassifier.hpp"
#include "irisBuilder.hpp"

#include <iostream>

// The KNN classifier works with K=5.
#define K 5

int main()
{
    irisBuilder builder;
    stringIO irisIO(&builder);
    knnClassifier classifier;
    std::vector<classifiable *> classifiedData = irisIO.importStringToVector(irisIO.importFileToString("../../classified.csv"), 4);
    std::cout << irisIO.importFileToString("unclassified.csv");
    std::vector<classifiable *> unclassifiedData = irisIO.importStringToVector(irisIO.importFileToString("../../unclassified.csv"), 4);
    std::vector<classifiable *> newData = classifier.getCategories(classifiedData, unclassifiedData, K);
    irisIO.exportStringToFile("../../output.csv", irisIO.exportVectorToString(newData));
    return 0;
}