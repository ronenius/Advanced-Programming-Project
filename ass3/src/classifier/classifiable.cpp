#include "classifiable.hpp"

//initializes using the data and does nothing else.
classifiable::classifiable(std::string name, std::vector<double> properties, std::vector<std::string> categories)
    : name(name), properties(properties), possibleCategories(categories){};

//returns the name (category).
std::string classifiable::getCategory()
{
    return name;
}

//sets the name(category).
void classifiable::setCategory(std::string name)
{
    this->name = name;
}

//returns the properties of the flower.
std::vector<double> classifiable::getProperties()
{
    return properties;
}

//returns the Euclidean distance to another classifiable.
double classifiable::getEuclideanDistance(classifiable other)
{
    std::vector<double> otherProperties = other.getProperties();
    //get the minimal length of the 2 properties vectors.
    int m = std::min(properties.size(), otherProperties.size());
    double sum = 0;
    //calculate the distance using euclidean distance.
    for (int i = 0; i < m; i++)
    {
        sum += (properties[i] - otherProperties[i]) * (properties[i] - otherProperties[i]);
    }
    return std::sqrt(sum);
}

//returns the Manhattan distance to another classifiable.
double classifiable::getManhattanDistance(classifiable other)
{
    std::vector<double> otherProperties = other.getProperties();
    //get the minimal length of the 2 properties vectors.
    int m = std::min(properties.size(), otherProperties.size());
    double sum = 0;
    //calculate the distance using euclidean distance.
    for (int i = 0; i < m; i++)
    {
        sum += std::abs(properties[i] - otherProperties[i]);
    }
    return sum;
}

//returns the Chebyshev distance to another classifiable.
double classifiable::getChebyshevDistance(classifiable other)
{
    std::vector<double> otherProperties = other.getProperties();
    //get the minimal length of the 2 properties vectors.
    int m = std::min(properties.size(), otherProperties.size());
    double max = 0;
    //calculate the distance using euclidean distance.
    for (int i = 0; i < m; i++)
    {
        if (max < std::abs(properties[i] - otherProperties[i]))
        {
            max = std::abs(properties[i] - otherProperties[i]);
        }
    }
    return max;
}

//returns the possible categories of the flower, including 'undefined', in the end of the vector.
std::vector<std::string> classifiable::getPossibleCategories()
{
    return classifiable::possibleCategories;
}

//adds a new possible category to the classifiable.
void classifiable::addPossibleCategory(std::string category)
{
    classifiable::possibleCategories.push_back(category);
}