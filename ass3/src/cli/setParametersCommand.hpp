#include "command.hpp"
#include <vector>

class setParametersCommand : public command
{
private:
    int K;
    std::string metric;
    static std::vector<std::string> METRICS;

public:
    setParametersCommand(defaultIO *dio, std::string description);
    void execute();
    int getK();
    std::string getMetric();
};