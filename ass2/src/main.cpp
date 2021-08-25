#include "csvIO.hpp"
#include "knnClassifier.hpp"
#include "irisBuilder.hpp"

#include <iostream>

// The KNN classifier works with K=5.
#define K 5

int main()
{
    irisBuilder builder;
    csvIO irisIO(&builder);
    knnClassifier classifier;
    std::vector<classifiable *> classifiedData = irisIO.importData("C:\\Users\\RONEN\\Desktop\\proj2\\Advanced-Programming-Project\\ass2\\classified.csv", 4);
    std::vector<classifiable *> unclassifiedData = irisIO.importData("C:\\Users\\RONEN\\Desktop\\proj2\\Advanced-Programming-Project\\ass2\\unclassified.csv", 4);
    std::vector<classifiable *> newData = classifier.getCategories(classifiedData, unclassifiedData, K);
    irisIO.exportData(newData, "C:\\Users\\RONEN\\Desktop\\proj2\\Advanced-Programming-Project\\ass2\\output.csv");
    return 0;
}