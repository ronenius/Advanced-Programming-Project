#include "tcpSocket.hpp"
#include "tcpServer.hpp"
int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    tcpServer TCPServer(sock);
    TCPServer.bind();
    TCPServer.listen();
    int clientSock = TCPServer.accept();
    tcpSocket 
}