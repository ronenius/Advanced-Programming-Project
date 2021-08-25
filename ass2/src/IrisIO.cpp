#include "abstractIO.hpp"
#include "iris.hpp"
#include <vector>
#include <string>
//reads and writes irises to csv.
class IrisIO : public abstractIO
{
    public:
    //creates a new iris with the names and properties given.
    classifiable* createInstance(std::string name, std::vector<double> properties) {
        return new iris(name, properties);
    }
};
