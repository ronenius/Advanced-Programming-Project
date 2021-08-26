#include "classifyingServer.hpp"
class udpSocket : public classifyingServer
{
private:
    int sock;

public:
    udpSocket(int sock, stringIO *serverIO, int numProperties, int k,
              classifier *serverClassifier, std::vector<classifiable *> classifiedData);
    int createSocket();
    void bind();
    void send(std::string message);
    std::string receive();
    void closeSocket();
};