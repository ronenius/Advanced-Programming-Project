#include "socketInterface.hpp"
#include "udpSocket.hpp"
#include "stringIO.hpp"
#ifndef CLIENT_UDP_SOCKET
#define CLIENT_UDP_SOCKET
class clientUdpSocket : public socketInterface
{
private:
    int sock;
    stringIO *serverIO;
    struct sockaddr_in from;

public:
    clientUdpSocket(int sock, stringIO *serverIO);
    void send(std::string message);
    std::string receive();
    void closeSocket();
    std::string fileToString(std::string path);
    void stringToFile(std::string path, std::string data);
};
#endif