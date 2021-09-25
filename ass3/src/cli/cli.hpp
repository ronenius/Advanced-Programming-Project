#include <vector>
#include "command.hpp"
#include "../classifier/stringIO.hpp"
#include "../classifier/knnClassifier.hpp"
class CLI
{
private:
    int k;
    std::string metric;
    classifier *cliClassifier;
    defaultIO *dio;
    stringIO csvIO;
    bool isUploadedFiles, isClassified;
    std::vector<classifiable> train;
    std::vector<classifiable> test;
    std::vector<classifiable> unClassified;
    static std::vector<std::string> METRICS;

public:
    CLI(defaultIO *dio, classifier *cliClassifier);
    std::vector<std::string> getPossibleMetrics();
    void start();
    int getK();
    void setK(int k);
    std::string getMetric();
    void setMetric(std::string metric);
    stringIO getCsvIO();
    classifier *getClassifier();
    void setClassifier(classifier *cliClassifier);
    std::vector<classifiable> getTrainer();
    void setTrainer(std::vector<classifiable> trainer);
    std::vector<classifiable> getTester();
    void setTester(std::vector<classifiable> tester);
    std::vector<classifiable> getUnclassified();
    void setUnclassified(std::vector<classifiable> unclassified);
    std::vector<classifiable> modifyClassifiedToUnclassified(std::vector<classifiable> classified);
};