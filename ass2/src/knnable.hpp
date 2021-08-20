#include <string>
#include <vector>
class knnable
{
public:
    virtual std::string getCategory() = 0;
    virtual void setCategory(std::string s) = 0;
    virtual double getDistance(knnable* other) = 0;
    virtual std::vector<double> getProperties() = 0;
    static std::vector<std::string> getPossibleCategories();
};