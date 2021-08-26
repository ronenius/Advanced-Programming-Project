#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
class socketInterface
{
public:
    virtual void send(std::string massage) = 0;
    virtual std::string receive() = 0;
    virtual void closeSocket();
};