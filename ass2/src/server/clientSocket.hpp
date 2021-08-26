#include "socketInterface.hpp"
class clientSocket : public socketInterface
{
private:
    int sock;

public:
    int createSocket();
    void send(std::string message);
    std::string receive();
    void closeSocket();
};