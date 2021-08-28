#include "udpSocket.hpp"
#include "../../classifier/irisBuilder.hpp"
#include "../../classifier/knnClassifier.hpp"

//The number of properties in an iris is 4.
#define NUM_PROPERTIES 4

// The KNN classifier works with K=5.
#define K 5

//Builds the udp classifying server and runs it forever.
int main()
{
    //Creates the udp socket.
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    //Creates the IO of the server.
    irisBuilder builder;
    stringIO serverIO(&builder);
    //Creates the knn classifier of the server.
    knnClassifier classif;
    //Imports the classified file to a vector of classifiables.
    std::vector<classifiable *> classifiedData = serverIO.importStringToVector(
        serverIO.importFileToString(
            "/home/ronenius/proj/Advanced-Programming-Project/ass2/data/classified.csv"),
        NUM_PROPERTIES);
    //Creates the server object.
    udpSocket udpServer(sock, &serverIO, NUM_PROPERTIES, K, &classif, classifiedData);
    //Binds the socket to the port.
    udpServer.bind();
    //Runs always.
    while (true)
    {
        //Receives message from a client.
        std::string message = udpServer.receive();
        //Classifies the message.
        std::string newData = udpServer.classify(message);
        //Sends the classified string back to the client.
        udpServer.send(newData);
    }
    //Closes the socket.
    udpServer.closeSocket();
    return 0;
}