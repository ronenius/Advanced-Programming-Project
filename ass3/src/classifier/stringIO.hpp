#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "classifiable.hpp"
#include "instanceBuilder.hpp"
#ifndef STRING_IO_HPP
#define STRING_IO_HPP
//The class that imports and exports all of the data
//to files and backwards
class stringIO
{
private:
    instanceBuilder *builder;

public:
    //Constructor of the class.
    stringIO(instanceBuilder *builder);

    //Copies a file to a string.
    std::string importFileToString(std::string path);

    //Processes the string and build a vector of classifiables out of it.
    std::vector<classifiable *> importStringToVector(std::string data, int numProperties);

    //Copies the categories of the vector to a string.
    std::string exportVectorToString(std::vector<classifiable *> data);

    //Copies the string to a file in the path.
    void exportStringToFile(std::string path, std::string data);
};
#endif