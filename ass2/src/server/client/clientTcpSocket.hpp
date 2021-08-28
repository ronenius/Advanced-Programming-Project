#include "../socketInterface.hpp"
#include "../tcpServer/tcpServer.hpp"
#include "../../classifier/stringIO.hpp"
#ifndef CLIENT_TCP_SOCKET
#define CLIENT_TCP_SOCKET
class clientTcpSocket : public socketInterface
{
private:
    int sock;
    stringIO *serverIO;

public:
    static const char *TCP_IP_ADDRESS;
    clientTcpSocket(int sock, stringIO *serverIO);
    void connectToServer();
    void send(std::string message);
    std::string receive();
    void closeSocket();
    std::string fileToString(std::string path);
    void stringToFile(std::string path, std::string data);
};
#endif