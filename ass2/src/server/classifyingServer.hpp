#include "stringIO.hpp"
#include "classifier.hpp"
#include "socketInterface.hpp"
#include "classifiable.hpp"
#ifndef CLASSIFYING_SERVER
#define CLASSIFYING_SERVER
class classifyingServer : public socketInterface
{
private:
    stringIO *serverIO;
    int numProperties, k;
    classifier *serverClassifier;
    std::vector<classifiable *> classifiedData;

public:
    classifyingServer(stringIO *serverIO, int numProperties, int k, classifier *serverClassifier, std::vector<classifiable *> classifiedData);
    std::string classify(std::string unClassifiedData);
};
#endif