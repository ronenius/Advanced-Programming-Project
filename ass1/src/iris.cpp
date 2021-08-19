#include "iris.hpp"
std::string iris::SETOSA = "setosa";
std::string iris::VIRGINICA = "virginica";
std::string iris::VERSICOLOR = "versicolor";
std::string iris::UNDEFINED = "undefined";
//initializes using the data and does nothing else.
iris::iris(std::string name, std::vector<double> properties) : name(name), properties(properties){};
//returns the name (category).
std::string iris::getName()
{
    return name;
}
//sets the name(category).
void iris::setName(std::string name)
{
    this->name = name;
}
//returns the properties of the flower.
std::vector<double> iris::getProperties()
{
    return properties;
}
//returns the distance to the other flower.
double iris::getDistance(iris other)
{
    //using the euclidean distance.
    return sqrt((properties[FIRST_FEATURE] - other.getProperties()[FIRST_FEATURE]) *
                    (properties[FIRST_FEATURE] - other.getProperties()[FIRST_FEATURE]) +
                (properties[SECOND_FEATURE] - other.getProperties()[SECOND_FEATURE]) *
                    (properties[SECOND_FEATURE] - other.getProperties()[SECOND_FEATURE]) +
                (properties[THIRD_FEATURE] - other.getProperties()[THIRD_FEATURE]) *
                    (properties[THIRD_FEATURE] - other.getProperties()[THIRD_FEATURE]) +
                (properties[FOURTH_FEATURE] - other.getProperties()[FOURTH_FEATURE]) *
                    (properties[FOURTH_FEATURE] - other.getProperties()[FOURTH_FEATURE]));
}