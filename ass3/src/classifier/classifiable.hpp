#include <string>
#include <vector>
#include <cmath>
#ifndef CLASSIFIABLE_HPP
#define CLASSIFIABLE_HPP
//An interface describing an object that the knn algorithm can be applied on.
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

    //returns the category of the object.
    //The classification will use this category to determine the category of the unclassified object.
    std::string getCategory();

    //sets the category of the object.
    void setCategory(std::string s);

    //returns the distance to another object.
    double getDistance(classifiable other);

    //returns the properties of the object.
    std::vector<double> getProperties();

    //returns all of the possible categories of the object, including 'unclassified'.
    std::vector<std::string> getPossibleCategories();

    //adds a new possible category to the classifiable.
    void addPossibleCategory(std::string category);
};
#endif