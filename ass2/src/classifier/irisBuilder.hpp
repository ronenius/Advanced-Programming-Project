#include "instanceBuilder.hpp"
#include "iris.hpp"
#include <vector>
#include <string>
#ifndef IRIS_BUILDER_HPP
#define IRIS_BUILDER_HPP
//reads and writes irises to csv.
class irisBuilder : public instanceBuilder
{
public:
    //creates a new iris with the names and properties given.
    classifiable *createInstance(std::string name, std::vector<double> properties);
};
#endif