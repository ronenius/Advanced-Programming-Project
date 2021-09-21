#include "clientUdpSocket.hpp"
#include "clientTcpSocket.hpp"
#include "../../classifier/irisBuilder.hpp"

//Builds the client side and runs it.
int main()
{
    //Creates the tcp client socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    //Creates the IO of the client.
    irisBuilder builder;
    stringIO serverIO(&builder);
    //Builds the tcp client object.
    clientTcpSocket TCPClient(sock, &serverIO);
    //Tries to connect to the tcp server.
    TCPClient.connectToServer();
    //Creates the udp client socket.
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    //Builds the udp client object.
    clientUdpSocket UDPClient(sock, &serverIO);
    //Receives the connection confirmation message from the tcp server.
    std::string message = TCPClient.receive();
    std::cout << message << std::endl;
    //Gets the user input on what does he want to classify and what protocol to use.
    std::string protocol, unclassifiedPath, outputPath;
    std::cin >> protocol >> unclassifiedPath >> outputPath;
    //If the chosen protocol is tcp.
    if (protocol.compare("TCP") == 0)
    {
        //Converts the unclassified file into a string.
        std::string data = TCPClient.fileToString(unclassifiedPath);
        //Sends the string to the tcp server.
        TCPClient.send(data);
        //Receives the classified message from the server.
        std::string newData = TCPClient.receive();
        //Exports the string message to a file in the output path.
        TCPClient.stringToFile(outputPath + "/output.csv", newData);
    }
    //Else if the chosen protocol is udp.
    else if (protocol.compare("UDP") == 0)
    {
        //Converts the unclassified file into a string.
        std::string data = UDPClient.fileToString(unclassifiedPath);
        //Sends the string to the udp server.
        UDPClient.send(data);
        //Sends the tcp server an empty string so that the tcp won't get stuck.
        TCPClient.send("");
        //Receives the classified message from the server.
        std::string newData = UDPClient.receive();
        //Exports the string message to a file in the output path.
        UDPClient.stringToFile(outputPath + "/output.csv", newData);
    }
    //Closes both of the clients.
    TCPClient.closeSocket();
    UDPClient.closeSocket();
    return 0;
}