#ifndef irishpp
#define irishpp
#include <string>
#include <vector>
#include <cmath>
#define FIRST_FEATURE 0
#define SECOND_FEATURE 1
#define THIRD_FEATURE 2
#define FOURTH_FEATURE 3
//manages the flower's details and distances.
class iris
{
private:
    std::string name;
    std::vector<double> properties;

public:
    static std::string SETOSA;
    static std::string VIRGINICA;
    static std::string VERSICOLOR;
    static std::string UNDEFINED;
    //'name' is the category. expected to be one of the 4 possible cattegories.
    //'propeties' is a vector discribing the flower's properties.
    iris(std::string name, std::vector<double> properties);
    //returns the name (category) of the flower.
    std::string getName();
    //sets the name (category) of the flower.
    void setName(std::string name);
    //returns the propeties of the flower.
    std::vector<double> getProperties();
    //returns the distance to the other flower.
    double getDistance(iris other);
};
#endif