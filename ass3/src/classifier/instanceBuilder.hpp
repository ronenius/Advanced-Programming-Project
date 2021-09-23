#include "classifiable.hpp"
#ifndef INSTANCE_BUILDER_HPP
#define INSTANCE_BUILDER_HPP
class instanceBuilder
{
public:
    //creates a knnable given the name and propeties.
    //if the name is 'undefined', it should create an unclassified knnable.
    classifiable *createInstance(std::string name, std::vector<double> properties);
};
#endif