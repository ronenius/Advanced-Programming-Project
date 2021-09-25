#include <string>
#include <vector>
#include <cmath>
#ifndef CLASSIFIABLE_HPP
#define CLASSIFIABLE_HPP
//An interface describing an classifiable that the knn algorithm can be applied on.
class classifiable
{
private:
    std::string name;
    std::vector<double> properties;
    std::vector<std::string> possibleCategories;

public:
    //'name' is the category. expected to be one of the possible categories.
    //'propeties' is a vector discribing the flower's properties.
    classifiable(std::string name, std::vector<double> properties, std::vector<std::string> categories);

    //returns the category of the classifiable.
    //The classification will use this category to determine the category of the unclassified classifiable.
    std::string getCategory();

    //sets the category of the classifiable.
    void setCategory(std::string s);

    //returns the Euclidean distance to another classifiable.
    double getEuclideanDistance(classifiable other);

    //returns the Manhattan distance to another classifiable.
    double getManhattanDistance(classifiable other);

    //returns the Chebyshev distance to another classifiable.
    double getChebyshevDistance(classifiable other);

    //returns the properties of the classifiable.
    std::vector<double> getProperties();

    //returns all of the possible categories of the classifiable, including 'unclassified'.
    std::vector<std::string> getPossibleCategories();

    //adds a new possible category to the classifiable.
    void addPossibleCategory(std::string category);
};
#endif