#include "udpSocket.hpp"
udpSocket::udpSocket(int sock, stringIO *serverIO, int numProperties, int k,
                     classifier *serverClassifier, std::vector<classifiable *> classifiedData)
    : sock(sock), classifyingServer(serverIO, numProperties, k, serverClassifier, classifiedData){};