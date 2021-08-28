#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#ifndef SOCKET_INTERFACE
#define SOCKET_INTERFACE
//An interface for a general socket (tcp, udp or client).
class socketInterface
{
public:
    //The max size for a sent message is 4096.
    static const int BUFFER_SIZE = 4096;

    //The function sends a string message from the client
    //or the server to the other side, respectively.
    virtual void send(std::string massage) = 0;

    //The function receives a string message from the other side
    //to the current side.
    virtual std::string receive() = 0;

    //Closes the socket.
    virtual void closeSocket() = 0;
};
#endif