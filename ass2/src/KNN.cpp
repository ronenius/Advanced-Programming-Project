#include "KNN.hpp"
//returns the most common species in the vector.
static std::string getMax(std::vector<iris> irises)
{
    //a counter for each species.
    int count1 = 0, count2 = 0, count3 = 0;
    std::string name;
    for (int i = 0; i < irises.size(); i++)
    {
        name = irises[i].getName();
        //add 1 to the right counter.
        if (name == iris::SETOSA)
        {
            count1++;
        }
        else if (name == iris::VERSICOLOR)
        {
            count2++;
        }
        else
        {
            count3++;
        }
    }
    //find the maximum of the counters.
    int max12 = count1 > count2 ? count1 : count2;
    int max = max12 > count3 ? max12 : count3;
    //return the species that has the maximum.
    if (max == count1)
    {
        return iris::SETOSA;
    }
    if (max == count2)
    {
        return iris::VERSICOLOR;
    }
    return iris::VIRGINICA;
}
//changes the category of 'unclassified' to the most common category among the k nearest flowers.
static void getCategory(std::vector<iris> classified, iris &unclassified, int k)
{
    std::vector<iris> irises;
    //the minimal distance and the index of the flower with the minimal distance to 'unclassified'.
    int minIndex = 0;
    double min = unclassified.getDistance(classified[0]);
    //k times:
    for (int j = 0; j < k; j++)
    {
        //find the minimum.
        for (int i = 1; i < classified.size(); i++)
        {
            double distance = unclassified.getDistance(classified[i]);
            if (distance < min)
            {
                min = distance;
                minIndex = i;
            }
        }
        //add the minimum to the irises vector.
        irises.push_back(classified[minIndex]);
        //if n==k and we reached the end, break.
        if (classified.size() == 1)
            break;
        //switch the minimum with the last.
        classified[minIndex] = classified[classified.size() - 1];
        //remove the minimum.
        classified.pop_back();
        //reset the minimum and its index.
        minIndex = 0;
        min = unclassified.getDistance(classified[0]);
    }
    //find the most common category.
    std::string name = getMax(irises);
    unclassified.setName(name);
}
//returns a vector similar to unclassified, but with species. the species are calculated with KNN algorithm.
std::vector<iris> getCategories(std::vector<iris> classified, std::vector<iris> unclassified, int k)
{
    //calculate the species for every flower in 'unclassified'.
    for (int i = 0; i < unclassified.size(); i++)
    {
        getCategory(classified, unclassified[i], k);
    }
    return unclassified;
}