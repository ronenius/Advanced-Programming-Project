#include "tcpSocket.hpp"

//The constructor of the tcp socket.
tcpSocket::tcpSocket(int sock, stringIO *serverIO, int numProperties, int k,
                     classifier *serverClassifier, std::vector<classifiable *> classifiedData)
    : sock(sock), classifyingServer(serverIO, numProperties, k, serverClassifier, classifiedData){};

//The function sends a string message from the client
//or the server to the other side, respectively.
void tcpSocket::send(std::string message)
{
    //Builds the char array from the string.
    int len = message.length();
    char messageArr[len + 1] = {0};
    strcpy(messageArr, message.c_str());
    //Sends the char array to the client.
    int sent_bytes = ::send(sock, messageArr, len, 0);
    if (sent_bytes < 0)
    {
        perror("error sending to client");
    }
}

//The function receives a string message from the other side
//to the current side.
std::string tcpSocket::receive()
{
    //Creates the buffer that will get the message from the client.
    char buffer[BUFFER_SIZE] = {0};
    int expected_data_len = sizeof(buffer);
    //Receieves the message from the client.
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes < 0)
    {
        perror("error reading from client");
    }
    //Returns the message.
    return std::string(buffer);
}

//Closes the socket.
void tcpSocket::closeSocket()
{
    close(sock);
}