#include "tcpServer.hpp"

//The tcp port (42069).
const int tcpServer::TCP_PORT = 42069;

//The queue size of the server accepting (5).
const int tcpServer::QUEUE_SIZE = 5;

//The constructor of the tcp server.
tcpServer::tcpServer(int sock) : sock(sock){};

//Binds the socket to the tcp port.
void tcpServer::bind()
{
    //Builds the sockaddr to get messages from all sockets.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(TCP_PORT);
    //Binds the tcp server in the port that was decided.
    if (::bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
    }
}

//Listens to any clients that want to connect to the server.
void tcpServer::listen()
{
    //Listens to all of the clients.
    if (::listen(sock, QUEUE_SIZE) < 0)
    {
        perror("error listening to a socket");
    }
}

//Accepts the clients that want to cennect to the server.
int tcpServer::accept()
{
    //Builds the sockaddr of the client.
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    //Gets the sockaddr and the socket number of the client socket.
    int client_sock = ::accept(sock, (struct sockaddr *)&client_sin, &addr_len);
    //Returns the socket number for future use.
    return client_sock;
}

//Closes the socket.
void tcpServer::closeSocket()
{
    close(sock);
}