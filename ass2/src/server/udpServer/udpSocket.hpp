#include "../classifyingServer.hpp"
#ifndef UDP_SOCKET_HPP
#define UDP_SOCKET_HPP
class udpSocket : public classifyingServer
{
private:
    //The socket number of the socket.
    int sock;

    //The sockaddr of the client that the udp server is connected to.
    struct sockaddr_in from;

public:
    //The udp port (6969).
    static const int UDP_PORT;

    //The constructor of the udp server.
    udpSocket(int sock, stringIO *serverIO, int numProperties, int k,
              classifier *serverClassifier, std::vector<classifiable *> classifiedData);

    //Binds the socket to the udp port.
    void bind();

    //The function sends a string message from the client
    //or the server to the other side, respectively.
    void send(std::string message);

    //The function receives a string message from the other side
    //to the current side.
    std::string receive();

    //Closes the socket.
    void closeSocket();
};
#endif