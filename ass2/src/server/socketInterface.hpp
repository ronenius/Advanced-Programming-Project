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
    static constexpr char const IP_ADDRESS[] = {'1', '2', '7', '.', '0', '.', '0', '.', '1'};
    static const int BUFFER_SIZE = 4096;
    virtual void send(std::string massage) = 0;
    virtual std::string receive() = 0;
    virtual void closeSocket();
};