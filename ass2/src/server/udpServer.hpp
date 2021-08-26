#include "classifyingServer.hpp"
class udpServer : public classifyingServer
{
private:
    int sock;

public:
    udpServer(int sock, stringIO *serverIO, int numProperties, int k,
              classifier *serverClassifier, std::vector<classifiable *> classifiedData);
};