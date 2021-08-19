#include "iris.hpp"
#include <fstream>
#include <sstream>

// Every iris has 4 properties apart of it's name.
#define NUMBER_OF_PROPERTIES 4

/**
 * The function gets a path to a csv file, opens it
 * and copies all the data about the irises from the file
 * to a vector of irises.
 */
std::vector<iris> importData(std::string path);

/**
 * The function gets a vector of irises and a path,
 * opens a csv file in the path and copies the data of the irises
 * from the vector to the file.
 */
void exportData(std::vector<iris> data, std::string path);