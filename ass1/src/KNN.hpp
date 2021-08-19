#include "iris.hpp"
//returns a vector similar to unclassified, but with species. the species are calculated with KNN algorithm.
std::vector<iris> getCategories(std::vector<iris> classified, std::vector<iris> unclassified, int k);