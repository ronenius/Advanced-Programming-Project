#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class tcpServer
{
private:
    int sock;

public:
    static const int TCP_PORT;
    static const int QUEUE_SIZE;

    tcpServer(int sock);
    void bind();
    void listen();
    int accept();
    void closeSocket();
};