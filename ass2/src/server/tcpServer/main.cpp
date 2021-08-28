#include "tcpSocket.hpp"
#include "tcpServer.hpp"
#include "../../classifier/irisBuilder.hpp"
#include "../../classifier/knnClassifier.hpp"

#define NUM_PROPERTIES 4
#define K 5

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    tcpServer TCPServer(sock);
    TCPServer.bind();
    while (true)
    {
        TCPServer.listen();
        int clientSock = TCPServer.accept();
        irisBuilder builder;
        stringIO serverIO(&builder);
        knnClassifier classif;
        std::vector<classifiable *> classifiedData = serverIO.importStringToVector(serverIO.importFileToString("/home/ronenius/proj/Advanced-Programming-Project/ass2/data/classified.csv"), NUM_PROPERTIES);
        tcpSocket tcp(clientSock, &serverIO, NUM_PROPERTIES, K, &classif, classifiedData);
        tcp.send("Connection was successful. Please choose what to classify:");
        std::string message = tcp.receive();
        std::string newData = tcp.classify(message);
        tcp.send(newData);
        tcp.closeSocket();
    }
    return 0;
}