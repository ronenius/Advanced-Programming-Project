#include "socketInterface.hpp"
class clientTcpSocket : public socketInterface
{
private:
    int sock;

public:
    clientTcpSocket(int sock);
    void send(std::string message);
    std::string receive();
    void closeSocket();
};