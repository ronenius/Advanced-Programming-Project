#include "iris.hpp"
std::string iris::SETOSA = "setosa";
std::string iris::VIRGINICA = "virginica";
std::string iris::VERSICOLOR = "versicolor";
std::string iris::UNDEFINED = "undefined";
iris::iris(std::string name, std::vector<double> properties) : name(name), properties(properties){};