#include "classifyingServer.hpp"
class udpSocket : public classifyingServer
{
private:
    int sock;
    struct sockaddr_in from;

public:
    static const int UDP_PORT;

    udpSocket(int sock, stringIO *serverIO, int numProperties, int k,
              classifier *serverClassifier, std::vector<classifiable *> classifiedData);
    void bind();
    void send(std::string message);
    std::string receive();
    void closeSocket();
};