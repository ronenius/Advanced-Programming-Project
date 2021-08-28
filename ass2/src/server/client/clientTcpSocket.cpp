#include "clientTcpSocket.hpp"

const char *clientTcpSocket::TCP_IP_ADDRESS = "127.0.0.1";

clientTcpSocket::clientTcpSocket(int sock, stringIO *serverIO) : sock(sock), serverIO(serverIO){};

void clientTcpSocket::connectToServer()
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(TCP_IP_ADDRESS);
    sin.sin_port = htons(tcpServer::TCP_PORT);
    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error connecting to server");
    }
}

void clientTcpSocket::send(std::string message)
{
    int len = message.length();
    char messageArr[len + 1];
    strcpy(messageArr, message.c_str());
    int sent_bytes = ::send(sock, messageArr, len, 0);
    if (sent_bytes < 0)
    {
        perror("error sending to TCP server");
    }
}

std::string clientTcpSocket::receive()
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
        perror("error reading from TCP server");
    }
    return std::string(buffer);
}

void clientTcpSocket::closeSocket()
{
    close(sock);
}

std::string clientTcpSocket::fileToString(std::string path)
{
    return serverIO->importFileToString(path);
}

void clientTcpSocket::stringToFile(std::string path, std::string data)
{
    serverIO->exportStringToFile(path, data);
}