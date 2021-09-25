#include <vector>
#include "command.hpp"
#include "../classifier/stringIO.hpp"
class CLI
{
private:
    defaultIO *dio;
    bool isUploadedFiles, isClassified;

public:
    CLI(defaultIO *dio);
    void start();
    std::vector<std::string> getPossibleMetrics();
};