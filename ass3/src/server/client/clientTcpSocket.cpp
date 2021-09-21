#include "clientTcpSocket.hpp"

//The ip address of the server (127.0.0.1)
const char *clientTcpSocket::TCP_IP_ADDRESS = "127.0.0.1";

//The constructor of the tcp client.
clientTcpSocket::clientTcpSocket(int sock, stringIO *serverIO) : sock(sock), serverIO(serverIO){};

//Tries to connect to the tcp server.
void clientTcpSocket::connectToServer()
{
    //Builds the sockaddr of the tcp server.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(TCP_IP_ADDRESS);
    sin.sin_port = htons(tcpServer::TCP_PORT);
    //Connects to the tcp server.
    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error connecting to server");
    }
}

//The function sends a string message from the client
//or the server to the other side, respectively.
void clientTcpSocket::send(std::string message)
{
    //Builds the char array from the string.
    int len = message.length();
    char messageArr[len + 1] = {0};
    strcpy(messageArr, message.c_str());
    //Sends the char array to the server.
    int sent_bytes = ::send(sock, messageArr, len, 0);
    if (sent_bytes < 0)
    {
        perror("error sending to TCP server");
    }
}

//The function receives a string message from the other side
//to the current side.
std::string clientTcpSocket::receive()
{
    //Creates the buffer that will get the message from the server.
    char buffer[BUFFER_SIZE] = {0};
    int expected_data_len = sizeof(buffer);
    //Receieves the message from the server.
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    //If there is no message then closes the client socket.
    if (read_bytes == 0)
    {
        this->closeSocket();
    }
    else if (read_bytes < 0)
    {
        perror("error reading from TCP server");
    }
    //Returns the message.
    return std::string(buffer);
}

//Closes the socket.
void clientTcpSocket::closeSocket()
{
    close(sock);
}

//Copies a file in the given path to a string.
std::string clientTcpSocket::fileToString(std::string path)
{
    return serverIO->importFileToString(path);
}

//Copies a string to a file in the given path.
void clientTcpSocket::stringToFile(std::string path, std::string data)
{
    serverIO->exportStringToFile(path, data);
}