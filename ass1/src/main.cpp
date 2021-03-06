#include "io.hpp"
#include "KNN.hpp"

// The KNN classifier works with K=5.
#define K 5

int main()
{
    /**
     * Imports the data about the classified and unclassified
     * irises from the file to vectors of irises.
     */
    std::vector<iris> classifiedData = importData("../classified.csv");
    std::vector<iris> unclassifiedData = importData("../Unclassified.csv");

    /**
     * Runs the classifier on the unclassified irises
     * and returns a new vector with the newly classified irises.
     */
    std::vector<iris> newData = getCategories(classifiedData, unclassifiedData, K);
    // Exports the new vector to an output csv file.
    exportData(newData, "../output.csv");
    return 0;
}