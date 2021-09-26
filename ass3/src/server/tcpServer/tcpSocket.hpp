#include "../socketInterface.hpp"
#ifndef TCP_SOCKET_HPP
#define TCP_SOCKET_HPP
class tcpSocket : public socketInterface
{
private:
    //The socket number of the socket.
    int sock;

public:
    //The constructor of the tcp socket.
    tcpSocket(int sock);

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