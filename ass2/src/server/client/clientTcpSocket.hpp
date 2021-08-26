#include "socketInterface.hpp"
#include "stringIO.hpp"
class clientTcpSocket : public socketInterface
{
private:
    int sock;
    stringIO *serverIO;

public:
    clientTcpSocket(int sock, stringIO *serverIO);
    void send(std::string message);
    std::string receive();
    void closeSocket();
};