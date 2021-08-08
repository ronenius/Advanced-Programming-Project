#include "iris.hpp"
std::string iris::SETOSA = "setosa";
std::string iris::VIRGINICA = "virginica";
std::string iris::VERSICOLOR = "versicolor";
std::string iris::UNDEFINED = "undefined";
iris::iris(std::string name, std::vector<double> properties) : name(name), properties(properties){};
std::string iris::getName()
{
    return name;
}
void iris::setName(std::string name)
{
    this->name = name;
}
std::vector<double> iris::getProperties()
{
    return properties;
}
double iris::getDistance(iris other)
{
    return sqrt((properties[0] - other.getProperties()[0]) * (properties[0] - other.getProperties()[0]) 
    + (properties[1] - other.getProperties()[1]) * (properties[1] - other.getProperties()[1])
     + (properties[2] - other.getProperties()[2]) * (properties[2] - other.getProperties()[2]) 
     + (properties[3] - other.getProperties()[3]) * (properties[3] - other.getProperties()[3]));
}