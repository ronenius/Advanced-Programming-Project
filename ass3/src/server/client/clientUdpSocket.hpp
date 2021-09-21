#include "../socketInterface.hpp"
#include "../udpServer/udpSocket.hpp"
#include "../../classifier/stringIO.hpp"
#ifndef CLIENT_UDP_SOCKET
#define CLIENT_UDP_SOCKET
class clientUdpSocket : public socketInterface
{
private:
    //The socket number of the socket.
    int sock;

    //The IO that converts files into strings and backwards.
    stringIO *serverIO;

    //The sockaddr of the udp server that the client connected to.
    struct sockaddr_in from;

public:
    //The ip address of the server (127.0.0.1)
    static const char *UDP_IP_ADDRESS;

    //The constructor of the udp client.
    clientUdpSocket(int sock, stringIO *serverIO);

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