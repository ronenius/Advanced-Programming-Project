#include "clientUdpSocket.hpp"

const char *clientUdpSocket::UDP_IP_ADDRESS = "127.0.0.1";

clientUdpSocket::clientUdpSocket(int sock, stringIO *serverIO) : sock(sock), serverIO(serverIO)
{
    memset(&from, 0, sizeof(from));
    from.sin_family = AF_INET;
    from.sin_addr.s_addr = inet_addr(UDP_IP_ADDRESS);
    from.sin_port = htons(udpSocket::UDP_PORT);
}

void clientUdpSocket::send(std::string message)
{
    int len = message.length();
    char messageArr[len + 1];
    strcpy(messageArr, message.c_str());
    int sent_bytes = sendto(sock, messageArr, len, 0, (struct sockaddr *)&from, sizeof(from));
    if (sent_bytes < 0)
    {
        perror("error writing to UDP server");
    }
}

std::string clientUdpSocket::receive()
{
    char buffer[BUFFER_SIZE];
    int expected_data_len = sizeof(buffer);
    unsigned int from_len = sizeof(struct sockaddr_in);
    int read_bytes = recvfrom(sock, buffer, expected_data_len, 0, (struct sockaddr *)&from, &from_len);
    if (read_bytes < 0)
    {
        perror("error reading from UDP server");
    }
    return std::string(buffer);
}

void clientUdpSocket::closeSocket()
{
    close(sock);
}

std::string clientUdpSocket::fileToString(std::string path)
{
    return serverIO->importFileToString(path);
}

void clientUdpSocket::stringToFile(std::string path, std::string data)
{
    serverIO->exportStringToFile(path, data);
}