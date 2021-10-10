#include <vector>
#include "command.hpp"
#include "../classifier/stringIO.hpp"
#include "../classifier/knnClassifier.hpp"
#ifndef CLI_HPP
#define CLI_HPP
//The CLI class that runs the commands.
class CLI
{
private:
    int k;
    std::string metric;
    classifier *cliClassifier;
    defaultIO *dio;
    stringIO csvIO;
    //marks if the files are uploaded/classified.
    bool isUploadedFiles, isClassified;
    //the training file.
    std::vector<classifiable> train;
    //the testing file.
    std::vector<classifiable> test;
    //the testing file, but without the classifications.
    std::vector<classifiable> unClassified;
    //the possible metrics.
    static std::vector<std::string> METRICS;

public:
    CLI(defaultIO *dio, classifier *cliClassifier);
    std::vector<std::string> getPossibleMetrics();
    //runs the commands.
    void start();
    int getK();
    void setK(int k);
    std::string getMetric();
    void setMetric(std::string metric);
    stringIO getCsvIO();
    classifier *getClassifier();
    void setClassifier(classifier *cliClassifier);
    //returns the trainer file (as classifiables vector).
    std::vector<classifiable> getTrainer();
    void setTrainer(std::vector<classifiable> trainer);
    //returns the test file (as classifiable vector).
    std::vector<classifiable> getTester();
    void setTester(std::vector<classifiable> tester);
    //returns the test file but without the classification.
    std::vector<classifiable> getUnclassified();
    void setUnclassified(std::vector<classifiable> unclassified);
    std::vector<classifiable> modifyClassifiedToUnclassified(std::vector<classifiable> classified);
    bool filesUploaded();
    void setFilesUploadState(bool state);
    bool dataClassified();
    void setClassificationState(bool state);
};
#endif