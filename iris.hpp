#ifndef irishpp
#define irishpp
#include <string>
#include <vector>
#include <cmath>
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
    iris(std::string name, std::vector<double> properties);
    std::string getName();
    void setName(std::string name);
    std::vector<double> getProperties();
    double getDistance(iris other);
};
#endif