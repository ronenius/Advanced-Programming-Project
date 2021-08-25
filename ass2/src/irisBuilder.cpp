#include "irisBuilder.hpp"
//creates a new iris with the names and properties given.
classifiable *createInstance(std::string name, std::vector<double> properties)
{
    return new iris(name, properties);
}