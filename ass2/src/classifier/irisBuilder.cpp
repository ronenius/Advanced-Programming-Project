#include "irisBuilder.hpp"

//creates a new iris with the names and properties given.
classifiable *irisBuilder::createInstance(std::string name, std::vector<double> properties)
{
    return new iris(name, properties);
}