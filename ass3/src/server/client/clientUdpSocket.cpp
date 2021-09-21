#include "clientUdpSocket.hpp"

//The ip address of the server (127.0.0.1)
const char *clientUdpSocket::UDP_IP_ADDRESS = "127.0.0.1";

//The constructor of the udp client.
clientUdpSocket::clientUdpSocket(int sock, stringIO *serverIO) : sock(sock), serverIO(serverIO)
{
    //Builds the sockaddr of the udp server.
    memset(&from, 0, sizeof(from));
    from.sin_family = AF_INET;
    from.sin_addr.s_addr = inet_addr(UDP_IP_ADDRESS);
    from.sin_port = htons(udpSocket::UDP_PORT);
}

//The function sends a string message from the client
//or the server to the other side, respectively.
void clientUdpSocket::send(std::string message)
{
    //Builds the char array from the string.
    int len = message.length();
    char messageArr[len + 1] = {0};
    strcpy(messageArr, message.c_str());
    //Sends the char array to the server.
    int sent_bytes = sendto(sock, messageArr, len, 0, (struct sockaddr *)&from, sizeof(from));
    if (sent_bytes < 0)
    {
        perror("error writing to UDP server");
    }
}

//The function receives a string message from the other side
//to the current side.
std::string clientUdpSocket::receive()
{
    //Creates the buffer that will get the message from the server.
    char buffer[BUFFER_SIZE] = {0};
    int expected_data_len = sizeof(buffer);
    unsigned int from_len = sizeof(struct sockaddr_in);
    //Receieves the message from the server.
    int read_bytes = recvfrom(sock, buffer, expected_data_len, 0, (struct sockaddr *)&from, &from_len);
    if (read_bytes < 0)
    {
        perror("error reading from UDP server");
    }
    //Returns the message.
    return std::string(buffer);
}

//Closes the socket.
void clientUdpSocket::closeSocket()
{
    close(sock);
}

//Copies a file in the given path to a string.
std::string clientUdpSocket::fileToString(std::string path)
{
    return serverIO->importFileToString(path);
}

//Copies a string to a file in the given path.
void clientUdpSocket::stringToFile(std::string path, std::string data)
{
    serverIO->exportStringToFile(path, data);
}