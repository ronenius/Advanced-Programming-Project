#include "cli.hpp"

std::vector<std::string> CLI::METRICS = {"EUC", "MAN", "CHE"};

CLI::CLI(defaultIO *dio)
    : k(5), metric(CLI::METRICS[0]), dio(dio), isUploadedFiles(false), isClassified(false){};

void CLI::start()
{
}

std::vector<std::string> CLI::getPossibleMetrics()
{
    return CLI::METRICS;
}