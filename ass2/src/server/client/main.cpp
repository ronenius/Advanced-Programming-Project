#include "clientUdpSocket.hpp"
#include "clientTcpSocket.hpp"
#include "../../classifier/irisBuilder.hpp"

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    irisBuilder builder;
    stringIO serverIO(&builder);
    clientTcpSocket TCPClient(sock, &serverIO);
    TCPClient.connectToServer();
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    clientUdpSocket UDPClient(sock, &serverIO);
    UDPClient.send("hello");
    std::string message = TCPClient.receive();
    std::cout << message << std::endl;
    std::string protocol, unclassifiedPath, outputPath;
    std::cin >> protocol >> unclassifiedPath >> outputPath;
    if (protocol.compare("TCP") == 0)
    {
        std::string data = TCPClient.fileToString(unclassifiedPath);
        TCPClient.send(data);
        std::string newData = TCPClient.receive();
        TCPClient.stringToFile(outputPath, newData);
    }
    else if (protocol.compare("UDP") == 0)
    {
        std::string data = UDPClient.fileToString(unclassifiedPath);
        UDPClient.send(data);
        std::string newData = UDPClient.receive();
        UDPClient.stringToFile(outputPath, newData);
    }
    TCPClient.closeSocket();
    UDPClient.closeSocket();
    return 0;
}