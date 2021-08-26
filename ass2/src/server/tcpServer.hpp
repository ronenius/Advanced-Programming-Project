#include "classifyingServer.hpp"
class tcpServer : public classifyingServer
{
private:
    int sock;

public:
    tcpServer(int sock, stringIO *serverIO, int numProperties, int k,
              classifier *serverClassifier, std::vector<classifiable *> classifiedData);
};