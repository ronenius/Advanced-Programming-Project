#include "classifyingServer.hpp"

//The constructor of the classifying server.
classifyingServer::classifyingServer(stringIO *serverIO, int numProperties, int k,
                                     classifier *serverClassifier,
                                     std::vector<classifiable *> classifiedData)
    : serverIO(serverIO), numProperties(numProperties), k(k),
      serverClassifier(serverClassifier), classifiedData(classifiedData){};

//The classify method that gets a string that represents an
//unclassified data, classifies it and returns a classified string.
std::string classifyingServer::classify(std::string unClassifiedData)
{
  //Converts the string data to a vector of classifiables.
  std::vector<classifiable *> vecData =
      this->serverIO->importStringToVector(unClassifiedData, numProperties);
  //Classifies the unclassified vactor and returns a classified vector.
  std::vector<classifiable *> newData =
      this->serverClassifier->getCategories(this->classifiedData, vecData, this->k);
  //Converts the classified vector to a string of categories.
  std::string newClassifiedData = this->serverIO->exportVectorToString(newData);
  //Returns the string.
  return newClassifiedData;
}