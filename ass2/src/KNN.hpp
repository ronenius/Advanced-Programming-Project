#include "knnable.hpp"
class KNN {
    //returns a vector similar to unclassified, but with species. the species are calculated with KNN algorithm.
    virtual std::vector<knnable*> getCategories(std::vector<knnable*> classified, std::vector<knnable*> unclassified, int k) = 0;
};