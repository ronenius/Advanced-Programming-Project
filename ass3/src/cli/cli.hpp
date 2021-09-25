#include <vector>
#include "command.hpp"
#include "../classifier/stringIO.hpp"
class CLI
{
private:
    int k;
    std::string metric;
    defaultIO *dio;
    bool isUploadedFiles, isClassified;
    static std::vector<std::string> METRICS;

public:
    CLI(defaultIO *dio);
    void start();
    std::vector<std::string> getPossibleMetrics();
};