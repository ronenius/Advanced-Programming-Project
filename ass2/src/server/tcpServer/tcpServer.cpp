#include "tcpServer.hpp"

const int tcpServer::TCP_PORT = 42069;
const int tcpServer::QUEUE_SIZE = 5;

tcpServer::tcpServer(int sock) : sock(sock){};

void tcpServer::bind()
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(TCP_PORT);
    if (::bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
    }
}

void tcpServer::listen()
{
    if (::listen(sock, QUEUE_SIZE) < 0)
    {
        perror("error listening to a socket");
    }
}

int tcpServer::accept()
{
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = ::accept(sock, (struct sockaddr *)&client_sin, &addr_len);
    if (client_sock < 0)
    {
        perror("error accepting client");
    }
    return client_sock;
}

void tcpServer::closeSocket()
{
    close(sock);
}