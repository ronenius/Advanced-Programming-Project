#include "udpSocket.hpp"

//The udp port (6969).
const int udpSocket::UDP_PORT = 6969;

//The constructor of the udp server.
udpSocket::udpSocket(int sock, stringIO *serverIO, int numProperties, int k,
                     classifier *serverClassifier, std::vector<classifiable *> classifiedData)
    : sock(sock), classifyingServer(serverIO, numProperties, k, serverClassifier, classifiedData){};

//Binds the socket to the udp port.
void udpSocket::bind()
{
    //Builds the sockaddr to get messages from all sockets.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(UDP_PORT);
    //Binds the tcp server in the port that was decided.
    if (::bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding to socket");
    }
}

//The function sends a string message from the client
//or the server to the other side, respectively.
void udpSocket::send(std::string message)
{
    //Builds the char array from the string.
    int len = message.length();
    char messageArr[len + 1] = {0};
    strcpy(messageArr, message.c_str());
    //Sends the char array to the client.
    int sent_bytes = sendto(sock, messageArr, len, 0, (struct sockaddr *)&from, sizeof(from));
    if (sent_bytes < 0)
    {
        perror("error writing to client");
    }
}

//The function receives a string message from the other side
//to the current side.
std::string udpSocket::receive()
{
    //Creates the buffer that will get the message from the client.
    char buffer[BUFFER_SIZE] = {0};
    int expected_data_len = sizeof(buffer);
    unsigned int from_len = sizeof(struct sockaddr_in);
    //Receieves the message from the client.
    int read_bytes = recvfrom(sock, buffer, expected_data_len, 0, (struct sockaddr *)&from, &from_len);
    if (read_bytes < 0)
    {
        perror("error reading from client");
    }
    //Returns the message.
    return std::string(buffer);
}

//Closes the socket.
void udpSocket::closeSocket()
{
    close(sock);
}