#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "classifiable.hpp"
#include "instanceBuilder.hpp"
class stringIO
{
private:
    instanceBuilder *builder;

public:
    stringIO(instanceBuilder *builder);
    std::string importFileToString(std::string path);
    std::vector<classifiable *> importStringToVector(std::string data, int numProperties);
    std::string exportVectorToString(std::vector<classifiable *> data);
    void exportStringToFile(std::string path, std::string data);
};