#include "classifiable.hpp"

//initializes using the data and does nothing else.
classifiable::classifiable(std::string name, std::vector<double> properties) : name(name), properties(properties){};

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

//returns the distance to the other flower.
double classifiable::getDistance(classifiable *other)
{
    std::vector<double> otherProperties = other->getProperties();
    //get the minimal length of the 2 properties vectors.
    int m = std::min(properties.size(), otherProperties.size());
    double sum = 0;
    //calculate the distance using euclidean distance.
    for (int i = 0; i < m; i++)
    {
        sum += (properties[i] - otherProperties[i]) * (properties[i] - otherProperties[i]);
    }
    return sqrt(sum);
}

//returns the possible categories of the flower, including 'undefined', in the end of the vector.
std::vector<std::string> classifiable::getPossibleCategories()
{
    return classifiable::CATEGORIES;
}

//adds a new possible category to the classifiable.
void classifiable::addPossibleCategory(std::string category)
{
    classifiable::CATEGORIES.push_back(category);
}