#include "classifyingServer.hpp"
std::string classifyingServer::classify(std::string unClassifiedData)
{
    std::vector<classifiable *> vecData = this->serverIO->importStringToVector(unClassifiedData, numProperties);
    std::vector<classifiable *> newData = this->serverClassifier->getCategories(this->classifiedData, vecData, this->k);
    std::string newClassifiedData = this->serverIO->exportVectorToString(newData);
    return newClassifiedData;
}