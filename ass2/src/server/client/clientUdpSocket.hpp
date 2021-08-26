#include "socketInterface.hpp"
class clientUdpSocket : public socketInterface
{
private:
    int sock;

public:
    clientUdpSocket(int sock);
    void send(std::string message);
    std::string receive();
    void closeSocket();
};