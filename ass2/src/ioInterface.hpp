#include <vector>
#include <string>
#include "classifiable.hpp"
#ifndef IO_INTERFACE_HPP
#define IO_INTERFACE_HPP
//An interface describing a class that can write and read knnables from csv.
class ioInterface
{
public:
    /**
     * The function gets a path to a csv file, opens it
     * and copies all the data about the knnables from the file
     * to a vector of knnables.
     */
    virtual std::vector<classifiable *> importData(std::string path, int numProperties) = 0;

    /**
     * The function gets a vector of knnables and a path,
     * opens a csv file in the path and copies the data of the knnables
     * from the vector to the file.
     */
    virtual void exportData(std::vector<classifiable *> data, std::string path) = 0;
};
#endif;