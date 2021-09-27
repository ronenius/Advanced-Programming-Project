#include "../../classifier/knnClassifier.hpp"
#include "../../cli/cli.hpp"
#include "../../io/socketIO.hpp"
#include "tcpServer.hpp"
#include "tcpSocket.hpp"
#include <thread>
#include <chrono>
#include <fcntl.h>
#define TIMEOUT_MILLISECONDS 60000

void run(int clientSock, int *threadCounter)
{
    (*threadCounter)++;
    tcpSocket tcp(clientSock);
    socketIO sio(&tcp);
    knnClassifier classif;
    CLI cli(&sio, &classif);
    cli.start();
    tcp.closeSocket();
    (*threadCounter)--;
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
    auto start = std::chrono::high_resolution_clock::now();
    int threadCounter = 0, milliseconds = 0;
    //Runs the server forever.
    while (milliseconds <= TIMEOUT_MILLISECONDS)
    {
        //Listens for any clients that want to connect.
        TCPServer.listen();
        //Accepts and gets the socket of the client.
        int clientSock = TCPServer.accept();
        if (clientSock != -1)
        {
            start = std::chrono::high_resolution_clock::now();
            std::thread th(run, clientSock, &threadCounter);
            th.detach();
        }
        auto now = std::chrono::high_resolution_clock::now();
        auto time = now - start;
        milliseconds = time / std::chrono::milliseconds(1);
    }
    while (threadCounter != 0)
        ;
    TCPServer.closeSocket();
    std::cout << "closed successfully" << std::endl;
}