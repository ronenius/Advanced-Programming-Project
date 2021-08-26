#include "stringIO.hpp"
#include "classifier.hpp"
#include "serverSocket.hpp"
#include "classifiable.hpp"
class classifyingServer : public serverSocket
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