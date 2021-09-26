#include "../../classifier/knnClassifier.hpp"
#include "../../cli/cli.hpp"
#include "../../io/socketIO.hpp"
#include "tcpServer.hpp"
#include "tcpSocket.hpp"
#include <thread>

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
    //Creates the server object.
    tcpServer TCPServer(sock);
    //Binds the socket to the port.
    TCPServer.bind();
    //Runs the server forever.
    while (true)
    {
        //Listens for any clients that want to connect.
        TCPServer.listen();
        //Accepts and gets the socket of the client.
        int clientSock = TCPServer.accept();
        std::thread th(run, clientSock);
        th.detach();
    }
}