#include "knnable.hpp"
#include "ioInterface.hpp"
#include <fstream>
#include <sstream>
class abstractIO : public ioInterface {
    /**
     * The function gets a path to a csv file, opens it
     * and copies all the data about the irises from the file
     * to a vector of irises.
     */
    std::vector<knnable*> importData(std::string path, int numProperties);

    /**
     * The function gets a vector of irises and a path,
     * opens a csv file in the path and copies the data of the irises
     * from the vector to the file.
     */
    void exportData(std::vector<knnable*> data, std::string path);
    knnable* createInstance(std::string name, std::vector<double> properties);
};