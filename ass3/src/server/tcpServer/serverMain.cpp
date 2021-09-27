#include "../../classifier/knnClassifier.hpp"
#include "../../cli/cli.hpp"
#include "../../io/socketIO.hpp"
#include "tcpServer.hpp"
#include "tcpSocket.hpp"
#include <thread>
#include <fcntl.h>

void run(int clientSock)
{
    tcpSocket tcp(clientSock);
    socketIO sio(&tcp);
    knnClassifier classif;
    CLI cli(&sio, &classif);
    cli.start();
    tcp.closeSocket();
}

int main()
{
    //Creates the tcp socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    int status = fcntl(sock, F_SETFL, fcntl(sock, F_GETFL, 0) | O_NONBLOCK);
    if (status < 0)
    {
        perror("error making non blocking socket");
    }
    //Creates the server object.
    tcpServer TCPServer(sock);
    //Binds the socket to the port.
    TCPServer.bind();
    //Runs the server forever.
    while (true)
    {
        //Listens for any clients that want to connect.
        TCPServer.listen();
        int clientSock = -1;
        //Accepts and gets the socket of the client.
        while (clientSock == -1)
        {
            clientSock = TCPServer.accept();
        }
        std::thread th(run, clientSock);
        th.detach();
    }
}