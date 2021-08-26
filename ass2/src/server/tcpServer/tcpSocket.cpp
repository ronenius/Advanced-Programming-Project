#include "tcpSocket.hpp"
tcpSocket::tcpSocket(int sock, stringIO *serverIO, int numProperties, int k,
                     classifier *serverClassifier, std::vector<classifiable *> classifiedData)
    : sock(sock), classifyingServer(serverIO, numProperties, k, serverClassifier, classifiedData){};

void tcpSocket::send(std::string message)
{
    int len = message.length();
    char messageArr[len + 1];
    strcpy(messageArr, message.c_str());
    int sent_bytes = ::send(sock, messageArr, len, 0);
    if (sent_bytes < 0)
    {
        perror("error sending to client");
    }
}

std::string tcpSocket::receive()
{
    char buffer[BUFFER_SIZE];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0)
    {
        this->closeSocket();
    }
    else if (read_bytes < 0)
    {
        perror("error reading from client");
    }
    return std::string(buffer);
}

void tcpSocket::closeSocket()
{
    close(sock);
}