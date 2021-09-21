#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP
class tcpServer
{
private:
    //The socket number of the socket.
    int sock;

public:
    //The tcp port (42069).
    static const int TCP_PORT;

    //The queue size of the server accepting (5).
    static const int QUEUE_SIZE;

    //The constructor of the tcp server.
    tcpServer(int sock);

    //Binds the socket to the tcp port.
    void bind();

    //Listens to any clients that want to connect to the server.
    void listen();

    //Accepts the clients that want to cennect to the server.
    int accept();

    //Closes the socket.
    void closeSocket();
};
#endif