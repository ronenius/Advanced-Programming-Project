#include "instanceBuilder.hpp"

//creates a knnable given the name and propeties.
//if the name is 'undefined', it should create an unclassified knnable.
classifiable *createInstance(std::string name, std::vector<double> properties)
{
    return new classifiable(name, properties);
}