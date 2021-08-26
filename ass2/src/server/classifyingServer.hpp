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
    std::string classify(std::string unClassifiedData);
};