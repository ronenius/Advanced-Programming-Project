#include <vector>
#include <string>
#include "classifiable.hpp"
#ifndef IO_INTERFACE_HPP
#define IO_INTERFACE_HPP
//An interface describing a class that can write and read knnables from csv.
class ioInterface
{
public:
    //read the knnables.
    virtual std::vector<classifiable*> importData(std::string path, int numProperties) = 0;
    //write the knnables.
    virtual void exportData(std::vector<classifiable*> data, std::string path) = 0;
};
#endif;