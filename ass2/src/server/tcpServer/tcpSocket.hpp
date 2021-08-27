#include "classifyingServer.hpp"
#ifndef TCP_SOCKET_HPP
#define TCP_SOCKET_HPP
class tcpSocket : public classifyingServer
{
private:
    int sock;

public:
    tcpSocket(int sock, stringIO *serverIO, int numProperties, int k,
              classifier *serverClassifier, std::vector<classifiable *> classifiedData);
    void send(std::string message);
    std::string receive();
    void closeSocket();
};
#endif