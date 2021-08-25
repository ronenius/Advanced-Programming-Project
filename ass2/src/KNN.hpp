#include "knnable.hpp"
#ifndef KNN_HPP
#define KNN_HPP
//An interface of a knn algorithm class.
class KNN {
    //returns a vector similar to unclassified, but with categories. the categories are calculated with KNN algorithm.
    virtual std::vector<knnable*> getCategories(std::vector<knnable*> classified, std::vector<knnable*> unclassified, int k) = 0;
};
#endif