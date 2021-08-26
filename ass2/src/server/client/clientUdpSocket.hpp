#include "socketInterface.hpp"
#include "stringIO.hpp"
class clientUdpSocket : public socketInterface
{
private:
    int sock;
    stringIO *serverIO;

public:
    clientUdpSocket(int sock, stringIO *serverIO);
    void send(std::string message);
    std::string receive();
    void closeSocket();
};