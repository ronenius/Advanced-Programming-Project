#include "knnClassifier.hpp"

//returns the most common category in the vector.
std::string knnClassifier::getMax(std::vector<classifiable> classifiables)
{
    //a counter for each category.
    std::vector<std::string> categories = classifiables[0].getPossibleCategories();
    std::vector<int> counters(categories.size(), 0);
    std::string name;
    for (int i = 0; i < classifiables.size(); i++)
    {
        name = classifiables[i].getCategory();
        //add 1 to the right counter.
        for (int j = 0; j < categories.size(); j++)
        {
            if (categories[j] == name)
            {
                counters[j]++;
            }
        }
    }
    //find the maximum of the counters.
    int max = 0, maxIndex = 0;
    for (int i = 0; i < categories.size(); i++)
    {
        if (counters[i] > max)
        {
            max = counters[i];
            maxIndex = i;
        }
    }
    //return the category that has the maximum.
    return categories[maxIndex];
}

//changes the category of 'unclassified' to the most common category among the k nearest knnables.
void knnClassifier::getCategory(std::vector<classifiable> classified,
                                classifiable &unclassified, int k, std::string metric)
{
    std::vector<classifiable> knnables;
    //the minimal distance and the index of the knnable with the minimal distance to 'unclassified'.
    int minIndex = 0;
    double min = 0;
    if (metric.compare("EUC") == 0)
        min = unclassified.getEuclideanDistance(classified[0]);
    else if (metric.compare("MAN") == 0)
        min = unclassified.getManhattanDistance(classified[0]);
    else
        min = unclassified.getChebyshevDistance(classified[0]);
    //k times:
    for (int j = 0; j < k; j++)
    {
        //find the minimum.
        for (int i = 1; i < classified.size(); i++)
        {
            double distance = 0;
            if (metric.compare("EUC") == 0)
                distance = unclassified.getEuclideanDistance(classified[i]);
            else if (metric.compare("MAN") == 0)
                distance = unclassified.getManhattanDistance(classified[i]);
            else
                distance = unclassified.getChebyshevDistance(classified[i]);
            if (distance < min)
            {
                min = distance;
                minIndex = i;
            }
        }
        //add the minimum to the knnables vector.
        knnables.push_back(classified[minIndex]);
        //if n==k and we reached the end, break.
        if (classified.size() == 1)
            break;
        //switch the minimum with the last.
        classifiable temp = classified[minIndex];
        classified[minIndex] = classified[classified.size() - 1];
        classified[classified.size() - 1] = temp;
        //remove the minimum.
        classified.pop_back();
        //reset the minimum and its index.
        minIndex = 0;
        if (metric.compare("EUC") == 0)
            min = unclassified.getEuclideanDistance(classified[0]);
        else if (metric.compare("MAN") == 0)
            min = unclassified.getManhattanDistance(classified[0]);
        else
            min = unclassified.getChebyshevDistance(classified[0]);
    }
    //find the most common category.
    std::string name = getMax(knnables);
    unclassified.setCategory(name);
}

//returns a vector similar to unclassified, but with categories.
//The categories are calculated with KNN algorithm.
std::vector<classifiable> knnClassifier::getCategories(
    std::vector<classifiable> classified,
    std::vector<classifiable> unclassified, int k, std::string metric)
{
    //calculate the category for every knnable in 'unclassified'.
    for (int i = 0; i < unclassified.size(); i++)
    {
        this->getCategory(classified, unclassified[i], k, metric);
    }
    return unclassified;
}