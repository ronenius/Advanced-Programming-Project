#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#ifndef SOCKET_INTERFACE
#define SOCKET_INTERFACE
class socketInterface
{
public:
    static const int BUFFER_SIZE = 4096;
    virtual void send(std::string massage) = 0;
    virtual std::string receive() = 0;
    virtual void closeSocket() = 0;
};
#endif