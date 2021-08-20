#include "naiveKNN.hpp"
//returns the most common species in the vector.
static std::string getMax(std::vector<knnable*> knnables)
{
    //a counter for each species.
    std::vector<std::string> categories = knnables[0]->getPossibleCategories();
    std::vector<int> counters(categories.size(), 0);
    std::string name;
    for (int i = 0; i < knnables.size(); i++)
    {
        name = knnables[i]->getCategory();
        //add 1 to the right counter.
        for (int j = 0; j < categories.size(); j++) {
            if (categories[j] == knnables[i]->getCategory()) {
                counters[j]++;
            }
        }
    }
    //find the maximum of the counters.
    int max = 0, maxIndex = 0;
    for (int i = 0; i < categories.size(); i++) {
        if (counters[i] > max) {
            max = counters[i];
            maxIndex = i;
        }
    }
    //return the species that has the maximum.
    return categories[maxIndex];
}
//changes the category of 'unclassified' to the most common category among the k nearest flowers.
static void getCategory(std::vector<knnable*> &classified, knnable* &unclassified, int k)
{
    std::vector<knnable*> knnables;
    //the minimal distance and the index of the flower with the minimal distance to 'unclassified'.
    int minIndex = 0;
    double min = unclassified->getDistance(classified[0]);
    //k times:
    for (int j = 0; j < k; j++)
    {
        //find the minimum.
        for (int i = 1; i < classified.size(); i++)
        {
            double distance = unclassified->getDistance(classified[i]);
            if (distance < min)
            {
                min = distance;
                minIndex = i;
            }
        }
        //add the minimum to the irises vector.
        knnables.push_back(classified[minIndex]);
        //if n==k and we reached the end, break.
        if (classified.size() == 1)
            break;
        //switch the minimum with the last.
        classified[minIndex] = classified[classified.size() - 1];
        //remove the minimum.
        classified.pop_back();
        //reset the minimum and its index.
        minIndex = 0;
        min = unclassified->getDistance(classified[0]);
    }
    //find the most common category.
    std::string name = getMax(knnables);
    unclassified->setCategory(name);
}
//returns a vector similar to unclassified, but with species. the species are calculated with KNN algorithm.
std::vector<knnable*> naiveKNN::getCategories(std::vector<knnable*> classified, std::vector<knnable*> unclassified, int k)
{
    //calculate the species for every flower in 'unclassified'.
    for (int i = 0; i < unclassified.size(); i++)
    {
        getCategory(classified, unclassified[i], k);
    }
    return unclassified;
}