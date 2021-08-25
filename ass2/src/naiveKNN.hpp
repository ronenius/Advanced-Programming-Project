#include "KNN.hpp"
#ifndef NAIVE_KNN_HPP
#define NAIVE_KNN_HPP
//A naive implimentation of the knn algorithm.
class naiveKNN : public KNN
{
    public:
        //returns a vector similar to unclassified, but with categories. the categories are calculated with KNN algorithm.
        std::vector<knnable*> getCategories(std::vector<knnable*> classified, std::vector<knnable*> unclassified, int k);
};
#endif