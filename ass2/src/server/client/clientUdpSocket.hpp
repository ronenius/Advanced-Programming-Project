#include "../socketInterface.hpp"
#include "../udpServer/udpSocket.hpp"
#include "../../classifier/stringIO.hpp"
#ifndef CLIENT_UDP_SOCKET
#define CLIENT_UDP_SOCKET
class clientUdpSocket : public socketInterface
{
private:
    int sock;
    stringIO *serverIO;
    struct sockaddr_in from;

public:
    static const char *UDP_IP_ADDRESS;
    clientUdpSocket(int sock, stringIO *serverIO);
    void send(std::string message);
    std::string receive();
    void closeSocket();
    std::string fileToString(std::string path);
    void stringToFile(std::string path, std::string data);
};
#endif