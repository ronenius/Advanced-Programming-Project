#include "../../classifier/knnClassifier.hpp"
#include "../../cli/cli.hpp"
#include "../../io/socketIO.hpp"
#include "tcpServer.hpp"
#include "tcpSocket.hpp"
#include <thread>
#include <chrono>
#include <fcntl.h>
#define TIMEOUT_MILLISECONDS 30000

void run(int clientSock, int& threadsCounter)
{
    threadsCounter++;
    tcpSocket tcp(clientSock);
    socketIO sio(&tcp);
    knnClassifier classif;
    CLI cli(&sio, &classif);
    cli.start();
    tcp.closeSocket();
    threadsCounter--;
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
    int threadsCounter = 0;
    //Runs the server forever.
    auto start = chrono::high_resolution_clock::now();
    int milliseconds = 0;
    while (milliseconds < )
    {
        //Listens for any clients that want to connect.
        TCPServer.listen();
        int clientSock = -1;
        //Accepts and gets the socket of the client.
        int clientSock = TCPServer.accept();
        if (clientSock != -1) {
            start = chorno::high_resolution_clock::now();
            std::thread th(run, clientSock, threadsCounter);
            th.detach();
        }
        auto now = chrono::high_resolution_clock::now();
        auto time = now - start;
        milliseconds = time / chrono::milliseconds(1);
    }
}