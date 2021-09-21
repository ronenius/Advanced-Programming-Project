#include "classifiable.hpp"
#ifndef CLASSIFIER_HPP
#define CLASSIFIER_HPP
//An interface of a classifier algorithm class.
class classifier
{
public:
    //returns a vector similar to unclassified, but with categories.
    //the categories are calculated with KNN algorithm.
    virtual std::vector<classifiable *> getCategories(std::vector<classifiable *> classified,
                                                      std::vector<classifiable *> unclassified, int k) = 0;
};
#endif