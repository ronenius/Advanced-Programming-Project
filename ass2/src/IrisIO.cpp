#include "abstractIO.hpp"
#include "iris.hpp"
#include <vector>
#include <string>
class IrisIO : abstractIO
{
    public:
    knnable* createInstance(std::string name, std::vector<double> properties) {
        return new iris(name, properties);
    }
};
