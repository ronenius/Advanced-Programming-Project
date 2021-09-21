#include "tcpSocket.hpp"
#include "tcpServer.hpp"
#include "../../classifier/irisBuilder.hpp"
#include "../../classifier/knnClassifier.hpp"

//The number of properties in an iris is 4.
#define NUM_PROPERTIES 4

// The KNN classifier works with K=5.
#define K 5

//Builds the tcp classifying server and runs it forever.
int main()
{
    //Creates the tcp socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    //Creates the server object.
    tcpServer TCPServer(sock);
    //Binds the socket to the port.
    TCPServer.bind();
    //Runs the server forever.
    while (true)
    {
        //Listens for any clients that want to connect.
        TCPServer.listen();
        //Accepts and gets the socket of the client.
        int clientSock = TCPServer.accept();
        //Creates the IO of the server.
        irisBuilder builder;
        stringIO serverIO(&builder);
        //Creates the knn classifier of the server.
        knnClassifier classif;
        //Imports the classified file to a vector of classifiables.
        std::vector<classifiable *> classifiedData = serverIO.importStringToVector(
            serverIO.importFileToString("data/classified.csv"), NUM_PROPERTIES);
        //Creates the server object.
        tcpSocket tcp(clientSock, &serverIO, NUM_PROPERTIES, K, &classif, classifiedData);
        //Sends a message that the connection was successful to the client.
        tcp.send("Connection was successful. Please choose what to classify:");
        //Receives a message from the client.
        std::string message = tcp.receive();
        //If the client sent a message to UDP then it
        //sends an empty message to the tcp and the tcp closes.
        if (message.length() == 0)
        {
            //Closes the server.
            tcp.closeSocket();
        }
        else
        {
            //Classifies the message.
            std::string newData = tcp.classify(message);
            //Sends the classified string back to the client.
            tcp.send(newData);
            //Closes the server.
            tcp.closeSocket();
        }
    }
    return 0;
}