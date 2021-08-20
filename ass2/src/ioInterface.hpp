#include <vector>
#include <string>
#include "knnable.hpp"
class ioInterface
{
public:
    virtual std::vector<knnable*> importData(std::string path, int numProperties) = 0;
    virtual void exportData(std::vector<knnable*> data, std::string path) = 0;
};