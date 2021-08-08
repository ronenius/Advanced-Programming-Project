#include "io.hpp"
#include "KNN.hpp"
int main()
{
    std::vector<iris> classifiedData = importData("classified.csv");
    std::vector<iris> unclassifiedData = importData("unclassified.csv");
    std::vector<iris> newData = getCategories(classifiedData, unclassifiedData, 5);
    exportData(newData);
}