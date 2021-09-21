#include "../classifier/stringIO.hpp"
#include "../classifier/classifier.hpp"
#include "socketInterface.hpp"
#include "../classifier/classifiable.hpp"
#ifndef CLASSIFYING_SERVER
#define CLASSIFYING_SERVER

//The parent class for the classifying server
//(the udp and tcp servers). It has a classifying method
//That gets an unclassified string and classifies it.
class classifyingServer : public socketInterface
{
private:
    //The IO that turns a string into a vector
    //of classifiables and backwards.
    stringIO *serverIO;

    //The number of properties in the properties vector
    //of the classifiable and the K in the KNN classifier.
    int numProperties, k;

    //The used classifier in the server (in ours it's knn).
    classifier *serverClassifier;

    //The classified data to compare to the unclassified.
    std::vector<classifiable *> classifiedData;

public:
    //The constructor of the classifying server.
    classifyingServer(stringIO *serverIO, int numProperties, int k,
                      classifier *serverClassifier, std::vector<classifiable *> classifiedData);

    //The classify method that gets a string that represents an
    //unclassified data, classifies it and returns a classified string.
    std::string classify(std::string unClassifiedData);
};
#endif