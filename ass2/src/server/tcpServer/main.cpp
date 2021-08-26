#include "tcpSocket.hpp"
#include "tcpServer.hpp"
#include "irisBuilder.hpp"
#include "knnClassifier.hpp"

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
        std::vector<classifiable *> classifiedData = serverIO.importStringToVector(serverIO.importFileToString("../../../data/classified.csv"), NUM_PROPERTIES);
        tcpSocket tcp(clientSock, &serverIO, NUM_PROPERTIES, K, &classif, classifiedData);
        tcp.send("Connection was successful. Please choose your operation:");
        std::string message = tcp.receive();
        std::string newData = tcp.classify(message);
        tcp.send(newData);
        tcp.closeSocket();
    }
}