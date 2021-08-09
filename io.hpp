#include "iris.hpp"
#include <fstream>
#include <sstream>
#define NUMBER_OF_PROPERTIES 4
std::vector<iris> importData(std::string path);
void exportData(std::vector<iris> data, std::string path);