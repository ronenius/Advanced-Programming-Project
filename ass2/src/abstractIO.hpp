#include "knnable.hpp"
#include "ioInterface.hpp"
#include <fstream>
#include <sstream>
#ifndef ABSTRACT_IO_HPP
#define ABSTRACT_IO_HPP
//the standard implementation to ioInterface.
class abstractIO : public ioInterface {
    /**
     * The function gets a path to a csv file, opens it
     * and copies all the data about the knnables from the file
     * to a vector of knnables.
     */
    std::vector<knnable*> importData(std::string path, int numProperties);

    /**
     * The function gets a vector of knnables and a path,
     * opens a csv file in the path and copies the data of the knnables
     * from the vector to the file.
     */
    void exportData(std::vector<knnable*> data, std::string path);

    //creates a knnable given the name and propeties. if the name is 'undefined', it should create an unclassified knnable.
    knnable* createInstance(std::string name, std::vector<double> properties);
};
#endif