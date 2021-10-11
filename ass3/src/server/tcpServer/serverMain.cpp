#include "../../classifier/knnClassifier.hpp"
#include "../../cli/cli.hpp"
#include "../../io/socketIO.hpp"
#include "tcpServer.hpp"
#include "tcpSocket.hpp"
#include <thread>
#include <chrono>
#include <fcntl.h>
#define TIMEOUT_MILLISECONDS 60000

//The function runs the cli of the project until the user closes it.
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

//The main runs the multithreaded server where each connection runs the cli to the client.
int main()
{
    //Creates the tcp socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    //Makes the server non blocking mode.
    int status = fcntl(sock, F_SETFL, fcntl(sock, F_GETFL, 0) | O_NONBLOCK);
    if (status < 0)
    {
        perror("error making non blocking socket");
    }
    //Creates the server object.
    tcpServer TCPServer(sock);
    //Binds the socket to the port.
    TCPServer.bind();
    //Gets the time right now.
    auto start = std::chrono::high_resolution_clock::now();
    int threadCounter = 0, milliseconds = 0;
    //Runs the server till timeout reached.
    while (milliseconds <= TIMEOUT_MILLISECONDS)
    {
        //Listens for any clients that want to connect.
        TCPServer.listen();
        //Accepts and gets the socket of the client.
        int clientSock = TCPServer.accept();
        //If the tcp accepted a valid client.
        if (clientSock != -1)
        {
            //Resets the timer.
            start = std::chrono::high_resolution_clock::now();
            //Creates a thread that runs the cli.
            std::thread th(run, clientSock, &threadCounter);
            //Detaches the thread from the scope.
            th.detach();
        }
        //Gets the current time.
        auto now = std::chrono::high_resolution_clock::now();
        //Calculates the timer.
        auto time = now - start;
        milliseconds = time / std::chrono::milliseconds(1);
    }
    //After the timeout the server waits until all of the clients finished to work.
    while (threadCounter != 0)
        ;
    //Closes the server.
    TCPServer.closeSocket();
    std::cout << "closed successfully" << std::endl;
}