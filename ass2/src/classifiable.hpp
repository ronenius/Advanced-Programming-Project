#include <string>
#include <vector>
#ifndef CLASSIFIABLE_HPP
#define CLASSIFIABLE_HPP
//An interface describing an object that the knn algorithm can be applied on.
class classifiable
{
public:
    //returns the category of the object. The classification will use this category to determine the category of the unclassified object.
    virtual std::string getCategory() = 0;
    //sets the category of the object.
    virtual void setCategory(std::string s) = 0;
    //returns the distance to another object.
    virtual double getDistance(classifiable *other) = 0;
    //returns the properties of the object.
    virtual std::vector<double> getProperties() = 0;
    //returns all of the possible categories of the object, including 'unclassified'.
    virtual std::vector<std::string> getPossibleCategories() = 0;
};
#endif