#include "socketInterface.hpp"
#include "tcpServer.hpp"
#include "stringIO.hpp"
class clientTcpSocket : public socketInterface
{
private:
    int sock;
    stringIO *serverIO;

public:
    clientTcpSocket(int sock, stringIO *serverIO);
    void connectToServer();
    void send(std::string message);
    std::string receive();
    void closeSocket();
    std::string fileToString(std::string path);
    void stringToFile(std::string path, std::string data);
};