#include "classifyingServer.hpp"
classifyingServer::classifyingServer(stringIO *serverIO, int numProperties, int k,
                                     classifier *serverClassifier, std::vector<classifiable *> classifiedData)
    : serverIO(serverIO), numProperties(numProperties), k(k),
      serverClassifier(serverClassifier), classifiedData(classifiedData){};

std::string classifyingServer::classify(std::string unClassifiedData)
{
    std::vector<classifiable *> vecData = this->serverIO->importStringToVector(unClassifiedData, numProperties);
    std::vector<classifiable *> newData = this->serverClassifier->getCategories(this->classifiedData, vecData, this->k);
    std::string newClassifiedData = this->serverIO->exportVectorToString(newData);
    return newClassifiedData;
}