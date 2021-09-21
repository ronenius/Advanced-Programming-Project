#include "../socketInterface.hpp"
#include "../tcpServer/tcpServer.hpp"
#include "../../classifier/stringIO.hpp"
#ifndef CLIENT_TCP_SOCKET
#define CLIENT_TCP_SOCKET
class clientTcpSocket : public socketInterface
{
private:
    //The socket number of the socket.
    int sock;

    //The IO that converts files into strings and backwards.
    stringIO *serverIO;

public:
    //The ip address of the server (127.0.0.1)
    static const char *TCP_IP_ADDRESS;

    //The constructor of the tcp client.
    clientTcpSocket(int sock, stringIO *serverIO);

    //Tries to connect to the tcp server.
    void connectToServer();

    //The function sends a string message from the client
    //or the server to the other side, respectively.
    void send(std::string message);

    //The function receives a string message from the other side
    //to the current side.
    std::string receive();

    //Closes the socket.
    void closeSocket();

    //Copies a file in the given path to a string.
    std::string fileToString(std::string path);

    //Copies a string to a file in the given path.
    void stringToFile(std::string path, std::string data);
};
#endif