#include "KNN.hpp"
static std::string getMax(std::vector<iris> irises)
{
    int count1 = 0, count2 = 0, count3 = 0;
    std::string name;
    for (int i = 0; i < irises.size(); i++)
    {
        name = irises[i].getName();
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
    int max12 = count1 > count2 ? count1 : count2;
    int max = max12 > count3 ? max12 : count3;
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
static void getCategory(std::vector<iris> classified, iris &unclassified, int k)
{
    std::vector<iris> irises;
    int minIndex = 0;
    double min = unclassified.getDistance(classified[0]);
    for (int j = 0; j < k; j++)
    {
        for (int i = 1; i < classified.size(); i++)
        {
            double distance = unclassified.getDistance(classified[i]);
            if (distance < min)
            {
                min = distance;
                minIndex = i;
            }
        }
        irises.push_back(classified[minIndex]);
        if (classified.size() == 1)
            break;
        classified[minIndex] = classified[classified.size() - 1];
        classified.pop_back();
        minIndex = 0;
        min = unclassified.getDistance(classified[0]);
    }
    std::string name = getMax(irises);
    unclassified.setName(name);
}
std::vector<iris> getCategories(std::vector<iris> classified, std::vector<iris> unclassified, int k)
{
    for (int i = 0; i < unclassified.size(); i++)
    {
        getCategory(classified, unclassified[i], k);
    }
    return unclassified;
}