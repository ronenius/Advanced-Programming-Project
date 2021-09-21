#include "classifier.hpp"
#ifndef NAIVE_KNN_HPP
#define NAIVE_KNN_HPP
//A naive implimentation of the knn algorithm.
class knnClassifier : public classifier
{
private:
    //returns the most common category in the vector.
    std::string getMax(std::vector<classifiable *> classifiables);

    //changes the category of 'unclassified' to the most common category among the k nearest knnables.
    void getCategory(std::vector<classifiable *> classified, classifiable *unclassified, int k);

public:
    //returns a vector similar to unclassified, but with categories. the categories are calculated with KNN algorithm.
    std::vector<classifiable *> getCategories(
        std::vector<classifiable *> classified,
        std::vector<classifiable *> unclassified, int k);
};
#endif