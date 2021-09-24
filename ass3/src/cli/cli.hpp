#include <vector>
#include "command.hpp"
#include "../classifier/classifiable.hpp"
class CLI
{
private:
    int k;
    std::string metric;
    defaultIO *dio;
    std::vector<classifiable *> train;
    std::vector<classifiable *> test;
    std::vector<classifiable *> unClassified;
    static std::vector<std::string> METRICS;

public:
    CLI(defaultIO *dio);
    void start();
    std::vector<std::string> getPossibleMetrics();
};