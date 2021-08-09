#include "io.hpp"
#include "KNN.hpp"
#define K 5
int main()
{
    std::vector<iris> classifiedData = importData("classified.csv");
    std::vector<iris> unclassifiedData = importData("unclassified.csv");
    std::vector<iris> newData = getCategories(classifiedData, unclassifiedData, K);
    exportData(newData, "output.csv");
}