#include "classifiable.hpp"
#include "io.hpp"
#include "instanceBuilder.hpp"
#include <fstream>
#include <sstream>
#ifndef ABSTRACT_IO_HPP
#define ABSTRACT_IO_HPP

//the standard implementation to ioInterface.
class csvIO : public io
{
private:
    instanceBuilder *builder;

public:
    //Creates an instance of the csvIO with the given builder.
    csvIO(instanceBuilder *builder);
    /**
     * The function gets a path to a csv file, opens it
     * and copies all the data about the knnables from the file
     * to a vector of knnables.
     */
    std::vector<classifiable *> importData(std::string path, int numProperties);
    /**
     * The function gets a vector of knnables and a path,
     * opens a csv file in the path and copies the data of the knnables
     * from the vector to the file.
     */
    void exportData(std::vector<classifiable *> data, std::string path);
};
#endif