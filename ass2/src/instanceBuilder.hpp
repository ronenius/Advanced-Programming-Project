#include "classifiable.hpp"
class instanceBuilder
{
public:
    //creates a knnable given the name and propeties.
    //if the name is 'undefined', it should create an unclassified knnable.
    virtual classifiable *createInstance(std::string name, std::vector<double> properties) = 0;
};