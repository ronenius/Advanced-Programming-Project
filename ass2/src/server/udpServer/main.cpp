#include "udpSocket.hpp"
#include "irisBuilder.hpp"
#include "knnClassifier.hpp"

#define NUM_PROPERTIES 4
#define K 5

int main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    irisBuilder builder;
    stringIO serverIO(&builder);
    knnClassifier classif;
    std::vector<classifiable *> classifiedData = serverIO.importStringToVector(serverIO.importFileToString("../../../data/classified.csv"), NUM_PROPERTIES);
    udpSocket udpServer(sock, &serverIO, NUM_PROPERTIES, K, &classif, classifiedData);
    udpServer.bind();
    while (true)
    {
        std::string message = udpServer.receive();
        if (message.compare("hello") == 0)
        {
            continue;
        }
        else
        {
            std::string newData = udpServer.classify(message);
            udpServer.send(newData);
        }
    }
    udpServer.closeSocket();
}