#include "iris.hpp"
std::vector<std::string> iris::CATEGORIES = {"Iris-setosa", "Iris-virginica", "Iris-versicolor", "undefined"};
//initializes using the data and does nothing else.
iris::iris(std::string name, std::vector<double> properties) : name(name), properties(properties){};
//returns the name (category).
std::string iris::getCategory()
{
    return name;
}
//sets the name(category).
void iris::setCategory(std::string name)
{
    this->name = name;
}
//returns the properties of the flower.
std::vector<double> iris::getProperties()
{
    return properties;
}
//returns the distance to the other flower.
double iris::getDistance(knnable* other)
{
    std::vector<double> otherProperties = other->getProperties();
    //get the minimal length of the 2 properties vectors.
    int m = std::min(properties.size(), otherProperties.size()), sum = 0;
    //calculate the distance using euclidean distance.
    for (int i = 0; i < m; i++) {
        sum += (properties[i] - otherProperties[i]) * (properties[i] - otherProperties[i]);
    }
    return sqrt(sum);
}
std::vector<std::string> iris::getPossibleCategories() {
    return iris::CATEGORIES;
}