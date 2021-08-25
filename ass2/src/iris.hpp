#include <string>
#include <vector>
#include <cmath>
#include "knnable.hpp"
#ifndef irishpp
#define irishpp
class iris : public knnable
{
private:
    std::string name;
    std::vector<double> properties;
    static std::vector<std::string> CATEGORIES;
public:
    //'name' is the category. expected to be one of the possible cattegories.
    //'propeties' is a vector discribing the flower's properties.
    iris(std::string name, std::vector<double> properties);
    //returns the name (category) of the flower.
    std::string getCategory();
    //sets the name (category) of the flower.
    void setCategory(std::string name);
    //returns the propeties of the flower.
    std::vector<double> getProperties();
    //returns the distance to the other flower.
    double getDistance(knnable* other);
    //returns the possible categories of the flower, including 'undefined', in the end of the vector.
    static std::vector<std::string> getPossibleCategories();
};
#endif