#include "udpSocket.hpp"
const int udpSocket::UDP_PORT = 6969;
udpSocket::udpSocket(int sock, stringIO *serverIO, int numProperties, int k,
                     classifier *serverClassifier, std::vector<classifiable *> classifiedData)
    : sock(sock), classifyingServer(serverIO, numProperties, k, serverClassifier, classifiedData){};

void udpSocket::bind()
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(UDP_PORT);
    if (::bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding to socket");
    }
}

void udpSocket::send(std::string message)
{
    int len = message.length();
    char messageArr[len + 1];
    strcpy(messageArr, message.c_str());
    int sent_bytes = sendto(sock, messageArr, len, 0, (struct sockaddr *)&from, sizeof(from));
    if (sent_bytes < 0)
    {
        perror("error writing to client");
    }
}

std::string udpSocket::receive()
{
    char buffer[BUFFER_SIZE];
    int expected_data_len = sizeof(buffer);
    unsigned int from_len = sizeof(struct sockaddr_in);
    int read_bytes = recvfrom(sock, buffer, expected_data_len, 0, (struct sockaddr *)&from, &from_len);
    if (read_bytes < 0)
    {
        perror("error reading from client");
    }
    return std::string(buffer);
}

void udpSocket::closeSocket()
{
    close(sock);
}